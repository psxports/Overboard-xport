#include "psx.h"
#include "native_services.h"
#include "native_runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Project host adapter for the original PsyQ formatter, not a BIOS thunk */
static __declspec(noreturn) void format_failure(const char *reason, uint32 count)
{
    fprintf(stderr, "Overboard sprintf 80064028: %s\n", reason);
    ob_native_missing(0x80064028u, 0xFFFFFFFEu, count);
}

static uint32 format_argument(uint32 count, const uint32 *args, uint32 *index)
{
    if (*index >= count)
        ob_native_missing(0x80064028u, *index + 1u, count);
    return args[(*index)++];
}

static sint32 format_number(uint32 *cursor, uint32 count)
{
    uint32 number = 0u;
    uint32 character = r_u8(*cursor);
    while (character >= '0' && character <= '9')
    {
        uint32 digit = character - '0';
        if (number > ((uint32)INT_MAX - digit) / 10u)
            format_failure("Format width or precision exceeds host integer range", count);
        number = number * 10u + digit;
        ++*cursor;
        character = r_u8(*cursor);
    }
    return (sint32)number;
}

static char *format_guest_string(uint32 address, sint32 precision, uint32 count)
{
    uint32 length = 0u;
    while (precision < 0 || length < (uint32)precision)
    {
        if (r_u8(address + length) == 0u) break;
        if (length == (uint32)INT_MAX)
            format_failure("Guest string exceeds host integer range", count);
        ++length;
    }
    char *string = (char *)malloc((size_t)length + 1u);
    if (string == NULL) format_failure("Host string allocation failed", count);
    for (uint32 index = 0u; index < length; ++index)
        string[index] = (char)r_u8(address + index);
    string[length] = '\0';
    return string;
}

uint32 ob_native_sprintf(uint32 count, const uint32 *args)
{
    if (count < 2u) ob_native_missing(0x80064028u, 2u, count);
    uint32 destination = args[0];
    uint32 cursor = args[1];
    uint32 argument = 2u;
    uint32 written = 0u;
    while (r_u8(cursor) != 0u)
    {
        uint32 character = r_u8(cursor++);
        if (character != '%')
        {
            w_u8(destination + written++, character);
            continue;
        }
        sint32 left = 0, plus = 0, space = 0, alternate = 0, zero = 0;
        for (;;)
        {
            character = r_u8(cursor);
            if (character == '-') left = 1;
            else if (character == '+') plus = 1;
            else if (character == ' ') space = 1;
            else if (character == '#') alternate = 1;
            else if (character == '0') zero = 1;
            else break;
            ++cursor;
        }
        sint32 width;
        if (r_u8(cursor) == '*')
        {
            ++cursor;
            width = (sint32)format_argument(count, args, &argument);
            if (width == INT_MIN) format_failure("INT_MIN dynamic width is unsupported", count);
            if (width < 0) { left = 1; width = -width; }
        }
        else width = format_number(&cursor, count);
        sint32 precision = -1;
        if (r_u8(cursor) == '.')
        {
            ++cursor;
            if (r_u8(cursor) == '*')
            {
                ++cursor;
                precision = (sint32)format_argument(count, args, &argument);
            }
            else precision = format_number(&cursor, count);
        }
        sint32 short_value = 0;
        if (r_u8(cursor) == 'h') { short_value = 1; ++cursor; }
        else if (r_u8(cursor) == 'l') ++cursor;
        character = r_u8(cursor++);
        if (character == '%')
        {
            w_u8(destination + written++, '%');
            continue;
        }
        if (character != 'd' && character != 'i' && character != 'u' &&
            character != 'o' && character != 'x' && character != 'X' &&
            character != 'c' && character != 's' && character != 'p' && character != 'n')
            format_failure("Unsupported conversion or length modifier", count);
        uint32 value = format_argument(count, args, &argument);
        if (character == 'n')
        {
            if (short_value) w_u16(value, written);
            else w_u32(value, written);
            continue;
        }
        if ((character == 's' || character == 'c' || character == 'p') && short_value)
            format_failure("Unsupported short string, character or pointer conversion", count);
        if ((character == 's' || character == 'c' || character == 'p') && alternate)
            format_failure("Unsupported PsyQ alternate string, character or pointer conversion", count);
        if (character == 'p')
        {
            character = 'X';
            precision = 8;
        }
        char specification[64];
        uint32 size = 0u;
        specification[size++] = '%';
        if (left) specification[size++] = '-';
        if (plus) specification[size++] = '+';
        if (space) specification[size++] = ' ';
        if (alternate) specification[size++] = '#';
        if (zero) specification[size++] = '0';
        if (width != 0)
            size += (uint32)snprintf(specification + size, sizeof(specification) - size, "%d", (int)width);
        if (precision >= 0)
            size += (uint32)snprintf(specification + size, sizeof(specification) - size, ".%d", (int)precision);
        specification[size++] = (char)character;
        specification[size] = '\0';
        char *string = NULL;
        if (character == 's') string = format_guest_string(value, precision, count);
        sint32 signed_value = short_value ? (sint16)value : (sint32)value;
        uint32 unsigned_value = short_value ? (uint16)value : value;
        int length;
        if (character == 's') length = snprintf(NULL, 0u, specification, string);
        else if (character == 'c') length = snprintf(NULL, 0u, specification, (int)(uint8)value);
        else if (character == 'd' || character == 'i') length = snprintf(NULL, 0u, specification, (int)signed_value);
        else length = snprintf(NULL, 0u, specification, (unsigned int)unsigned_value);
        if (length < 0) format_failure("Host formatter rejected conversion", count);
        char *output = (char *)malloc((size_t)length + 1u);
        if (output == NULL) format_failure("Host format allocation failed", count);
        if (character == 's') snprintf(output, (size_t)length + 1u, specification, string);
        else if (character == 'c') snprintf(output, (size_t)length + 1u, specification, (int)(uint8)value);
        else if (character == 'd' || character == 'i') snprintf(output, (size_t)length + 1u, specification, (int)signed_value);
        else snprintf(output, (size_t)length + 1u, specification, (unsigned int)unsigned_value);
        if ((uint32)length > (uint32)INT_MAX - written)
            format_failure("Formatted output exceeds original signed count range", count);
        for (uint32 index = 0u; index < (uint32)length; ++index)
            w_u8(destination + written++, (uint8)output[index]);
        free(output);
        free(string);
    }
    w_u8(destination + written, 0u);
    return written;
}
