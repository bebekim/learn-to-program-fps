# Nathan's C++ FPS workshop

## Start here: CLI foundations

The current teaching entry point is [the structured lecture sequence](lectures/README.md),
starting with [01 — Run, change, run again](lectures/01-first-program/README.md).
Read the [instructor guide](lectures/00-instructor-guide.md) for preparation and
mastery checks. Nathan starts with no assumed programming knowledge.

The first pass builds a turn-based text maze: represent the world as data, apply
precise rules to input, and predict/check the resulting state. After lecture 14,
revisit those rules with raylib presentation and then continuous time. Console
ray casting is an optional deeper track, not a requirement before raylib.

All 24 lecture notes include worked explanations, exercises, instructor answers,
and runnable starter/comparison C++ programs. Lectures 01–14 lead to the text maze;
15–24 are isolated deeper labs rather than an integrated FPS. The existing raylib
target range below is preserved for the later pass; its scorekeeper lesson is not
the beginner entry point.

Build a game you can explain. The later raylib pass starts with a tiny first-person
target range, then adds features by designing data and functions, testing examples,
and improving code.
No previous C++ is assumed. Work in short sessions with an adult nearby for setup.

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

## Where things live

- `src/main.cpp`: teacher-provided window, input, rendering, and target-range scaffold.
- `include/game_rules.hpp`: data definition and scoring contract.
- `src/game_rules.cpp`: small pure rule to read and change first.
- `tests/rules_tests.cpp`: executable checks, including score boundaries.
- `lessons/01-scorekeeper.md`: later raylib task; begin the CLI lectures first.
- `docs/roadmap.md`: later projects and mastery checks, not prebuilt solutions.
- `notes/journal.md`: Nathan's predictions, evidence, and questions.

## How we work

Turn off AI autocomplete and generated-code chat in the student editor. Ordinary
syntax highlighting, compiler errors, and documentation lookup are fine. Nathan
writes the code and explains it. An adult may handle installation and ask questions;
do not paste a solution into the student's task. This initial scaffold is supplied
infrastructure, not evidence that Nathan has learned its contents.

For every change: define the data → write a signature, purpose and contract → make
concrete input/output examples → sketch a template from the data → implement →
run tests and play → refactor with behavior unchanged → explain the result.
A contract says which inputs are allowed and what the result promises. An invariant
is something that stays true through every valid update. This is an adaptation of
the HtDP design recipe to C++, not a replacement for learning C++ lifetimes and types.

## Git save points

An adult can initialize the empty project with `git init`. Check `git status`, then
save the supplied starter with `git add .` and `git commit -m "Start playable target range"`.
Set Git name/email if prompted. Nothing is published automatically.
Before each experiment, begin from a tested save point. After a successful change,
review `git diff`, stage only intended files, and commit a small explanation such as
`git commit -m "Add and test remaining target rule"`. Keep failures in your journal;
use `git diff` to understand them before undoing anything. Never erase work just to
make the tests green.

## References and engine choice

[raylib](https://github.com/raysan5/raylib) supplies graphics and input while leaving
our C++ data and rules visible. Its [examples](https://www.raylib.com/examples.html)
are API references; explain borrowed ideas rather than copying a whole game.
[HtDP](https://htdp.org/) supplies the design-recipe inspiration.
[LimonEngine](https://github.com/enginmanap/limonEngine) is a later reading and
comparison project: study how a larger FPS engine organizes responsibilities once
our own small program is understandable. It is not a build dependency. No claim is
made here about its current platform support; investigate that during the comparison.
