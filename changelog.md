# ZMenu7 changelog

## v1.0.0-beta.4
**Geometry Dash v2.2074 support**

No Android support yet; work is ongoing.

**Fixes**
* Fixed radio button keybinds always selecting the first option.
* Fixed random crashes involving combo boxes.
* Fixed several Slider Limit issues.
* Fixed a rare crash caused by an invalid UI renderer mode.
* Fixed issues with Instant Complete and Mute Level Audio On Death.
* Fixed keyboard shortcuts (Ctrl+C, Ctrl+V, etc.) not working in the UI.
* Fixed keybind deletion crashes.
* Fixed crashes involving Platformer modes, Practice Coins, and Show Trajectory.
* Fixed Frame Stepper conflicts with Speedhack.
* Start Position Switcher keybinds now trigger instantly.
* Practice Music Sync now toggles the corresponding setting automatically.
* Replay no longer triggers Auto Safe Mode unless a macro is loaded.
* Added mod descriptions.

**Additions**
* Added optional Death Markers that show where player deaths occurred; markers clear when restarting or leaving a level.
* Added No Trail, Always Show Trail, and Discord RPC.
* Added a Show In Editor option to Show Hitboxes.
* Replaced TPS Bypass with Physics Bypass.
* Added Place Checkpoint and Remove Checkpoint shortcuts.
* Added custom keybinds for P1/P2 jump.
* Added Endscreen Cheat Indicator.
* Auto Safe Mode now stores whether cheats were active during an attempt.
* Added a Click Between Frames toggle when the corresponding mod is installed.
* Added new label variables: `isDualMode`, `cubeIcon`, `shipIcon`, `ballIcon`, `ufoIcon`, `waveIcon`, `robotIcon`, `spiderIcon`, `swingIcon`, `gamemode`, `playerIcon`, `levelDescription`, `frameReal`, `tps`, and `runStart`.
* Expanded RIFT scripting with configuration access, improved stability, type-conversion helpers, duration formatting, and sub-expression evaluation.
* Added the ZMenu7 API for developers who want to interact with the mod.

## v1.0.0-beta.3
**Fixes**
* Fixed Pause Countdown timing.
* Fixed Noclip Deaths.
* Fixed Respawn Delay keybind registration.
* Moved Copy Bypass and Verify Bypass to the Creator tab.
* Fixed several label parser issues.

**Additions**
* Added 0% Practice Completion, No Mirror, Instant Mirror, No Object Glow, and Level Uncomplete Shortcut.
* Labels can now be reordered.
* Macros can now be deleted from the menu.

## v1.0.0-beta.2
**Fixes**
* Fixed Force Platformer in online levels.
* Fixed the invisible interface tab in Panel layout.
* Fixed immediate font-size changes.
* Fixed the Sidebar layout window size.
* Fixed Smart Start Position on macOS.
* Fixed crashes caused by corrupted theme files.

**Additions**
* Added Solid Wave Trail, Custom Wave Trail, and Stop Triggers on Death.
* Added Noclip Death and Accuracy limits.
* Keybinds no longer activate while typing in a Geometry Dash text box.
* Added a hint for creating keybinds.
* Click Between Frames is automatically disabled while using the bot.
* Added label variables: `framestepper`, `monthName`, and `lastDeath`.

## v1.0.0-beta.1
* Initial release.
