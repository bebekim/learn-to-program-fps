# One build/run workflow for all lectures

An adult verifies the compiler and configures Geany before the lesson. These examples
use only the C++17 standard library. No raylib download, CMake, assets, Windows console
engine header, or network connection is needed.

## Keep student work

Keep one active working folder and save a named copy before loading the next starter.
Never overwrite Nathan's edited source to make it look like a target. The lecture
starters introduce supplied infrastructure as needed; they are not a claim that the
student independently built that infrastructure. From 12 onward the text maze
combines earlier ideas. From 15 onward the examples are isolated depth labs.

## Windows with the existing Visual Studio compiler

Open Developer PowerShell for VS 2022, enter the active working folder, and run:

```powershell
cl /nologo /EHsc /std:c++17 /W4 starter.cpp /Fe:maze.exe
if ($LASTEXITCODE -eq 0) { .\maze.exe }
```

If an adult instead already uses a verified g++ installation:

```powershell
g++ -std=c++17 -Wall -Wextra -Wpedantic starter.cpp -o maze.exe
if ($LASTEXITCODE -eq 0) { .\maze.exe }
```

Choose one compiler; do not install a second just for these notes.
For comparison, build target.cpp to a different executable name.
Typing input normally requires Enter. q exits the interactive games. The supplied
EOF checks also stop safely when no input remains.

## Adult Mac reference

From any lecture directory:

```sh
c++ -std=c++17 -Wall -Wextra -Wpedantic starter.cpp -o /tmp/nathan-lecture
```

After the compile succeeds:

```sh
/tmp/nathan-lecture
```

Recompile after source changes. A failed compile can leave an older executable
behind; never use its output as evidence that the new source compiled.

## Verify the provided checkpoints

From the repository root, with Node and a c++ compiler available:

```sh
node lectures/verify-checkpoints.mjs
```

This compiles both sources per lecture, runs them with bounded scripted input, and
checks selected expected results and cross-checkpoint behaviour. It does not validate
Geany's configuration, Windows installation, a raylib window, or independent student
solutions. Binaries are built in a fresh temporary directory, not among student files.
