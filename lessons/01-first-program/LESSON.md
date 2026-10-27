# 01 — Run, change, run again

CLI foundations. Work in short sessions; a lesson is a learning unit, not one uninterrupted talk.

First complete [00 — Compile and run](../00-compile-and-run/LESSON.md).
This lesson uses that familiar build/run workflow to make and test a message change.
Today the program only prints two lines. Nathan's Maze is a chosen title; there
is no playable maze yet. The task is to change text and check the rebuilt output.

## Before you begin

Prerequisite: Nathan has built and run the supplied greeting in lesson 00.
For compiler installation or repair, use [lesson 00 setup](../00-compile-and-run/ADULT-SETUP.md).

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Follow the picture

Use [lesson 00's source → build → executable → run charts](../00-compile-and-run/LESSON.md)
as a reminder. Today we add a new question: after changing the source, does the
rebuilt program show exactly the message we predicted?

## Explain it together

A computer does not read your intention. It follows the instructions in the program you run. The text in Geany is **source code**. The compiler translates that text into an **executable**. Running the executable carries out those instructions.

Point to the source file, then to the running console. Say: “These are related, but they are not the same thing. Editing the source changes our instructions. Compiling makes a new runnable program.”

Read the surrounding syntax together using the guide below. Nathan can look up
these pieces while editing; memorising them is not a prerequisite for changing a message.

### Read the syntax of a message

```cpp
std::cout << "Nathan's Maze\n";
```

| Piece | Meaning |
| --- | --- |
| `std::cout` | The standard output stream; our terminal displays what we send here |
| `std` and `::` | Use the name `cout` from the standard-library namespace `std` |
| `<<` | Send the value on the right to the output stream on the left |
| `"` … `"` | Double quotes mark the beginning and end of a string literal |
| `Nathan's Maze` | The characters to print; the apostrophe is ordinary text inside double quotes |
| `\n` | Request a newline within the output |
| `;` | End the C++ statement |

Read it as “write Nathan's Maze, then a newline, to standard output.”
Changing the text inside the quotes changes the message. The quotes and semicolon
still have their syntax jobs. `""` is an empty string; it contains no characters.

The surrounding file also has syntax worth recognising:

- `#include <iostream>` makes the stream declarations available. Angle brackets
  surround the header name; this directive has no trailing semicolon.
- `int main()` defines the main function with no parameters. Its `int` return type
  means it returns an integer status.
- `{` and `}` enclose that function's instructions.
- `return 0;` finishes the function with a successful exit status.
- `//` begins a comment lasting to the end of the source line. The TRY THIS comment
  is a note for you, not output for the player.

Spaces inside a quoted message appear in the output. Indentation before
`std::cout` helps us read the source but is not printed. A line break in the source
between statements is also different from the output newline requested by `\n`.

**Point and explain:** which characters name a library stream, which characters
are the message, and which symbol ends the statement?

## Worked example — predict before running

Read these two instructions aloud before running:

```cpp
std::cout << "Nathan's Maze\n";
std::cout << "My first game program.\n";
```

`std::cout` sends output to the console. Text inside double quotation marks is the message. `\n` starts a new line; it is not printed as a backslash and an n.

Expected output:

```text
Nathan's Maze
My first game program.
```

Ask: “Which part could we change to give the game another name?” Point only to the characters inside the first pair of quotes.

## Guided practice

1. Run the unchanged starter and compare it with the prediction.
2. Change only the title. Before compiling, say the new first line and whether the second line will change.
3. Save, compile, and run. Compare both lines.
4. Edit the title again, but deliberately run the old executable once before rebuilding. Observe the old title; then compile successfully and run again.

Stop here if the build/run cycle is still unfamiliar. Do not introduce variables yet.

## Independent challenge

Change the second message to say who made the program. Keep the two output instructions and their order. Predict both output lines before rebuilding, then point to exactly what changed.

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

Next: [02 — Instructions have an order](../02-instructions-and-output/LESSON.md)

