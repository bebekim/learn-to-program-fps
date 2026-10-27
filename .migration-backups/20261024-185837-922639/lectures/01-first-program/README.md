# 01 — Run, change, run again

CLI foundations. Work in short sessions; a lecture is a learning unit, not one uninterrupted talk.

## Before you begin

None; adult has verified compiler and Geany.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../SETUP.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

A computer does not read your intention. It follows the instructions in the program you run. The text in Geany is **source code**. The compiler translates that text into an **executable**. Running the executable carries out those instructions.

Point to the source file, then to the running console. Say: “These are related, but they are not the same thing. Editing the source changes our instructions. Compiling makes a new runnable program.”

For today, `#include <iostream>`, `int main()`, the braces, and `return 0;` are supplied packaging. Explain only that the program starts inside main. Nathan does not need to memorise the packaging to change a message.

## Worked example — predict before running

Read these two instructions aloud before running:

```cpp
std::cout << "Nathan's Maze\n";
std::cout << "Find the exit.\n";
```

`std::cout` sends output to the console. Text inside double quotation marks is the message. `\n` starts a new line; it is not printed as a backslash and an n.

Expected output:

```text
Nathan's Maze
Find the exit.
```

Ask: “Which part could we change to give the game another name?” Point only to the characters inside the first pair of quotes.

## Guided practice

1. Run the unchanged starter and compare it with the prediction.
2. Change only the title. Before compiling, say the new first line and whether the second line will change.
3. Save, compile, and run. Compare both lines.
4. Edit the title again, but deliberately run the old executable once before rebuilding. Observe the old title; then compile successfully and run again.

Stop here if the build/run cycle is still unfamiliar. Do not introduce variables yet.

## Independent challenge

Make the second message invite the player into a maze. Keep the two output instructions and their order. Ask Nathan to point to exactly what he changed.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Without a demonstrated edit, Nathan can choose a new message, predict it, compile, and show it. He can identify source versus executable and explain why rebuilding is necessary.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

Expected: changing only the first string changes only the first line. Running an old executable keeps the old title because it still contains the earlier translation.

If a quote is accidentally deleted, the compiler may report several errors. Restore the first broken quote and rebuild; do not explain every downstream diagnostic. If the executable still shows an old message after a failed build, the old executable is not evidence that the edited source compiled.

Accept an explanation such as “I change the source, build it, then run the new program.” Do not require the words translation unit, stream, or exit status.

### What the comparison target demonstrates

The teacher target changes the title only. The independent second-message task is intentionally left to Nathan.

### Source connection

A: line 90, `int main()`; printing is a new bridge exercise, not extracted FPS output.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [02 — Instructions have an order](../02-instructions-and-output/README.md)

