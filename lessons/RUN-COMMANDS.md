# Console command reference — after lesson 00

**For:** anyone returning to a later lesson who needs the commands again.
**When:** after the computer is configured and lesson 00 has been completed.
This page is a quick reference, not a separate lesson or installation guide.

- **Adult preparation, once:** [lesson 00 ADULT-SETUP.md](00-compile-and-run/ADULT-SETUP.md) installs/configures the compiler and Geany.
- **Nathan's actual first lesson:** [lesson 00 LESSON.md](00-compile-and-run/LESSON.md) teaches compiling and running, with charts and command explanations.
- **Later sessions:** use the command reminders below; no repeated installation is needed.

Start with [lesson 00](00-compile-and-run/LESSON.md), which uses hello.cpp.
The same workflow then applies to lessons 01–24, which use starter.cpp. Their examples use the C++17 standard
library; raylib, CMake and assets are not required. Internet is needed to install
the toolchain initially, but these console examples build offline afterwards.

## Each time you work

1. Keep a named copy of Nathan's previous work.
2. Open the intended starter.cpp in Geany, or continue his active working file.
3. Open a terminal **in that source file's directory**.
4. Save, build, and run only if the build succeeds.
5. Compare the output with the prediction and save the learning change.

Do not overwrite his edited program with target.cpp. The comparison target is an
adult aid, not an instruction to copy a solution.

### Mac — Terminal

```sh
clang++ -std=c++17 -Wall -Wextra -Wpedantic starter.cpp -o maze && ./maze
```

### Windows GCC — PowerShell, after MSYS2 setup

```powershell
g++ -std=c++17 -Wall -Wextra -Wpedantic starter.cpp -o maze.exe
if ($LASTEXITCODE -eq 0) { .\maze.exe }
```

### Windows MSVC — Developer PowerShell

```powershell
cl /nologo /EHsc /std:c++17 /W4 starter.cpp /Fe:maze.exe
if ($LASTEXITCODE -eq 0) { .\maze.exe }
```

For a target comparison, change starter.cpp to target.cpp and use a different output
name. Later interactive examples usually need Enter after a command; q exits the
maze games. A failed build can leave an older executable behind.

## Diagrams

For the adult's Emacs-to-browser workflow, use
[the Mermaid preview setup](../docs/emacs-markdown-preview.md). Browser diagram
rendering loads Mermaid online; this is separate from compiling a C++ program.

## Adult batch verification

Node is optional and is not needed to compile a lesson. With Node and a C++ compiler
available, run from the **repository root**:

```sh
node lessons/verify-checkpoints.mjs
```

The verifier uses the c++ command by default. On a machine where only g++ is on PATH,
select it before running. In PowerShell:

```powershell
$env:CXX = "g++"
node lessons/verify-checkpoints.mjs
```

CXX must name a GCC/Clang-compatible driver; this verifier does not use MSVC's cl flags.
It builds lesson 00's greeting plus the 48 supplied checkpoints in a fresh temporary directory, runs bounded
scripted input and checks selected expected results. It does not validate Geany,
Windows installation, graphics or student understanding. Lesson 25 uses the separate
[raylib setup](../docs/ADULT-RAYLIB-SETUP.md).
