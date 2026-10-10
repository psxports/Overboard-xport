# Overboard!

Resolve `[XPORT_ROOT]` from `xport-project.json` and read `[XPORT_ROOT]/AGENTS.md`. Keep only stable game-specific facts and task-routing links here; put detailed evidence under `status`. Never create, edit, move, delete or regenerate `README.md`.

## Project facts

- Native short name: `OB`; native implementation language: C; original source language: undetermined
- Solution: `src/platform/win/OB.sln`; Debug executable: `bin/OB_debug.exe`; Release executable: `bin/OB.exe`; working directory: `bin`; intermediates: `_build`
- Runtime data: `bin/DATA`; Red Book output when applicable: `bin/MUSIC`
- Reviewed executable: `orig/SLES_008.65`, SHA-256 `736baeebf50f5d77d0d64400ed6c60b6452b6df3bae48ebe1703c76c865e8904`, loaded at `0x80010000`, entry `0x8005F998`, runtime GP `0x80076874` from the executable's `lui/addiu` initializer
- Disc: `iso/Overboard! (Europe).cue`; `orig/SYSTEM.CNF` selects `SLES_008.65`; track 01 is MODE2/2352 and later tracks are Red Book audio
- Dummy scope: user permits stubs for unimplemented BIOS/SDK calls in the xport toolset; preserve unresolved game behavior as TODO; authorization and recording BIOS identity: `status/audits/first/bios-sdk-stub-authorization.json`
- Lockstep record role: `user` on port 2412; comparison role: `lockstep` on port 2413; exact memory sizes and adapter settings are in `xport-project.json`
- Reviewed startup evidence: `status/startup.json`, `status/ghidra/classification.json`, `status/translation-ledger.json`, and `status/audits/`; no project-specific hooks or memory layouts have been reviewed yet
