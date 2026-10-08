#include "front_signatures.h"
#include "native_runtime.h"

/* Geometry and color fields consumed by the existing main renderer */
static uint32 front_a_glyph(uint32 texture, uint32 u, uint32 v, uint32 x, uint32 y,
                           uint32 red, uint32 green, uint32 blue, uint32 flags)
{
    uint32 storage = ob_draft_scratch_acquire(124u);
    uint32 fields = storage + 80u;
    w_u32(fields + 16u, 15u);
    w_u32(fields + 20u, x);
    w_u32(fields + 24u, y);
    w_u32(fields + 28u, flags);
    w_u32(fields + 32u, red);
    w_u32(fields + 36u, green);
    w_u32(fields + 40u, blue);
    uint32 result = ob_append_colored_texture_quad(texture, u, v, 15u, fields);
    ob_draft_scratch_release(storage);
    return result;
}

uint32 ob_front_a_callback(uint32 target,uint32 available,uint32 first,uint32 second)
{
    uint32 count=available;
    switch(target)
    {
    case 0x800117C8u: count=1u; break;
    case 0x800118C0u: count=1u; break;
    case 0x8001195Cu: count=2u; break;
    case 0x80011984u: count=7u; break;
    case 0x80011DA0u: count=2u; break;
    case 0x80011DC0u: count=2u; break;
    case 0x80011DE0u: count=2u; break;
    case 0x80011DF0u: count=1u; break;
    case 0x80012184u: count=0u; break;
    case 0x800121CCu: count=1u; break;
    case 0x8001221Cu: count=0u; break;
    case 0x80012294u: count=0u; break;
    case 0x800122ECu: count=0u; break;
    case 0x8001237Cu: count=0u; break;
    case 0x800123E4u: count=0u; break;
    case 0x80012758u: count=1u; break;
    case 0x800129FCu: count=1u; break;
    case 0x80012BE8u: count=1u; break;
    case 0x80013794u: count=0u; break;
    case 0x80013818u: count=0u; break;
    case 0x80013820u: count=0u; break;
    case 0x80013908u: count=0u; break;
    case 0x80013C00u: count=0u; break;
    case 0x80013FA4u: count=1u; break;
    case 0x80014BF8u: count=0u; break;
    case 0x8001578Cu: count=4u; break;
    case 0x800159C8u: count=0u; break;
    case 0x80015FA8u: count=3u; break;
    case 0x80016220u: count=1u; break;
    case 0x80016254u: count=0u; break;
    case 0x8001627Cu: count=1u; break;
    case 0x80016390u: count=1u; break;
    case 0x80016598u: count=1u; break;
    case 0x80016768u: count=0u; break;
    case 0x800169D0u: count=2u; break;
    case 0x80016A50u: count=1u; break;
    case 0x80016B88u: count=1u; break;
    case 0x80016C20u: count=0u; break;
    case 0x80016FC4u: count=1u; break;
    case 0x800170B8u: count=0u; break;
    case 0x800170C0u: count=0u; break;
    case 0x800170C8u: count=0u; break;
    case 0x800170D0u: count=0u; break;
    case 0x800170F8u: count=1u; break;
    case 0x80017178u: count=0u; break;
    case 0x800171ECu: count=2u; break;
    case 0x80017328u: count=2u; break;
    case 0x800174CCu: count=1u; break;
    case 0x80017554u: count=0u; break;
    case 0x80018454u: count=0u; break;
    case 0x8001994Cu: count=0u; break;
    case 0x80019EA0u: count=2u; break;
    case 0x80019EE0u: count=1u; break;
    case 0x8001A05Cu: count=0u; break;
    case 0x8001A0CCu: count=0u; break;
    case 0x8001A0F0u: count=0u; break;
    case 0x8001A1CCu: count=0u; break;
    case 0x8001A398u: count=0u; break;
    case 0x8001A4B0u: count=4u; break;
    case 0x8001A6FCu: count=0u; break;
    case 0x8001B008u: count=0u; break;
    case 0x8001B048u: count=0u; break;
    case 0x8001B058u: count=0u; break;
    case 0x8001CF58u: count=0u; break;
    case 0x8001D048u: count=1u; break;
    case 0x8001D1B0u: count=0u; break;
    case 0x8001DBCCu: count=1u; break;
    case 0x8001DCF4u: count=0u; break;
    case 0x8001DDA0u: count=0u; break;
    case 0x8001DDF8u: count=0u; break;
    case 0x8001DEB4u: count=1u; break;
    case 0x8001DF34u: count=0u; break;
    case 0x8001DF58u: count=1u; break;
    case 0x8001DFF0u: count=0u; break;
    case 0x8001E050u: count=0u; break;
    case 0x8001E108u: count=0u; break;
    case 0x8001E1E0u: count=0u; break;
    case 0x8001E298u: count=2u; break;
    case 0x8001E540u: count=0u; break;
    case 0x8001E7B0u: count=6u; break;
    case 0x8001EBBCu: count=6u; break;
    case 0x8001F454u: count=2u; break;
    case 0x8001F56Cu: count=2u; break;
    case 0x8001F5DCu: count=2u; break;
    case 0x8001F64Cu: count=2u; break;
    case 0x8001F874u: count=0u; break;
    case 0x8001F9B0u: count=2u; break;
    case 0x8001FC60u: count=0u; break;
    case 0x8001FDA4u: count=1u; break;
    case 0x8001FEDCu: count=1u; break;
    case 0x80020260u: count=0u; break;
    case 0x80020288u: count=0u; break;
    case 0x800202E8u: count=0u; break;
    case 0x80020450u: count=0u; break;
    case 0x80020864u: count=0u; break;
    case 0x80020A70u: count=0u; break;
    case 0x80020D64u: count=0u; break;
    case 0x80020FD4u: count=0u; break;
    case 0x8002140Cu: count=0u; break;
    case 0x80021460u: count=8u; break;
    case 0x800215FCu: count=11u; break;
    case 0x800217B4u: count=1u; break;
    case 0x8002192Cu: count=0u; break;
    case 0x80021A38u: count=1u; break;
    case 0x80021AD8u: count=0u; break;
    case 0x80021B20u: count=1u; break;
    case 0x80021C24u: count=0u; break;
    case 0x80021C74u: count=0u; break;
    case 0x80021D80u: count=0u; break;
    case 0x80021DE8u: count=0u; break;
    case 0x80021EFCu: count=0u; break;
    case 0x80021FF4u: count=1u; break;
    case 0x80022058u: count=0u; break;
    case 0x800220BCu: count=0u; break;
    case 0x80022234u: count=1u; break;
    case 0x800222FCu: count=1u; break;
    case 0x800223A0u: count=1u; break;
    case 0x80022440u: count=0u; break;
    case 0x800224A0u: count=0u; break;
    case 0x800226D0u: count=0u; break;
    case 0x80022AD4u: count=7u; break;
    case 0x80022C1Cu: count=1u; break;
    case 0x80022CD4u: count=0u; break;
    case 0x80022E78u: count=0u; break;
    case 0x80023138u: count=0u; break;
    case 0x800231E4u: count=0u; break;
    case 0x8002328Cu: count=0u; break;
    case 0x80023308u: count=1u; break;
    case 0x80023A10u: count=0u; break;
    case 0x80023AA8u: count=0u; break;
    case 0x80023B28u: count=2u; break;
    case 0x80023C08u: count=0u; break;
    case 0x80023E30u: count=0u; break;
    case 0x80023E70u: count=0u; break;
    case 0x80024310u: count=0u; break;
    case 0x80024320u: count=0u; break;
    case 0x8002439Cu: count=0u; break;
    case 0x80024400u: count=0u; break;
    case 0x80024548u: count=0u; break;
    case 0x80024640u: count=0u; break;
    case 0x80024938u: count=0u; break;
    case 0x80024B40u: count=0u; break;
    case 0x80024D24u: count=0u; break;
    case 0x80024D54u: count=1u; break;
    case 0x80024EA8u: count=0u; break;
    case 0x80024F18u: count=0u; break;
    case 0x80024F24u: count=1u; break;
    case 0x8002512Cu: count=1u; break;
    case 0x800251E8u: count=1u; break;
    case 0x800255F0u: count=0u; break;
    case 0x80025624u: count=0u; break;
    case 0x80025658u: count=0u; break;
    case 0x800256CCu: count=1u; break;
    case 0x80025700u: count=1u; break;
    case 0x800257A0u: count=0u; break;
    case 0x800257CCu: count=1u; break;
    case 0x80025874u: count=0u; break;
    case 0x800259ACu: count=1u; break;
    case 0x80025A9Cu: count=1u; break;
    case 0x80025ABCu: count=1u; break;
    case 0x80025CB4u: count=2u; break;
    case 0x80025D50u: count=0u; break;
    case 0x80025D6Cu: count=0u; break;
    case 0x80025DA0u: count=2u; break;
    case 0x800260C8u: count=0u; break;
    case 0x800260F8u: count=0u; break;
    case 0x80026164u: count=3u; break;
    case 0x80026278u: count=0u; break;
    case 0x800262CCu: count=2u; break;
    case 0x800263B4u: count=0u; break;
    case 0x80026418u: count=0u; break;
    case 0x80026444u: count=0u; break;
    case 0x80026460u: count=0u; break;
    case 0x80026694u: count=3u; break;
    case 0x80026734u: count=2u; break;
    case 0x80026758u: count=1u; break;
    case 0x8002679Cu: count=0u; break;
    case 0x800267C4u: count=0u; break;
    case 0x80026898u: count=2u; break;
    case 0x800268D0u: count=0u; break;
    case 0x800268E8u: count=2u; break;
    case 0x8002691Cu: count=0u; break;
    case 0x80026950u: count=0u; break;
    case 0x80026984u: count=0u; break;
    case 0x800269D0u: count=1u; break;
    case 0x80026D30u: count=2u; break;
    case 0x80026EB8u: count=1u; break;
    case 0x80026F48u: count=1u; break;
    case 0x80027154u: count=0u; break;
    case 0x800271ECu: count=2u; break;
    case 0x80027274u: count=2u; break;
    case 0x8002744Cu: count=1u; break;
    case 0x800276B4u: count=1u; break;
    case 0x80027710u: count=1u; break;
    case 0x800277D0u: count=0u; break;
    case 0x80027810u: count=0u; break;
    case 0x8002785Cu: count=0u; break;
    case 0x800278ACu: count=0u; break;
    case 0x80027978u: count=0u; break;
    case 0x800279A4u: count=0u; break;
    case 0x800279D4u: count=1u; break;
    case 0x80027A3Cu: count=0u; break;
    case 0x80027A74u: count=0u; break;
    case 0x80027AACu: count=0u; break;
    case 0x80027AE4u: count=0u; break;
    case 0x80027CD0u: count=1u; break;
    case 0x80027D78u: count=0u; break;
    case 0x80027DF8u: count=0u; break;
    case 0x80027E54u: count=2u; break;
    case 0x80027E90u: count=1u; break;
    case 0x80027ED8u: count=1u; break;
    case 0x80027F54u: count=0u; break;
    case 0x80027F98u: count=2u; break;
    case 0x80028280u: count=4u; break;
    case 0x800283C0u: count=0u; break;
    case 0x800283DCu: count=2u; break;
    case 0x80028614u: count=1u; break;
    case 0x80029290u: count=0u; break;
    case 0x800292B0u: count=2u; break;
    case 0x800292ECu: count=2u; break;
    case 0x80029B70u: count=3u; break;
    case 0x80029E30u: count=0u; break;
    case 0x80029E54u: count=0u; break;
    case 0x80029E80u: count=0u; break;
    case 0x80029EECu: count=2u; break;
    case 0x80029F58u: count=0u; break;
    case 0x8002A870u: count=0u; break;
    case 0x8002A9DCu: count=3u; break;
    case 0x8002AB48u: count=0u; break;
    case 0x8002ADFCu: count=0u; break;
    case 0x8002AF54u: count=0u; break;
    case 0x8002B15Cu: count=3u; break;
    case 0x8002B7FCu: count=0u; break;
    case 0x8002B868u: count=1u; break;
    case 0x8002C4ACu: count=0u; break;
    case 0x8002C728u: count=1u; break;
    case 0x8002C77Cu: count=1u; break;
    case 0x8002CA3Cu: count=0u; break;
    case 0x8002CCC8u: count=0u; break;
    case 0x8002CEB0u: count=1u; break;
    case 0x8002CFA8u: count=0u; break;
    case 0x8002CFE4u: count=2u; break;
    case 0x8002CFF4u: count=0u; break;
    case 0x8002D078u: count=5u; break;
    case 0x8002D25Cu: count=2u; break;
    case 0x8002D8A8u: count=1u; break;
    case 0x8002D98Cu: count=1u; break;
    case 0x8002DA68u: count=1u; break;
    case 0x8002DB08u: count=0u; break;
    case 0x8002DB3Cu: count=0u; break;
    case 0x8002DB6Cu: count=0u; break;
    case 0x8002DC10u: count=0u; break;
    case 0x8002E8D8u: count=0u; break;
    case 0x8002F284u: count=2u; break;
    case 0x8002F310u: count=2u; break;
    case 0x8002F4CCu: count=1u; break;
    case 0x8002F560u: count=0u; break;
    case 0x8002F9C4u: count=2u; break;
    case 0x8002FAA8u: count=0u; break;
    case 0x8002FE50u: count=3u; break;
    case 0x8002FED4u: count=3u; break;
    case 0x800303D4u: count=2u; break;
    case 0x8003042Cu: count=2u; break;
    case 0x80030700u: count=3u; break;
    case 0x8003077Cu: count=6u; break;
    case 0x80030924u: count=0u; break;
    case 0x80031FECu: count=0u; break;
    case 0x800328ECu: count=1u; break;
    case 0x80033528u: count=1u; break;
    case 0x80033F48u: count=0u; break;
    case 0x80033F90u: count=0u; break;
    case 0x80033FB0u: count=1u; break;
    case 0x800340A0u: count=1u; break;
    case 0x80034114u: count=2u; break;
    case 0x80034234u: count=0u; break;
    case 0x800342F0u: count=1u; break;
    case 0x80034430u: count=1u; break;
    case 0x80034530u: count=0u; break;
    case 0x80034768u: count=8u; break;
    case 0x80034910u: count=1u; break;
    case 0x800349D8u: count=1u; break;
    case 0x80034E10u: count=1u; break;
    case 0x80035178u: count=0u; break;
    case 0x80035220u: count=0u; break;
    case 0x80035270u: count=0u; break;
    case 0x800352B4u: count=1u; break;
    case 0x800354C8u: count=1u; break;
    case 0x80035618u: count=0u; break;
    case 0x800357DCu: count=0u; break;
    case 0x8003584Cu: count=1u; break;
    case 0x8003858Cu: count=1u; break;
    case 0x80039100u: count=1u; break;
    case 0x80039808u: count=2u; break;
    case 0x80039838u: count=4u; break;
    case 0x80039BD8u: count=1u; break;
    case 0x80039C30u: count=2u; break;
    case 0x80039E68u: count=2u; break;
    case 0x8003A430u: count=0u; break;
    case 0x8003AA8Cu: count=1u; break;
    case 0x800409E0u: count=0u; break;
    case 0x80040BF0u: count=1u; break;
    case 0x800415E4u: count=1u; break;
    case 0x80041B74u: count=0u; break;
    case 0x80041BB8u: count=0u; break;
    case 0x80041D7Cu: count=3u; break;
    case 0x80042368u: count=1u; break;
    case 0x800423D8u: count=0u; break;
    case 0x80042424u: count=1u; break;
    case 0x800425ECu: count=7u; break;
    case 0x80042644u: count=1u; break;
    case 0x800427ACu: count=0u; break;
    case 0x80042928u: count=2u; break;
    case 0x80042B54u: count=3u; break;
    case 0x80043120u: count=1u; break;
    case 0x80043404u: count=0u; break;
    case 0x800435ACu: count=2u; break;
    case 0x80043600u: count=3u; break;
    case 0x80043664u: count=0u; break;
    case 0x800436ACu: count=0u; break;
    case 0x800436D4u: count=0u; break;
    case 0x800436ECu: count=0u; break;
    case 0x8004378Cu: count=0u; break;
    case 0x800437C4u: count=2u; break;
    case 0x80043824u: count=0u; break;
    case 0x8004389Cu: count=0u; break;
    case 0x8004395Cu: count=0u; break;
    case 0x80043974u: count=0u; break;
    case 0x800439BCu: count=0u; break;
    case 0x80043AB0u: count=0u; break;
    case 0x80043AF4u: count=0u; break;
    case 0x80043B68u: count=1u; break;
    case 0x80043BACu: count=0u; break;
    case 0x80043C18u: count=0u; break;
    case 0x80043C6Cu: count=0u; break;
    case 0x80043C94u: count=0u; break;
    case 0x80043CD4u: count=0u; break;
    case 0x80043CDCu: count=0u; break;
    case 0x80043CF0u: count=0u; break;
    case 0x80043D20u: count=0u; break;
    case 0x80043D38u: count=0u; break;
    case 0x80043D78u: count=0u; break;
    case 0x80043DACu: count=0u; break;
    case 0x80043DBCu: count=0u; break;
    case 0x80043DECu: count=0u; break;
    case 0x80043E14u: count=0u; break;
    case 0x80043E3Cu: count=2u; break;
    case 0x80043EACu: count=3u; break;
    case 0x80043FD0u: count=0u; break;
    case 0x80044058u: count=0u; break;
    case 0x800440E8u: count=0u; break;
    case 0x80044130u: count=1u; break;
    case 0x800441ACu: count=0u; break;
    case 0x800442F0u: count=3u; break;
    case 0x8004434Cu: count=3u; break;
    case 0x80044474u: count=3u; break;
    case 0x800444F4u: count=2u; break;
    case 0x80044C58u: count=0u; break;
    case 0x80044C90u: count=1u; break;
    case 0x80044CD4u: count=1u; break;
    case 0x80044D50u: count=0u; break;
    case 0x80044DBCu: count=4u; break;
    case 0x80044E5Cu: count=3u; break;
    case 0x80044EDCu: count=4u; break;
    case 0x80045094u: count=1u; break;
    case 0x80045124u: count=1u; break;
    case 0x8004514Cu: count=0u; break;
    case 0x800451E4u: count=0u; break;
    case 0x80045204u: count=1u; break;
    case 0x80045284u: count=2u; break;
    case 0x80045378u: count=3u; break;
    case 0x800453C4u: count=0u; break;
    case 0x80045430u: count=1u; break;
    case 0x80045464u: count=2u; break;
    case 0x80045490u: count=1u; break;
    case 0x800454BCu: count=1u; break;
    case 0x800455DCu: count=2u; break;
    case 0x80045758u: count=3u; break;
    case 0x80045848u: count=2u; break;
    case 0x800458B4u: count=3u; break;
    case 0x80045A44u: count=2u; break;
    case 0x80045A7Cu: count=0u; break;
    case 0x80045ADCu: count=1u; break;
    case 0x80045B74u: count=0u; break;
    case 0x80045C30u: count=1u; break;
    case 0x80045C98u: count=0u; break;
    case 0x80045D44u: count=0u; break;
    case 0x80045D70u: count=1u; break;
    case 0x80045EF4u: count=0u; break;
    case 0x80045F20u: count=0u; break;
    case 0x80045F4Cu: count=1u; break;
    case 0x800460B0u: count=0u; break;
    case 0x80046124u: count=1u; break;
    case 0x80046184u: count=3u; break;
    case 0x800461E8u: count=4u; break;
    case 0x800464BCu: count=1u; break;
    case 0x8004651Cu: count=1u; break;
    case 0x80046544u: count=1u; break;
    case 0x800465E8u: count=2u; break;
    case 0x8004670Cu: count=3u; break;
    case 0x80046914u: count=2u; break;
    case 0x80046954u: count=2u; break;
    case 0x80046AF8u: count=2u; break;
    case 0x80046BE8u: count=4u; break;
    case 0x80046CACu: count=1u; break;
    case 0x80046CDCu: count=1u; break;
    case 0x80046D98u: count=1u; break;
    case 0x80046E6Cu: count=2u; break;
    case 0x80046EACu: count=2u; break;
    case 0x80047050u: count=2u; break;
    case 0x80047140u: count=2u; break;
    case 0x8004719Cu: count=2u; break;
    case 0x8004735Cu: count=2u; break;
    case 0x80047450u: count=4u; break;
    case 0x800477B8u: count=4u; break;
    case 0x8004795Cu: count=1u; break;
    case 0x800479E0u: count=0u; break;
    case 0x80047A60u: count=0u; break;
    case 0x80047B24u: count=1u; break;
    case 0x80047B54u: count=3u; break;
    case 0x80047E2Cu: count=4u; break;
    case 0x80047F60u: count=1u; break;
    case 0x80047FF0u: count=1u; break;
    case 0x80048020u: count=1u; break;
    case 0x800480A8u: count=1u; break;
    case 0x80048124u: count=1u; break;
    case 0x800486E4u: count=1u; break;
    case 0x800487B8u: count=1u; break;
    case 0x80048978u: count=0u; break;
    case 0x80048994u: count=1u; break;
    case 0x80048B60u: count=0u; break;
    case 0x80048BF4u: count=1u; break;
    case 0x80048D2Cu: count=1u; break;
    case 0x80048FECu: count=0u; break;
    case 0x800491B0u: count=4u; break;
    case 0x800493F8u: count=1u; break;
    case 0x8004954Cu: count=1u; break;
    case 0x800496D8u: count=1u; break;
    case 0x80049A10u: count=1u; break;
    case 0x80049ED4u: count=3u; break;
    case 0x8004A048u: count=4u; break;
    case 0x8004A1C0u: count=0u; break;
    case 0x8004A2ECu: count=1u; break;
    case 0x8004A410u: count=1u; break;
    case 0x8004A48Cu: count=1u; break;
    case 0x8004A564u: count=0u; break;
    case 0x8004A5C4u: count=0u; break;
    case 0x8004A908u: count=1u; break;
    case 0x8004AAFCu: count=2u; break;
    case 0x8004B0B0u: count=0u; break;
    case 0x8004B3C4u: count=0u; break;
    case 0x8004B3E8u: count=0u; break;
    case 0x8004B450u: count=2u; break;
    case 0x8004B514u: count=0u; break;
    case 0x8004B634u: count=0u; break;
    case 0x8004B6ACu: count=0u; break;
    case 0x8004B70Cu: count=0u; break;
    case 0x8004B7A0u: count=1u; break;
    case 0x8004B9B0u: count=0u; break;
    case 0x8004BA60u: count=0u; break;
    case 0x8004BA98u: count=0u; break;
    case 0x8004BB48u: count=0u; break;
    case 0x8004BBE4u: count=0u; break;
    case 0x8004BC2Cu: count=0u; break;
    case 0x8004BC88u: count=0u; break;
    case 0x8004BCF8u: count=0u; break;
    case 0x8004BF54u: count=2u; break;
    case 0x8004C2C4u: count=3u; break;
    case 0x8004C4D4u: count=0u; break;
    case 0x8004C64Cu: count=4u; break;
    case 0x8004C944u: count=1u; break;
    case 0x8004CD2Cu: count=0u; break;
    case 0x8004CDF4u: count=2u; break;
    case 0x8004CE64u: count=2u; break;
    case 0x8004CF28u: count=0u; break;
    case 0x8004D0F8u: count=0u; break;
    case 0x8004D634u: count=1u; break;
    case 0x8004D76Cu: count=6u; break;
    case 0x8004D910u: count=6u; break;
    case 0x8004DAA4u: count=4u; break;
    case 0x8004DB40u: count=3u; break;
    case 0x8004DFB8u: count=1u; break;
    case 0x8004E028u: count=3u; break;
    case 0x8004E310u: count=2u; break;
    case 0x8004E3B0u: count=0u; break;
    case 0x8004E518u: count=4u; break;
    case 0x8004E584u: count=3u; break;
    case 0x8004E614u: count=1u; break;
    case 0x8004E644u: count=1u; break;
    case 0x8004E70Cu: count=0u; break;
    case 0x8004E814u: count=0u; break;
    case 0x8004E9E4u: count=4u; break;
    case 0x8004EC6Cu: count=0u; break;
    case 0x8004EEF4u: count=2u; break;
    case 0x8004F004u: count=2u; break;
    case 0x8004F064u: count=0u; break;
    case 0x8004F074u: count=3u; break;
    case 0x8004F0D8u: count=4u; break;
    case 0x8004F288u: count=1u; break;
    case 0x8004F2C4u: count=2u; break;
    case 0x8004F31Cu: count=1u; break;
    case 0x8004F354u: count=0u; break;
    case 0x8004F418u: count=3u; break;
    case 0x8004F478u: count=2u; break;
    case 0x8004F51Cu: count=3u; break;
    case 0x8004F610u: count=2u; break;
    case 0x8004F758u: count=2u; break;
    case 0x8004FA0Cu: count=6u; break;
    case 0x8004FC64u: count=7u; break;
    case 0x80050088u: count=4u; break;
    case 0x800502ACu: count=3u; break;
    case 0x80050380u: count=1u; break;
    case 0x80050550u: count=1u; break;
    case 0x80050644u: count=1u; break;
    case 0x80050870u: count=0u; break;
    case 0x800508D0u: count=1u; break;
    case 0x80050A2Cu: count=1u; break;
    case 0x80050B88u: count=2u; break;
    case 0x80051400u: count=2u; break;
    case 0x80051450u: count=2u; break;
    case 0x800514E4u: count=0u; break;
    case 0x8005160Cu: count=0u; break;
    case 0x80051974u: count=0u; break;
    case 0x80052A68u: count=0u; break;
    case 0x80053D20u: count=2u; break;
    case 0x80053E2Cu: count=0u; break;
    case 0x800540F8u: count=0u; break;
    case 0x80054264u: count=0u; break;
    case 0x80054320u: count=0u; break;
    case 0x80054440u: count=0u; break;
    case 0x800544ECu: count=0u; break;
    case 0x80054780u: count=0u; break;
    case 0x8005491Cu: count=0u; break;
    case 0x80054A24u: count=2u; break;
    case 0x80054AE0u: count=0u; break;
    case 0x80054B30u: count=0u; break;
    case 0x80054C14u: count=0u; break;
    case 0x80054CA8u: count=0u; break;
    case 0x80054CD8u: count=0u; break;
    case 0x80054CECu: count=0u; break;
    case 0x80054CFCu: count=0u; break;
    case 0x80054D50u: count=0u; break;
    case 0x80054E08u: count=4u; break;
    case 0x80054EFCu: count=1u; break;
    case 0x800551B0u: count=0u; break;
    case 0x800551F8u: count=0u; break;
    case 0x800552D4u: count=3u; break;
    case 0x800553D0u: count=3u; break;
    case 0x800556D8u: count=0u; break;
    case 0x800556F4u: count=0u; break;
    case 0x8005577Cu: count=1u; break;
    case 0x80055808u: count=0u; break;
    case 0x800558E4u: count=0u; break;
    case 0x800558F4u: count=0u; break;
    case 0x80055954u: count=2u; break;
    case 0x80056580u: count=0u; break;
    case 0x80058D98u: count=0u; break;
    case 0x80058FC0u: count=0u; break;
    case 0x80059128u: count=3u; break;
    case 0x8005A9DCu: count=0u; break;
    case 0x8005A9F4u: count=0u; break;
    case 0x8005F468u: count=2u; break;
    case 0x8005F488u: count=1u; break;
    case 0x8005F998u: count=0u; break;
    case 0x800602D0u: count=0u; break;
    case 0x80061034u: count=0u; break;
    case 0x800629C4u: count=2u; break;
    case 0x80063C1Cu: count=1u; break;
    case 0x80063C70u: count=0u; break;
    case 0x80063CD8u: count=0u; break;
    case 0x80063CE8u: count=0u; break;
    case 0x80064900u: count=0u; break;
    case 0x8008DB20u: count=1u; break;
    case 0x8008DD3Cu: count=1u; break;
    case 0x8008DD94u: count=1u; break;
    case 0x8008E090u: count=1u; break;
    case 0x8008E138u: count=0u; break;
    case 0x8008E140u: count=1u; break;
    case 0x8008E198u: count=0u; break;
    case 0x8008E1A0u: count=1u; break;
    case 0x8008E204u: count=0u; break;
    case 0x8008E20Cu: count=1u; break;
    case 0x8008E270u: count=0u; break;
    case 0x8008E278u: count=1u; break;
    case 0x8008E2DCu: count=2u; break;
    case 0x8008E380u: count=2u; break;
    case 0x8008E424u: count=2u; break;
    case 0x8008E4D8u: count=0u; break;
    case 0x8008E530u: count=0u; break;
    case 0x8008E588u: count=0u; break;
    case 0x8008E5E0u: count=1u; break;
    case 0x8008E654u: count=0u; break;
    case 0x8008E65Cu: count=3u; break;
    case 0x8008E780u: count=2u; break;
    case 0x8008E828u: count=2u; break;
    case 0x8008E998u: count=2u; break;
    case 0x8008EB5Cu: count=0u; break;
    case 0x8008EBC8u: count=2u; break;
    case 0x8008ED3Cu: count=0u; break;
    case 0x8008EDD0u: count=1u; break;
    case 0x8008EEECu: count=0u; break;
    case 0x8008EEF4u: count=2u; break;
    case 0x8008F684u: count=2u; break;
    case 0x8008F7F0u: count=2u; break;
    case 0x80091274u: count=2u; break;
    case 0x80091920u: count=2u; break;
    case 0x800920FCu: count=0u; break;
    case 0x80092114u: count=0u; break;
    case 0x8009212Cu: count=2u; break;
    case 0x800921D0u: count=2u; break;
    case 0x80092214u: count=2u; break;
    case 0x80092280u: count=2u; break;
    case 0x8009234Cu: count=1u; break;
    case 0x800923D4u: count=1u; break;
    case 0x80092704u: count=2u; break;
    case 0x80092814u: count=1u; break;
    case 0x800928DCu: count=0u; break;
    case 0x80092928u: count=2u; break;
    case 0x80092BC4u: count=1u; break;
    case 0x80092C30u: count=1u; break;
    case 0x80092CB0u: count=1u; break;
    case 0x80092D14u: count=0u; break;
    case 0x80092D1Cu: count=2u; break;
    case 0x80092D30u: count=1u; break;
    case 0x80092DACu: count=3u; break;
    case 0x80092E84u: count=1u; break;
    case 0x8009307Cu: count=0u; break;
    case 0x80093150u: count=0u; break;
    case 0x80093224u: count=0u; break;
    case 0x800932A0u: count=0u; break;
    case 0x8009331Cu: count=0u; break;
    case 0x8009341Cu: count=0u; break;
    case 0x8009350Cu: count=0u; break;
    case 0x80093780u: count=0u; break;
    case 0x800939F4u: count=0u; break;
    case 0x80093A34u: count=0u; break;
    case 0x80093A74u: count=0u; break;
    case 0x80093AB4u: count=0u; break;
    case 0x80093AF4u: count=0u; break;
    case 0x80093B34u: count=0u; break;
    case 0x80093B74u: count=0u; break;
    case 0x80093BB4u: count=5u; break;
    case 0x80093E70u: count=1u; break;
    case 0x80094030u: count=4u; break;
    case 0x80094288u: count=5u; break;
    case 0x80094488u: count=7u; break;
    case 0x8009465Cu: count=6u; break;
    case 0x800946F0u: count=1u; break;
    case 0x80094790u: count=1u; break;
    case 0x800947B4u: count=0u; break;
    case 0x800947ECu: count=1u; break;
    case 0x8009482Cu: count=1u; break;
    case 0x80094894u: count=2u; break;
    case 0x800948D0u: count=2u; break;
    case 0x80094918u: count=2u; break;
    case 0x800949ACu: count=2u; break;
    case 0x800949F4u: count=2u; break;
    case 0x80094A88u: count=2u; break;
    case 0x80094B7Cu: count=2u; break;
    case 0x80094C68u: count=4u; break;
    case 0x80094DFCu: count=4u; break;
    case 0x80094FB0u: count=3u; break;
    case 0x80095094u: count=0u; break;
    case 0x80095D1Cu: count=2u; break;
    case 0x80095DF0u: count=3u; break;
    case 0x80095F9Cu: count=3u; break;
    case 0x800962A4u: count=3u; break;
    case 0x80096550u: count=4u; break;
    case 0x80096B8Cu: count=2u; break;
    case 0x80096CECu: count=2u; break;
    case 0x80096E3Cu: count=1u; break;
    case 0x80096EDCu: count=1u; break;
    case 0x80097094u: count=1u; break;
    case 0x80097114u: count=2u; break;
    case 0x800971D0u: count=1u; break;
    case 0x800971F0u: count=1u; break;
    case 0x80097210u: count=1u; break;
    case 0x80097458u: count=1u; break;
    case 0x800974E4u: count=3u; break;
    case 0x8009789Cu: count=1u; break;
    case 0x800978F0u: count=1u; break;
    case 0x80097944u: count=1u; break;
    case 0x80097DFCu: count=1u; break;
    case 0x80097E5Cu: count=1u; break;
    case 0x80097EF8u: count=1u; break;
    case 0x80097FE8u: count=2u; break;
    case 0x80098058u: count=3u; break;
    case 0x800980B0u: count=3u; break;
    case 0x8009810Cu: count=3u; break;
    case 0x80098168u: count=1u; break;
    case 0x800981C8u: count=1u; break;
    case 0x80098298u: count=1u; break;
    case 0x800988BCu: count=1u; break;
    case 0x8009898Cu: count=5u; break;
    case 0x80098DFCu: count=1u; break;
    case 0x800993B4u: count=1u; break;
    case 0x800994B0u: count=4u; break;
    case 0x800996B8u: count=1u; break;
    case 0x8009978Cu: count=1u; break;
    case 0x80099890u: count=2u; break;
    case 0x800999D8u: count=3u; break;
    case 0x80099AF4u: count=0u; break;
    case 0x8009A248u: count=3u; break;
    case 0x8009A2E4u: count=2u; break;
    case 0x8009AB74u: count=1u; break;
    case 0x8009AE68u: count=2u; break;
    case 0x8009B4E4u: count=1u; break;
    case 0x8009B540u: count=2u; break;
    case 0x8009B704u: count=2u; break;
    case 0x8009B7A0u: count=3u; break;
    case 0x8009B8E4u: count=1u; break;
    case 0x8009B94Cu: count=2u; break;
    default: break;
    }
    /* TODO: Recover any additional meaningful callback inputs at the caller */
    if(count>available||count>2u) return ob_native_missing_value(target,"Missing meaningful callback argument");
    if(count==0u) return ob_draft_unresolved_call(target,0u);
    if(count==1u) return ob_draft_unresolved_call(target,1u,first);
    return ob_draft_unresolved_call(target,2u,first,second);
}

uint32 ob_front_8008E140(uint32 a1)
{
    FUNCTION_MARKER(0x8008E140u, "FRONT.BIN");
    ob_front_8008DD3C(a1);
    ob_front_8008DD3C(r_u32(0x8009BB8Cu));
    uint32 result = ob_front_8008DD3C(r_u32(0x8009BB90u));
    w_u32(0x8009BB88u, 0u); w_u32(0x8009BB8Cu, 0u); w_u32(0x8009BB90u, 0u);
    return result;
}

uint32 ob_front_8008E270(void)
{
    FUNCTION_MARKER(0x8008E270u, "FRONT.BIN");
    return ob_front_8008E278(r_u32(0x8009BB90u));
}

uint32 ob_front_8008E278(uint32 object)
{
    FUNCTION_MARKER(0x8008E278u, "FRONT.BIN");
    if (r_u32(object + 120u) - 1u < 2u) return 256u;
    sub_80011984(0x8006ABFCu,255u,25u,15u,256u,0u,0u);
    w_u32(r_u32(0x8009BB90u) + 120u,1u);
    return 1u;
}

void ob_front_80092D14(void)
{
    FUNCTION_MARKER(0x80092D14u, "FRONT.BIN");
}

uint32 ob_front_80092280(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80092280u, "FRONT.BIN");
    (void)a1;
    uint32 value = r_u32(a2 + 8u), sound;
    if (value == 0u) { ob_draft_unresolved_call(0x80011870u,1u,1u); sound = 0x8006AC1Cu; }
    else if (value == 1u) { ob_draft_unresolved_call(0x80011870u,1u,2u); sound = 0x8006AC3Cu; }
    else if (value == 2u) { ob_draft_unresolved_call(0x80011870u,1u,4u); sound = 0x8006AC18u; }
    else { w_u8(0x8006C22Fu,value); return value; }
    sub_80011984(sound,255u,15u,15u,256u,0u,0u);
    value = r_u32(a2 + 8u); w_u8(0x8006C22Fu,value); return value;
}

uint32 ob_front_80092704(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80092704u, "FRONT.BIN");
    uint32 y = r_u32(a2)*17u +55u;
    ob_front_80092E84(a1);
    uint32 selected = r_u32(a1+12u)==a2;
    uint32 flags = selected && (r_u32(a2+4u)&256u)!=0u;
    ob_front_80093BB4(r_u32(a2+8u),164u,y,selected,flags);
    return ob_front_80094488(r_u32(0x8009C878u+r_u32(a2)*4u),90u,y,
                            selected?91u:45u,selected?15u:40u,selected?8u:22u,0u);
}

uint32 ob_front_80092C30(uint32 a1)
{
    FUNCTION_MARKER(0x80092C30u, "FRONT.BIN");
    uint32 item = r_u32(a1+8u);
    ob_front_8009465C(0x8008D200u,50u,91u,15u,8u,0u);
    do {
        uint32 callback = r_u32(item+44u);
        if(callback) ob_front_a_callback(callback,2u,a1,item);
        item = r_u32(item+20u);
    } while(item != r_u32(a1+8u));
    return r_u32(a1+8u);
}

void ob_front_80093BB4(uint32 code, uint32 x, uint32 y, uint32 selected, uint32 flags)
{
    FUNCTION_MARKER(0x80093BB4u, "FRONT.BIN");
    uint32 texture;
    switch(code) {
    case 4: case 20: texture=0x8006AD74u; break;
    case 5: case 21: texture=0x8006AD7Cu; break;
    case 6: case 22: texture=0x8006AD70u; break;
    case 7: case 23: texture=0x8006AD78u; break;
    case 8: case 24: texture=selected?0x8006AD4Cu:0x8006AD88u; goto basic;
    case 9: case 25: texture=selected?0x8006AD54u:0x8006AD90u; goto basic;
    case 10: case 26: texture=selected?0x8006AD48u:0x8006AD84u; goto basic;
    case 11: case 27: texture=selected?0x8006AD50u:0x8006AD8Cu; goto basic;
    case 12: case 28: texture=selected?0x8006AD64u:0x8006ADA0u; goto basic;
    case 13: case 29: texture=selected?0x8006AD58u:0x8006AD94u; goto basic;
    case 14: case 30: texture=selected?0x8006AD5Cu:0x8006AD98u; goto basic;
    case 15: case 31: texture=selected?0x8006AD60u:0x8006AD9Cu; goto basic;
    default: return;
    }
    sub_800215FC(texture,0u,0u,16u,16u,x,y,selected?91u:45u,
                 selected?15u:40u,selected?8u:22u,flags);
    return;
basic:
    sub_80021460(texture,0u,0u,16u,16u,x,y,flags);
}

uint32 ob_front_80093E70(uint32 a1)
{
    FUNCTION_MARKER(0x80093E70u, "FRONT.BIN");
    uint32 index, record=a1;
    sint32 count=(sint32)r_u32(a1);
    for(index=0u;(sint32)index<count;++index,record+=36u)
        w_u32(record+36u,ob_front_800946F0(record+8u)+18u);
    if(count==0) return ob_draft_unresolved_call(0x80093EF4u,1u,7u);
    uint32 spacing=(uint32)(357/count), position=12u;
    record=a1;
    for(index=0u;(sint32)index<count;++index,record+=36u) {
        uint32 x=r_u32(record+28u),y=r_u32(record+32u),width=r_u32(record+36u);
        if(x==0xFFFFFFFFu) x=position+(uint32)((sint32)(spacing-width)/2);
        else if(x==0xFFFFFFFEu) x=12u+(uint32)((sint32)(136u-width)/2);
        else if(x==0xFFFFFFFDu) x=233u+(uint32)((sint32)(136u-width)/2);
        if(y==0xFFFFFFFFu) y=220u;
        w_u32(record+28u,x); w_u32(record+32u,y);
        position+=spacing;
        ob_front_80094030(r_u32(record+4u),record+8u,x,y);
    }
    return count>0?0u:357u;
}

void ob_front_80094030(uint32 a1,uint32 a2,uint32 a3,uint32 a4)
{
    FUNCTION_MARKER(0x80094030u,"FRONT.BIN");
    uint32 texture=0u,code=0u;
    switch(a1) {
    case 0: texture=0x8006AD74u; break;
    case 1: texture=0x8006AD70u; break;
    case 2: code=7u; break; case 3: code=5u; break;
    case 4: code=14u; break; case 5: code=15u; break;
    case 6: code=3u; break; case 7: code=12u; break;
    case 8: texture=0x8006AD6Cu; break;
    case 9: texture=0x8006AD68u; break;
    case 10: texture=0x8006AD80u; break;
    default: sub_80022AD4(a2,a3,a4+5u,128u,128u,128u,0u); return;
    }
    if(texture) sub_800215FC(texture,0u,0u,16u,16u,a3,a4,91u,15u,8u,0u);
    else ob_front_80093BB4(code,a3,a4,1u,0u);
    sub_80022AD4(a2,a3+18u,a4+5u,128u,128u,128u,0u);
}

uint32 ob_front_80094488(uint32 text,uint32 x,uint32 y,uint32 red,uint32 green,uint32 blue,uint32 flags)
{
    FUNCTION_MARKER(0x80094488u,"FRONT.BIN");
    /* The entry identity return is overwritten by the loop comparison */
    uint32 texture=0u,index=0u;
    while((sint32)index<(sint32)ob_draft_unresolved_call(0x80063FB8u,1u,text)) {
        uint32 character=r_u8(text+index);
        if(character==32u) x+=6u;
        else {
            sint32 glyph=(sint32)character-33;
            sint32 page=(glyph<0?glyph+15:glyph)>>4;
            sint32 cell=glyph-page*16;
            if((uint32)page<6u) texture=0x8006AD30u+(uint32)page*4u;
            else texture=ob_native_missing_value(0x80094488u,"Glyph page outside the texture table");
            front_a_glyph(texture,(uint32)((cell%4)*16),(uint32)((cell/4)*16),x,y,red,green,blue,flags);
            x+=1u+(uint32)(sint32)(sint8)r_u8(0x8009CC74u+(uint32)glyph);
        }
        ++index;
    }
    /* The terminating signed loop comparison leaves zero in v0 */
    return ob_draw_text_end(0u);
}

uint32 ob_front_8009465C(uint32 text,uint32 y,uint32 red,uint32 green,uint32 blue,uint32 flags)
{
    FUNCTION_MARKER(0x8009465Cu,"FRONT.BIN");
    uint32 width=ob_front_800946F0(text);
    return ob_front_80094488(text,(uint32)((sint32)(386u-width)/2),y,red,green,blue,flags);
}

uint32 ob_front_800949F4(uint32 object,uint32 state)
{
    FUNCTION_MARKER(0x800949F4u,"FRONT.BIN");
    uint32 value;
    switch(state) {
    case 0: value=0x8006AAF0u; break;
    case 1: value=0x8006AAF8u; break;
    case 2: value=0x8006AB00u; break;
    case 3: value=0x8006AB08u; break;
    default: return (sint32)state<2?1u:3u;
    }
    w_u32(r_u32(object+52u)+40u,value); return value;
}

uint32 ob_front_80096B8C(uint32 selected_action,uint32 mode)
{
    FUNCTION_MARKER(0x80096B8Cu,"FRONT.BIN");
    static const uint32 strings[4]={0x8008D754u,0x8008D75Cu,0x8008D764u,0x8008D76Cu};
    uint32 result=0u;
    for(uint32 i=0u;i<4u;++i)
        result=ob_front_80094288(strings[i],r_u32(0x8009CF00u+i*4u),82u+i*56u,188u,mode==2u&&selected_action==i);
    if(mode==2u) { result=0x8009BFA4u; w_u32(0x8009BB94u,result); }
    return result;
}

uint32 ob_front_80094DFC(uint32 card,uint32 slot,uint32 x,uint32 y)
{
    FUNCTION_MARKER(0x80094DFCu,"FRONT.BIN");
    uint32 record=0x80089D34u+card*552u+slot*36u;
    uint32 texture=r_u32(0x8006CEC4u+slot*4u), header=0x80084AC8u+slot*512u;
    uint32 pixels,palette,frames=r_u8(header+2u)&3u;
    if(!r_u32(record)||!frames) { pixels=0x8009CD80u;palette=0x8009CE00u; }
    else
    {
        if(frames>=2u) w_u32(record+8u,r_u32(record+8u)<frames*2u-1u?r_u32(record+8u)+1u:0u);
        palette=header+96u;pixels=header+128u+(uint32)((sint32)r_u32(record+8u)/2)*128u;
    }
    ob_draft_unresolved_call(0x80020BD8u,3u,texture,pixels,palette);
    return sub_80021460(texture,0u,0u,16u,16u,(uint32)(sint32)(sint16)x,(uint32)(sint32)(sint16)y,0u);
}

uint32 ob_front_800978F0(uint32 menu)
{
    FUNCTION_MARKER(0x800978F0u,"FRONT.BIN");
    uint32 callback=r_u32(menu+32u);
    if(callback) ob_front_a_callback(callback,1u,menu,0u);
    callback=r_u32(menu+20u);
    return callback?ob_front_a_callback(callback,1u,menu,0u):0u;
}

uint32 ob_front_80097944(uint32 handle)
{
    FUNCTION_MARKER(0x80097944u,"FRONT.BIN");
    uint32 menu=r_u32(handle),item=r_u32(menu+12u),callback=r_u32(item+32u);
    uint32 command=ob_front_a_callback(callback,1u,handle,0u),parent;
    menu=r_u32(handle);item=r_u32(menu+12u);
    switch(command)
    {
    case 1u: if(!(r_u32(menu)&64u)) return 0xFFFFFFFEu; break;
    case 3u: if(!(r_u32(menu)&64u)) return 0xFFFFFFFDu; break;
    case 2u:
        if(r_u32(menu)&64u) break;
        callback=r_u32(menu+32u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
        menu=r_u32(handle);parent=r_u32(menu+4u);if(!parent)return 0xFFFFFFFEu;
        w_u32(handle,parent);callback=r_u32(parent+28u);if(callback)ob_front_a_callback(callback,1u,parent,0u);
        break;
    case 4u: case 5u:
        callback=r_u32(item+52u);if(callback)ob_front_a_callback(callback,2u,menu,item);
        menu=r_u32(handle);item=r_u32(menu+12u);item=r_u32(item+(command==4u?16u:20u));w_u32(menu+12u,item);
        callback=r_u32(item+48u);if(callback)ob_front_a_callback(callback,2u,menu,item);
        break;
    case 6u: case 7u:
        if(!(r_u32(item+4u)&0x400u))
        {
            sint32 value=(sint32)r_u32(item+8u),maximum=(sint32)r_u32(item+12u);
            if(command==6u)
            {
                if(value<maximum)w_u32(item+8u,(uint32)value+1u);
                else if(r_u32(item+4u)&4u)w_u32(item+8u,0u);else break;
            }
            else
            {
                if(value>0)w_u32(item+8u,(uint32)value-1u);
                else if(r_u32(item+4u)&4u)w_u32(item+8u,(uint32)maximum);else break;
            }
        }
        menu=r_u32(handle);item=r_u32(menu+12u);callback=r_u32(item+(command==6u?56u:60u));
        if(callback)ob_front_a_callback(callback,2u,menu,item);
        break;
    case 10u:
        callback=r_u32(item+64u);if(callback)ob_front_a_callback(callback,2u,menu,item);
        menu=r_u32(handle);item=r_u32(menu+12u);
        if(callback&&(r_u32(item+4u)&1u))return 0xFFFFFFFFu;
        if(r_u32(item+4u)&0x10u)
        {
            callback=r_u32(menu+32u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
            menu=r_u32(handle);item=r_u32(menu+12u);parent=r_u32(item+28u);w_u32(handle,parent);w_u32(parent+4u,menu);
            callback=r_u32(parent+28u);if(callback)ob_front_a_callback(callback,1u,parent,0u);
            parent=r_u32(handle);if(!(r_u32(parent)&0x80u))w_u32(parent+12u,r_u32(parent+8u));
        }
        else if(r_u32(item+4u)&0x20u)
        {
            callback=r_u32(menu+32u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
            menu=r_u32(handle);parent=r_u32(menu+4u);w_u32(handle,parent);
            callback=r_u32(parent+28u);if(callback)ob_front_a_callback(callback,1u,parent,0u);
            if(!(r_u32(menu)&0x80u))w_u32(menu+12u,r_u32(menu+8u));
        }
        else if(r_u32(item+4u)&8u)
        {
            callback=r_u32(menu+32u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
            return r_u32(r_u32(r_u32(handle)+12u));
        }
        break;
    default: break;
    }
    menu=r_u32(handle);callback=r_u32(menu+24u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
    return 0xFFFFFFFFu;
}

uint32 ob_front_80097EF8(uint32 template_address)
{
    FUNCTION_MARKER(0x80097EF8u,"FRONT.BIN");
    uint32 handle=ob_draft_scratch_acquire(4u),object;
    w_u32(handle,0u);sub_800262CC(handle,68u);object=r_u32(handle);
    if(object)
    {
        ob_fill_words(object,68u,0u,object);
        for(uint32 i=0u;i<4u;++i)w_u32(object+i*4u,r_u32(template_address+i*4u));
        for(uint32 i=0u;i<9u;++i)w_u32(object+32u+i*4u,r_u32(template_address+16u+i*4u));
    }
    ob_draft_scratch_release(handle);return object;
}

void ob_front_80094FB0(uint32 source,uint32 destination,uint32 count)
{
    FUNCTION_MARKER(0x80094FB0u,"FRONT.BIN");
    if((sint32)count<=0)return;
    uint32 end=destination+count*2u;
    do
    {
        uint32 pixel=r_u16(source),color=0u;
        if(pixel)
        {
            uint32 sum=(pixel&31u)+((pixel>>5)&31u)+((pixel>>10)&31u);
            uint32 red=(uint32)(((uint64)(sum*26u)*0x2C0B02C1u)>>36);
            uint32 green=(uint32)(((uint64)(sum*22u)*0x2C0B02C1u)>>36);
            uint32 blue=(uint32)(((uint64)(sum*15u)*0x2C0B02C1u)>>36);
            color=red+(green<<5)+(blue<<10)+0x8000u;
        }
        w_u16(destination,(uint16)color);destination+=2u;source+=2u;
    }while((sint32)destination<(sint32)end);
}

uint32 ob_front_80095F9C(uint32 card,uint32 slot,uint32 state)
{
    FUNCTION_MARKER(0x80095F9Cu,"FRONT.BIN");
    uint32 x=136u+(uint32)((sint32)slot%5)*24u,y=88u+(uint32)((sint32)slot/5)*24u;
    if(card==0xFFFFFFFFu)state=0u;
    if(state==0u)return ob_draft_unresolved_call(0x80020A70u,8u,x,y,16u,16u,128u,128u,128u,1u);
    if(state>=1u&&state<=3u)
    {
        if(r_u32(0x8006BCC4u)==card&&r_u32(0x8006BCC8u)==slot)
            ob_draft_unresolved_call(0x80020A70u,8u,x-4u,y-4u,24u,24u,64u,64u,64u,1u);
        if(state>=2u)ob_draft_unresolved_call(0x80020A70u,8u,x-4u,y-4u,24u,24u,96u,0u,0u,1u);
        if(state<=2u)return ob_front_80094C68(card,slot,(uint32)(sint32)(sint16)x,(uint32)(sint32)(sint16)y);
        ob_front_80094DFC(card,slot,(uint32)(sint32)(sint16)x,(uint32)(sint32)(sint16)y);
        uint32 header=0x80084AC8u+slot*512u,text=0x8008D414u,storage=0u;
        if(r_u8(header)==83u&&r_u8(header+1u)==67u)
        {
            storage=ob_draft_scratch_acquire(40u);
            ob_draft_unresolved_call(0x80063FA8u,3u,storage,header+4u,32u);w_u8(storage+32u,0u);text=storage;
        }
        uint32 result=ob_front_8009465C(text,158u,91u,15u,8u,0u);
        if(storage)ob_draft_scratch_release(storage);return result;
    }
    return (sint32)state<2?1u:3u;
}

uint32 ob_front_800962A4(uint32 card_state,uint32 card_status,uint32 disabled)
{
    FUNCTION_MARKER(0x800962A4u,"FRONT.BIN");
    uint32 storage=ob_draft_scratch_acquire(112u),second=storage+56u,format;
    w_u8(storage,r_u8(0x8008D420u));w_u8(storage+1u,r_u8(0x8008D421u));
    w_u8(second,r_u8(0x8008D420u));w_u8(second+1u,r_u8(0x8008D421u));
    ob_draft_unresolved_call(0x80063FD8u,3u,storage+2u,0u,48u);
    ob_draft_unresolved_call(0x80063FD8u,3u,second+2u,0u,48u);
    switch(card_state)
    {
    case 0xFFFFFFFFu:format=0x8008D424u;break;
    case 0u:format=ob_draft_unresolved_call(0x800541A8u,1u,0u)?0x8008D44Cu:0x8008D43Cu;break;
    case 1u:format=0x8008D45Cu;break;
    case 2u:format=0x8008D46Cu;break;
    case 3u:format=0x8008D47Cu;break;
    case 4u:format=ob_draft_unresolved_call(0x800541A8u,1u,4u)?0x8008D49Cu:0x8008D48Cu;break;
    case 5u:format=0x8008D4ACu;break;
    case 6u:format=0x8008D4BCu;break;
    case 7u:format=0x8008D4CCu;break;
    default:format=ob_native_missing_value(0x800962A4u,"Card state has no original format string");break;
    }
    ob_draft_unresolved_call(0x80064028u,2u,card_state==0xFFFFFFFFu?second:storage,format);
    if(card_state!=0xFFFFFFFFu)
    {
        switch(card_status)
        {
        case 0u:case 3u:ob_draft_unresolved_call(0x80064028u,4u,second,0x8008D4DCu,storage,0x8008D4E4u);break;
        case 1u:ob_draft_unresolved_call(0x80064028u,4u,second,0x8008D4DCu,storage,0x8008D4FCu);break;
        case 4u:ob_draft_unresolved_call(0x80064028u,4u,second,0x8008D4DCu,storage,0x8008D4F0u);break;
        case 2u:case 5u:ob_draft_unresolved_call(0x80064028u,2u,second,0x8008D508u);break;
        default:break;
        }
    }
    uint32 result=ob_front_8009465C(second,51u,disabled?45u:91u,disabled?40u:15u,disabled?22u:8u,0u);
    if(!disabled){result=card_state==0xFFFFFFFFu?0x8009BDE8u:0x8009BE7Cu;w_u32(0x8009BB94u,result);}
    ob_draft_scratch_release(storage);return result;
}

uint32 ob_front_80096550(uint32 action,uint32 card,uint32 choice,uint32 mode)
{
    FUNCTION_MARKER(0x80096550u,"FRONT.BIN");
    if(action>=23u)return 0u;
    uint32 result=ob_front_80095DF0(card,action==0u?(mode==1u?2u:1u):0u,choice);
    if(action==0u){if(mode==1u){result=0x8009BF10u;w_u32(0x8009BB94u,result);}return result;}
    if(action==4u||action==14u)return result;
    if(action<=3u)
    {
        uint32 heading=action==1u?0x8008D58Cu:action==2u?0x8008D5A0u:0x8008D568u;
        uint32 interactive=action==2u||mode==1u;
        ob_front_8009465C(heading,100u,interactive?91u:45u,interactive?15u:40u,interactive?8u:22u,0u);
        uint32 yes=interactive&&!choice,no=interactive&&choice;
        ob_front_80094488(0x8008D584u,162u,125u,yes?91u:45u,yes?15u:40u,yes?8u:22u,0u);
        result=ob_front_80094488(0x8008D588u,202u,125u,no?91u:45u,no?15u:40u,no?8u:22u,0u);
        if(interactive)
        {
            if(action==1u)result=choice?0x8009C038u:0x8009C0CCu;
            else if(action==2u)result=choice?0x8009C160u:0x8009C1F4u;
            else result=choice?0x8009C288u:0x8009C31Cu;
            w_u32(0x8009BB94u,result);
        }
        return result;
    }
    static const uint32 messages[23]={0u,0u,0u,0u,0u,0x8008D5A8u,0x8008D5B4u,0x8008D5C0u,0x8008D5FCu,0x8008D5DCu,0x8008D608u,0x8008D614u,0x8008D624u,0x8008D634u,0u,0x8008D64Cu,0x8008D664u,0x8008D680u,0x8008D698u,0x8008D6ACu,0x8008D6C4u,0x8008D6D4u,0x8008D6E4u};
    return ob_front_8009465C(messages[action],112u,91u,15u,8u,0u);
}

uint32 ob_front_800994B0(uint32 player,uint32 unused_a1,uint32 locked,uint32 selected)
{
    FUNCTION_MARKER(0x800994B0u,"FRONT.BIN");
    (void)unused_a1;
    uint32 text=ob_draft_scratch_acquire(8u),x=150u+player*40u;
    ob_draft_unresolved_call(0x80064028u,3u,text,0x8008D968u,player+1u);
    uint32 heading_selected=!locked&&selected==0xFFFFFFFFu;
    ob_front_80094488(text,x,42u,heading_selected?91u:45u,heading_selected?15u:40u,heading_selected?8u:22u,locked?1u:0u);
    for(uint32 i=0u;i<9u;++i)
    {
        uint32 active=!locked&&selected==i;
        ob_front_80093BB4(r_u32(0x8009CF58u+(player*9u+i)*4u),x,61u+i*16u,active,locked?1u:active&&r_u32(0x8009D028u+player*4u)==3u);
    }
    uint32 result=ob_front_80093E70(0x8009C4D8u);ob_draft_scratch_release(text);return result;
}

uint32 ob_front_8008F7F0(uint32 menu,uint32 item)
{
    FUNCTION_MARKER(0x8008F7F0u,"FRONT.BIN");
    static const uint32 selected_geometry[14][3]={
        {64u,169u,63u},{64u,201u,65u},{64u,233u,70u},{16u,201u,129u},{32u,158u,108u},
        {32u,138u,112u},{32u,140u,100u},{32u,144u,94u},{32u,174u,114u},{32u,152u,120u},
        {32u,158u,100u},{32u,134u,123u},{32u,140u,106u},{32u,144u,84u}};
    static const uint32 idle_geometry[9][2]={{136u,112u},{140u,100u},{140u,90u},{175u,115u},{150u,120u},{156u,100u},{134u,123u},{136u,106u},{146u,86u}};
    uint32 volume=r_u32(item+8u);
    if(r_u32(menu+12u)==item)
    {
        if(volume<10u)
            for(uint32 i=0u;i<5u+volume;++i)
                sub_80021460(0x8006B32Cu+i*4u,0u,0u,32u,selected_geometry[i][0],selected_geometry[i][1],selected_geometry[i][2],0u);
        return ob_front_8008E65C(20u,0x8008D100u,0x8008D104u);
    }
    if(volume>=10u)return 0u;
    /* The zero-volume jump leaves the original epilogue address in the return carrier */
    uint32 result=0x80091250u;
    for(uint32 i=0u;i<volume;++i)
        result=sub_80021460(0x8006B364u+i*4u,0u,0u,32u,32u,idle_geometry[i][0],idle_geometry[i][1],0u);
    return result;
}

