# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

Game & Watch Simulators: a C++ engine (SDL 1.2) that simulates Game & Watch-style LCD handhelds, originally ported from the Madrigal Delphi simulators. The simulation aims to match the real hardware: on/off, ACL, time modes, and so on. Alarm and chrono modes only show default data. It targets desktop SDL plus handhelds and mobile: GP2X, Wiz, Pandora, Symbian S60/UIQ3, Android and iOS.

## Build

The desktop build uses CMake (the only build system for desktop; old autotools files were removed). It needs SDL 1.2 with SDL_image, SDL_mixer, SDL_ttf and SDL_gfx, plus zlib and zziplib. Custom find modules are in `cmake/modules/`.

```sh
mkdir -p build && cd build
cmake ..                          # add -DWITH_DEVELDEVICES=ON to include unfinished games
make
./bin/gameandwatch -d ../data     # -d / --data-path sets the data directory (default: "data")
```

There are no tests and no lint setup. The build uses `-Wall`.

Each non-desktop platform has its own build files, and each keeps its **own copy of the source file list**:
- `src/CMakeLists.txt` (desktop, and the Android/iOS library build via the `ANDROID`/`IOS` CMake vars)
- `android/jni/src/Android.mk` (ndk-build; SDL 1.3 sources go in `android/jni/SDL`)
- `ios/gamewatch/gamewatch.xcodeproj`
- `symbian/{s60v3,uiq3}/gamewatch.mmp`
- `.cproject` (Eclipse CDT)

When you add or remove a source file, update every list that should include it.

## Architecture

Headers are in `include/` and implementations in `src/`, with the same layout (`devices/`, `plat/`, `util/`).

- **Platform abstraction** (`include/platform.h`): `GW_Platform` is an abstract interface for drawing, text, sound, image/sound loading, time and input events. Input is translated into abstract `GPK_*` keys. `plat/plat_sdl.cpp` is the base SDL implementation. The other `plat_*.cpp` files subclass it for specific handhelds and change key mappings and screen size. `gamewatch.cpp` (`main`) picks the platform class at compile time with defines such as `GP2X`, `GW_PLAT_PANDORA`, `GW_PLAT_S60`, `GW_PLAT_WIZ`, `GW_PLAT_ANDROID` and `GW_PLAT_IOS`.
- **Menu / game list**: `GW_GameList` (`gamelist.cpp`) registers one `GW_Game_Info` per game. `GW_Menu` shows the list and runs the selected game through `GW_Device`.
- **Device / game core** (`include/device.h`, `src/device.cpp`):
  - `GW_Device` runs the main loop. It pumps platform events, calls `GW_Game::Update()`, and redraws only when the game reports a change (`CheckChanged`). It also handles background panning/centering, zoom modes and volume.
  - `GW_Game` is the base class for a simulated unit. It has on/off state and modes, and virtual hooks `do_turnon`, `do_turnoff`, `do_setmode`, `do_timer`, `do_update` and `do_gametype_get`.
  - `GW_GameData` holds all of a game's assets and state, keyed by integer IDs plus an index: images, **positions** (LCD segments, each with x/y, an image, visibility and a status), sounds and timers. Games build this declaratively with chained calls such as `data().position_add(...)->timer_add(...)`. Rendering draws the visible positions over the background image.
- **Game engines vs. devices** (`src/devices/`):
  - `deveng_*` files are reusable engines for a family of hardware. `GW_GameEngine_VTech` implements the shared VTech behaviour: modes (idle/demo/game A/B/time/alarm/chrono/date), clock, score and miss display, and the standard timers (`TMR_*`). `deveng_vtech_monkey`, `deveng_vtech_condor` and `deveng_vtech_banana` build on it for specific game layouts.
  - `dev_*` files are the concrete games. A device is usually a `GW_Game_Info` subclass (id, description, data dir, background image, transparent color) with `create()`, plus a game class that subclasses an engine. The game class mostly just overrides segment coordinates with `position_change(...)` (see `dev_pirate.cpp`).
  - Unfinished games (`banana`, `sleepwlk`, `dkong`) are compiled only with `WITH_DEVELDEVICES` / `GW_DEVEL_DEVICE`.
- **Adding a game**: write `include/devices/dev_X.h` and `src/devices/dev_X.cpp`, register it in `GW_GameList::load()`, add the files to the build lists above, and provide `data/X.zip`.

## Data

Each game's assets are in `data/<id>.zip`, containing `image/*.bmp` and `sound/*.wav`. The desktop build defines `GW_USE_ZDATA`, so assets are loaded through zziplib (`SDL_RWFromZZIP`). A path like `data/pirate/image/bg.bmp` resolves transparently inside `data/pirate.zip`. Shared platform data, such as the font, is in `data/gamewatch/`. Images use a color key for transparency (magenta 255,0,255 for most games), which is set per game in its `GW_Game_Info`.

## Default desktop keys

In the menu, the arrow keys move and Enter selects. In a game: Enter turns on, Backspace turns off, Esc exits, 1 is Game A, 2 is Game B, 3 is Time, the arrow keys move, and +/- change the volume. Keys for other platforms are listed in `doc/README.<platform>`.
