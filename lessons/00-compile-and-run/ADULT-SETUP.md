# ADULT SETUP — Adult preparation before lesson 00

**For:** the parent or instructor. **When:** once on each computer, or when repairing
its tools. **Purpose:** install/configure the compiler and Geany so the lesson can begin.

**Nathan's lesson is [LESSON.md](LESSON.md).** That file contains the teaching charts,
explanations of the build command, learner exercises and understanding checks.
Do not teach this installation checklist as lesson 00.

| File | Who uses it? | What to do |
| --- | --- | --- |
| ADULT-SETUP.md — this file | Adult, before the session | Install, configure and verify tools |
| [LESSON.md](LESSON.md) | Nathan with an adult, during the session | Learn what building/running means and follow the exercises |

## 1. Prepare the computer

Use Apple's Clang on the adult Mac. On Nathan's ordinary x64 Windows PC, use GCC
through MSYS2, unless MSVC is already working. Install one toolchain, not all three.
Geany edits code; it does not establish that a compiler and its libraries are installed.
The selected toolchain supplies those compiler tools, headers and libraries.

Geany is already installed. CMake and raylib are not needed for this console lesson.
Git, Node and a debugger are not prerequisites for Nathan's first build.

Ensure the course folder and its lesson files are present on the computer:

- Mac course location: `~/repositories/edu/learn-to-program-fps`.
- Example Windows copy: `C:\Users\Nathan\source\learn-to-program-fps`.
- First source file: `lessons/00-compile-and-run/hello.cpp`.

Adjust the Windows path to its actual location. Preserve any existing student work.

## 2. Mac — install and verify Clang

### Install once

Open **Terminal**. Check first:

```sh
clang++ --version
xcode-select -p
```

If these report a compiler and developer directory, keep the existing installation.
If the tools are missing, request Apple's Command Line Tools installer:

```sh
xcode-select --install
```

Complete the graphical installer before continuing. Then open a new Terminal and
repeat the two verification commands. Full Xcode is not needed for this console
lesson; an existing working Xcode installation is also fine.

An “install requested” message means the installer was requested, not that the
compiler installation has finished.

## 3. Windows — install and verify g++ through MSYS2

These steps assume an ordinary **64-bit Intel/AMD Windows PC**. For a Windows ARM
machine, choose a matching toolchain rather than blindly using the x86_64 package.

### Install once

1. Download MSYS2 from [the official site](https://www.msys2.org/).
2. Run its x86_64 installer. The instructions below assume the default location,
   `C:\msys64`.
3. Open **MSYS2 UCRT64** from Start. Use this terminal for package installation,
   not ordinary PowerShell and not the plain MSYS terminal.
4. Update MSYS2:

```sh
pacman -Syu
```

Accept the prompts. If the update asks you to close the terminal, let it finish,
reopen **MSYS2 UCRT64**, and run the update again until it completes.

5. In **MSYS2 UCRT64**, install the compiler:

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-gcc
```

This installs GCC's C/C++ compiler and the required package dependencies, including
its standard-library support. Accept the installation prompt.

6. Verify in that same terminal:

```sh
g++ --version
```

It should identify GCC. If the command is missing, check the package installation
and that the terminal says UCRT64.

### Make the compiler available to PowerShell and Geany

1. Search Windows Start for **Edit environment variables for your account**.
2. Under **User variables**, select **Path** and choose **Edit**.
3. Add a **new entry**; do not replace or delete the existing entries:

```text
C:\msys64\ucrt64\bin
```

4. Confirm the dialogs. Close and reopen PowerShell and Geany so that they inherit
   the changed environment.
5. In a fresh **PowerShell**, verify:

```powershell
g++ --version
where.exe g++
```

The location should include `C:\msys64\ucrt64\bin\g++.exe`.
If another compiler appears first, use the explicit compiler path while resolving
the PATH selection. Do not copy compiler DLLs from random download sites.

## 4. Windows alternative — existing MSVC compiler

If Visual Studio or its Build Tools already has a working C++ toolchain, use it;
GCC is not mandatory. To install MSVC, use Microsoft's
[Build Tools installation instructions](https://learn.microsoft.com/en-us/cpp/build/building-on-the-command-line)
and select **Desktop development with C++**, with an x64 MSVC toolset and Windows SDK.

Open the installation's **Developer PowerShell** shortcut; it configures the headers,
libraries and compiler environment. A plain terminal with only cl.exe added to PATH
is not an equivalent setup.

Verify the selected terminal can find the compiler:

```powershell
Get-Command cl
```

The learner's build and run commands are in [LESSON.md, section 4](LESSON.md#4-build-then-run).

Keep editing in Geany and building in Developer PowerShell initially. Configuring
Geany to launch MSVC needs that same developer environment; the GCC build-button
configuration below is not for MSVC.

## 5. Optional one-time Geany configuration

After the readiness check below succeeds, configure the editor if you want its
Build button. This is adult tool configuration. Nathan's terminal-based build/run
lesson remains in LESSON.md.

Open hello.cpp in Geany. Choose **Build → Set Build Commands** for the C++ file type.
Configure the **Build** command (not only the compile-object command).

**Windows with GCC on PATH:**

```text
g++ -std=c++17 -Wall -Wextra -Wpedantic "%f" -o "%e.exe"
```

Use the source directory as the working directory (Geany's %d placeholder where
the dialog offers a working-directory field). The executable for hello.cpp is
then hello.exe. Run it from PowerShell as .\hello.exe after a successful build.

**Mac with Clang:**

```text
clang++ -std=c++17 -Wall -Wextra -Wpedantic "%f" -o "%e"
```

From the source directory, run ./hello in Terminal. Here %f is the current
filename and %e is that filename without its extension. Save before building.
Use the Build menu first; shortcuts depend on the configured key bindings.

These settings produce hello or hello.exe for hello.cpp, matching lesson 00's
terminal examples. Later filenames use their own base names.

## 6. Adult readiness check and handoff

This is an installation check, not a second copy of the lesson.

1. Confirm the chosen compiler's verification command works in the intended terminal.
2. Open hello.cpp in Geany and confirm it is editable.
3. Once, follow [LESSON.md, sections 3–4](LESSON.md#3-find-the-source-file-in-a-terminal)
   to locate, build and run the supplied program. Expected output: `Hello, maze explorer!`.
4. If using Geany's Build button, confirm it invokes the intended compiler and produces
   the expected executable. The terminal commands remain the fallback.
5. **Stop using this file. Open [LESSON.md](LESSON.md) with Nathan and begin lesson 00.**

After setup succeeds, Nathan does not need to repeat installation or read this file
during normal lessons. Return here only for configuration changes or tool failures.
Command explanations and the learner's prediction/build/run activities live in LESSON.md.

## 7. Troubleshooting — adult reference

| Symptom | Check |
| --- | --- |
| clang++ asks to install developer tools | Finish Apple's installer before trying the build again |
| g++ or cl is not recognised | Verify installation and the selected terminal/PATH; restart terminals after PATH changes |
| hello.cpp: no such file | Check current directory and that the filename is not hello.cpp.txt |
| iostream cannot be found | Check the complete C++ toolchain; with MSVC use Developer PowerShell, not a manually added cl.exe |
| “undefined reference” or linker errors from a simple iostream program | Use the C++ driver g++/clang++, not the C driver gcc/clang |
| Runtime DLL missing on Windows | Keep MSYS2's ucrt64 bin directory on PATH when running; don't move just the executable to another machine yet |
| Program still shows an old message | Save, rebuild, and run the correct executable; an old binary can remain after a failed build |
| Window closes after printing | Run it from an already-open terminal; this first program is supposed to exit |
| Cannot overwrite hello.exe | Stop the old running copy and rebuild |

## Sources and verification

- [Apple: installing the command-line tools](https://developer.apple.com/documentation/xcode/installing-the-command-line-tools)
- [MSYS2: installation and GCC package](https://www.msys2.org/)
- [MSYS2: updating the system](https://www.msys2.org/docs/updating/)
- [Microsoft: C++ command-line tools](https://learn.microsoft.com/en-us/cpp/build/building-on-the-command-line)
- [Geany manual](https://www.geany.org/manual/current/index.html)

The Mac compiler is already present on the reference machine. The lesson's Clang
build/run commands can be checked there. That does not validate installation or
Geany configuration on Nathan's Windows computer.

