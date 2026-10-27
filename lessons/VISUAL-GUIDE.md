# Visual C++ primer

**Lesson 00:** [Compile and run](00-compile-and-run/LESSON.md) uses these charts to teach the first build. Use sections 1–2 to picture how a program is built. Point, predict, then run. Revisit section 3 after functions; the remaining sections are visual reminders for later lessons, not one long first lesson.

Continue with [the structured course](COURSE-INDEX.md). The text maze is the first stepping stone toward CommandLineFPS, then the Javidx9 upgrade, raylib, and Unreal. [See the destinations](START-HERE.md).

These Terminal examples are for the adult’s Mac. Use [adult compiler setup](00-compile-and-run/ADULT-SETUP.md) for Nathan’s Windows compiler. The diagram ideas apply on both platforms.

**Reading key:** Diagrams explain; follow the arrows. **C++ CODE** goes in a `.cpp` file. **TERMINAL** commands go in Terminal.

## 1. Give the computer instructions

C++ is a language for writing instructions.

**DIAGRAM — Write, build, and run**

```mermaid
flowchart LR
    A["WRITE<br/>hello.cpp<br/>Your instructions"] -->|BUILD| B["hello<br/>Finished program"]
    B -->|RUN| C["Screen<br/>Hello!"]
```

Save this as **hello.cpp**:

**C++ CODE — type in your source file**

```cpp
#include <iostream>

int main() {
    std::cout << "Hello!\n";
    return 0;
}
```

**DIAGRAM — Parts of your first program**

```mermaid
flowchart LR
    A["#include &lt;iostream&gt;"] --> B["Get the tools for printing"]
    C["int main()"] --> D["Start here"]
    E["std::cout"] --> F["Send text to the screen"]
    G["Backslash + n"] --> H["Start a new line"]
    I["return 0;"] --> J["Finish successfully"]
    K["Semicolon ;"] --> L["End an instruction"]
```

In Terminal, inside the folder containing your file:

**TERMINAL — type these commands in Terminal**

```sh
clang++ hello.cpp -o hello
./hello
```

**DIAGRAM — Reading a Terminal command**

```mermaid
flowchart TD
    A["clang++ hello.cpp -o hello"] --> B["clang++<br/>Use the C++ build tools"]
    A --> C["hello.cpp<br/>Read this source file"]
    A --> D["-o hello<br/>Name the finished program"]
    E["./hello"] --> F["Run the program in this folder"]
```

**Try it:** Change `Hello!` to your name. Build again, then run.

*Adult setup help: if the Mac has no compiler, run `xcode-select --install` and finish the installer.*

## 2. What is an object file?

Think of building a toy car:

**DIAGRAM — Building a toy car**

```mermaid
flowchart LR
    A["Wheel drawing"] --> B["Built wheels"]
    C["Body drawing"] --> D["Built body"]
    B --> E["Join the pieces"]
    D --> E
    E --> F["Finished toy car"]
```

A program is built in pieces too:

**DIAGRAM — Compiling and linking a program**

```mermaid
flowchart TD
    A["main.cpp<br/>Instructions"] -->|COMPILE| B["main.o<br/>Compiled piece"]
    C["move.cpp<br/>Instructions"] -->|COMPILE| D["move.o<br/>Compiled piece"]
    B --> E["LINK<br/>Connect the pieces"]
    D --> E
    F["Library code<br/>Ready-made tools"] --> E
    E --> G["game<br/>Runnable program"]
```

**Compile:** translate C++ into machine-code pieces.  
**Object file (`.o`):** a compiled piece, usually not runnable by itself.  
**Link:** connect the pieces and required library code into a program.

An object file also keeps a list of what it provides and what it needs.

**DIAGRAM — Connecting a function call**

```mermaid
flowchart LR
    A["main.o<br/>I need move()"] -->|LINKER CONNECTS| B["move.o<br/>I provide move()"]
```

### Build your greeting in two steps

**TERMINAL — type these commands in Terminal**

```sh
clang++ -c hello.cpp -o hello.o
clang++ hello.o -o hello
./hello
```

**DIAGRAM — Compile, link, and run**

```mermaid
flowchart LR
    A["hello.cpp<br/>Source file"] -->|"1. COMPILE (-c)"| B["hello.o<br/>Object file"]
    B -->|"2. LINK"| C["hello<br/>Executable"]
    C -->|"3. RUN"| D["Hello!"]
```

**Point to it:** Which file is a piece? Which file can you run?

## 3. Watch the linker connect two pieces

Make these two files in the same folder.

**main.cpp**

**C++ CODE — type in your source file**

```cpp
#include <iostream>

int move(int position); // Promise: this function exists somewhere.

int main() {
    std::cout << move(2) << "\n";
    return 0;
}
```

**move.cpp**

**C++ CODE — type in your source file**

```cpp
int move(int position) {
    return position + 1;
}
```

**DIAGRAM — Connecting two source files**

```mermaid
flowchart TD
    A["main.cpp<br/>Call move(2)"] -->|COMPILE| B["main.o"]
    C["move.cpp<br/>Add 1"] -->|COMPILE| D["move.o"]
    B --> E["LINK"]
    D --> E
    E --> F["game"]
    F -->|RUN| G["Screen shows 3"]
```

**TERMINAL — type these commands in Terminal**

```sh
clang++ -c main.cpp -o main.o
clang++ -c move.cpp -o move.o
clang++ main.o move.o -o game
./game
```

**Break it on purpose:** Leave out `move.o`:

**TERMINAL — type these commands in Terminal**

```sh
clang++ main.o -o broken-game
```

**DIAGRAM — A missing piece causes a link error**

```mermaid
flowchart LR
    A["main.o<br/>Where is move()?"] --> B{"Is move.o included?"}
    B -->|No| C["LINK ERROR<br/>Missing piece!"]
    B -->|Yes| D["Link succeeds"]
```

**Fix it:** Link both object files again.

## 4. Variables are labeled boxes

A variable stores a value. Its type says what kind.

**C++ CODE — type in your source file**

```cpp
int health = 100;
double x = 2.5;
bool playing = true;
char wall = '#';
```

**DIAGRAM — Variables store values**

```mermaid
flowchart LR
    A["int<br/>Whole number"] --> B["health<br/>100"]
    C["double<br/>Decimal number"] --> D["x<br/>2.5"]
    E["bool<br/>True or false"] --> F["playing<br/>true"]
    G["char<br/>One character"] --> H["wall<br/>#"]
```

**C++ CODE — type in your source file**

```cpp
health = health - 10;
```

**DIAGRAM — Updating health**

```mermaid
flowchart LR
    A["health<br/>100"] --> B["Subtract 10"]
    B --> C["health<br/>90"]
```

**Try it:** Start at `100`. Take damage twice. What is in the box?

## 5. Decisions choose a path

**C++ CODE — type in your source file**

```cpp
if (health > 0) {
    std::cout << "Keep playing!\n";
} else {
    std::cout << "Game over!\n";
}
```

**DIAGRAM — Choosing a path**

```mermaid
flowchart TD
    A{"Is health greater than 0?"} -->|Yes| B["Keep playing!"]
    A -->|No| C["Game over!"]
```

**Trace it:** Follow the arrows with health `20`. Then try `0`.

## 6. Loops repeat instructions

**C++ CODE — type in your source file**

```cpp
int count = 0;
while (count < 3) {
    std::cout << count << "\n";
    count = count + 1;
}
```

**DIAGRAM — Repeating instructions**

```mermaid
flowchart TD
    A["Start: count = 0"] --> B{"Is count less than 3?"}
    B -->|Yes| C["Print count"]
    C --> D["Add 1 to count"]
    D --> B
    B -->|No| E["Stop<br/>Printed: 0, 1, 2"]
```

**Predict:** Change `3` to `5`. What will print?

## 7. Functions are little machines

A function takes input, does a job, and can return an answer.

**C++ CODE — type in your source file**

```cpp
int move(int position) {
    return position + 1;
}
```

**DIAGRAM — A function takes input and returns an answer**

```mermaid
flowchart LR
    A["INPUT<br/>2"] --> B["move()<br/>Add 1"]
    B --> C["ANSWER<br/>3"]
```

To keep the answer, store it:

**C++ CODE — type in your source file**

```cpp
int x = 2;
x = move(x);
```

**DIAGRAM — Saving a returned answer**

```mermaid
flowchart LR
    A["x stores 2"] --> B["move(2)"]
    B --> C["Returns 3"]
    C --> D["Store the answer<br/>x now stores 3"]
```

**Try it:** Make `move` add `2`. Recompile `move.cpp`, then link again.

## 8. A game map is a grid

| y ↓ / x → | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | # | # | # | # | # | # | # | # |
| 1 | # | . | **P** | . | . | . | . | # |
| 2 | # | . | . | . | # | . | . | # |
| 3 | # | # | # | # | # | # | # | # |

**# = wall · . = empty · P = player**

**DIAGRAM — Map coordinates**

```mermaid
flowchart LR
    A["Map coordinates<br/>Count from ZERO"] --> B["x = column<br/>Goes right"]
    A --> C["y = row<br/>Goes down"]
    B --> D["Player starts at<br/>x = 2, y = 1"]
    C --> D
```

**DIAGRAM — Checking a move**

```mermaid
flowchart TD
    A["Try moving right"] --> B{"Is the next square inside the map?"}
    B -->|No| C["Stay"]
    B -->|Yes| D{"Is it a wall?"}
    D -->|Yes| C
    D -->|No| E["Move one square right"]
```

**Point to it:** Where is the player after one move right?

Always check that a square is inside the map before reading it.

## 9. How does the map become a first-person view?

Imagine shining a thin flashlight beam from the player.

**DIAGRAM — Casting a ray**

```mermaid
flowchart LR
    A["Player"] -->|"Ray: a thin flashlight beam"| B["Wall"]
    B --> C["Measure the distance"]
```

Measure how far away the wall is. Nearby walls look taller.

**DIAGRAM — Near and far walls**

```mermaid
flowchart LR
    A["Nearby wall"] --> B["Draw a TALL slice"]
    C["Faraway wall"] --> D["Draw a SHORT slice"]
```

Many beams give us many screen columns. Together, they form the view.

**DIAGRAM — The game loop**

```mermaid
flowchart TD
    A["Read keys"] --> B["Move player"]
    B --> C["Draw view"]
    C --> D{"Quit?"}
    D -->|No| A
    D -->|Yes| E["End"]
```

## 10. Your mission checklist

- [ ] Print your name using C++.
- [ ] Point to the source file, object file, and executable.
- [ ] Explain linking by pointing to the two pieces it connects.
- [ ] Fix the missing-piece link error.
- [ ] Predict a variable's new value.
- [ ] Follow a decision and a loop with your finger.
- [ ] Move the player one square on the map.

**Next mission:** return to [your current lesson](COURSE-INDEX.md); after the first primer session, start [lesson 01](01-first-program/LESSON.md).

---

*Teaching note: code in lessons 4–6 belongs inside `main`, after including `<iostream>`. Teach one section at a time: point → predict → run. Terminal controls and precise wall-distance calculations come in later lessons.*
