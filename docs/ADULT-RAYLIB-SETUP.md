# raylib target-range setup

This is the graphical project used by [lesson 25](../lessons/25-raylib-scorekeeper/LESSON.md).
For lessons 01–24, use the simpler [console setup](../lessons/RUN-COMMANDS.md); CMake and raylib are not needed.
Run these graphical build commands from the repository root, not from a lesson folder.

## Setup and play — Nathan’s Windows PC

Windows is Nathan’s learning platform. The macOS section below is for the adult’s
reference machine. A successful Mac build does not validate the Windows setup.

Requirements: Git, CMake 3.24+, a C++17 compiler, and a desktop with OpenGL support.
The first configure downloads raylib **5.5** from its official repository; internet
access is required. This is a deliberate fixed baseline, not a claim of latest release.
No asset downloads or paid tools are needed.

### Windows — start here

An adult should do the initial installation:

1. Install Git for Windows and CMake 3.24 or newer. Enable CMake’s option to add it
   to PATH, then open a new terminal.
2. Install Visual Studio 2022 Community (the editor) or Build Tools 2022 with the
   **Desktop development with C++** workload, MSVC v143 compiler, and Windows SDK.
   If Visual Studio offers GitHub Copilot, leave it disabled for student work.
3. Copy the whole project folder to Nathan’s PC, for example
   `C:\Users\Nathan\source\learn-to-program-fps`. The Mac `/Users/...` path is
   not a Windows path. Do not copy Mac build folders.
4. Open **Developer PowerShell for VS 2022**, then enter the actual folder location:

```powershell
cd "$HOME\source\learn-to-program-fps"
```

If the folder is elsewhere, use that location instead. From the project folder:

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Debug --parallel
ctest --test-dir build -C Debug --output-on-failure
.\build\Debug\nathan_fps.exe
```

After editing source files, repeat the build, test, and run commands; configure
again only when the project setup changes. You can use Visual Studio’s **Open a
local folder** to edit this folder. Keep AI completion and generated-code tools
disabled; compiler diagnostics and ordinary IntelliSense are fine.

Windows startup check:

```powershell
.\build\Debug\nathan_fps.exe --smoke-test
```

It should open briefly and close normally. Then run without `--smoke-test` and
check movement, mouse aim, hits and misses, R reset, Tab pause, and Escape exit.
This Windows check remains to be done on Nathan’s PC.

WASD walks, mouse aims, left click shoots the orange spheres. Hit each target once
to finish. R resets; Tab pauses and releases the mouse; Escape exits. There is no
jumping, enemy AI, wall physics, or weapon simulation yet. The movement boundary
keeps you on the floor. Targets disappear when hit; misses do not change the score.

For a graphics-free rules check (also useful offline):

```powershell
cmake -S . -B build-rules -G "Visual Studio 17 2022" -A x64 -DBUILD_GAME=OFF
cmake --build build-rules --config Debug
ctest --test-dir build-rules -C Debug --output-on-failure
```

`nathan_fps --smoke-test` opens a window, draws three frames, then exits; it checks
startup/rendering only. It still needs a desktop session. If downloads fail, check
network access and Git. If CMake cannot find a compiler, finish the platform setup
above. Keep distinct build folders for different generators or platforms.

### macOS — optional adult reference

Install Apple's Command Line Tools with `xcode-select --install`. Install CMake and
Git (for example `brew install cmake git` if Homebrew is already installed).
In Terminal, enter this project folder, then:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
./build/nathan_fps
```
