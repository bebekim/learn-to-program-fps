# 05 — Ask the player

CLI foundations. Work in short sessions; a lesson is a learning unit, not one uninterrupted talk.

## Before you begin

04: values and assignment.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

Output tells the player something. **Input** lets the running program receive a value from the player. Today the program asks for one character and repeats it back; it does not yet act on the command.

`char command = '?';` prepares a place for a single character. Single quotes such as 'w' describe one character; double quotes describe a text string. `std::cin >> command;` reads a character from standard input.

In the ordinary console, type the letter and press Enter. This is different from the original FPS, which polls whether a key is held.

### Standard input and standard output

A **stream** carries a sequence of characters into or out of a program.
Every ordinary terminal program has a **standard input** channel (often called
**stdin**) and a **standard output** channel (often called **stdout**).
In our terminal session, input comes from what we type and output appears in the
terminal. These channels can also be connected to files or other programs; they
do not always mean a keyboard and screen.

In C++, `<iostream>` supplies the stream names we use:

| C++ name | Channel | What we use it for |
| --- | --- | --- |
| `std::cin` | Standard input | Read the player's typed character |
| `std::cout` | Standard output | Write the prompt and reply |

`stdin` and `stdout` are also names used by C's input/output library. Here we write
the C++ names `std::cin` and `std::cout` in our code.

```text
Player types d, then Enter
         |
         v
standard input --> std::cin >> command --> command now stores 'd'
                                              |
                                              v
terminal display <-- standard output <-- std::cout << command
```

The program normally waits at the input operation until input is available.
The terminal may show the letter while you type: that is the terminal's own echo.
Our program's reply is the later `You typed: d` line.

### Read the symbols one piece at a time

```cpp
char command = '?';
```

| Piece | Meaning here |
| --- | --- |
| `char` | The type: this variable holds one character |
| `command` | The name we chose for the variable |
| `=` | Give the new variable its initial value |
| `'?'` | A character literal: the character between single quotes |
| `;` | End this statement |

`command` is a name, so it has no quotes. `'d'` means the literal character d;
`command` means “use the value currently stored in this variable.”

```cpp
std::cin >> command;
```

| Piece | Meaning here |
| --- | --- |
| `std` | The namespace containing these C++ standard-library names |
| `::` | Scope resolution: look inside `std` for the name that follows |
| `cin` | The standard input stream |
| `>>` | Stream extraction: read a value from the stream into the variable on the right |
| `command` | Where to store the character we read |
| `;` | End this statement |

Say: **“Read a character from standard input into command.”** With a `char`, this
operation skips whitespace such as spaces and newlines, then reads one character.
Typing `dog` does not store a whole word: this read stores `'d'` and leaves the
remaining characters available for later reads. The old `'?'` is replaced when
the read succeeds.

```cpp
std::cout << "You typed: " << command << "\n";
```

| Piece | Meaning here |
| --- | --- |
| `std::cout` | The standard output stream, using the same `std::` naming syntax |
| `<<` | Stream insertion: send the value on the right to the output stream |
| `"You typed: "` | A string literal: output this text, including the final space |
| `command` | Output the character stored in the variable |
| `"\n"` | A string containing a newline; move subsequent output to the next line |
| `;` | End the complete statement |

The repeated `<<` operations write the pieces in order. They do not automatically
insert spaces or newlines. The quotes mark literals in the source code; the quotes
themselves are not printed. The escape sequence `\n` requests a newline instead of
printing a backslash and an n.

Remember the direction with these two examples:

```cpp
std::cin >> command;  // Input stream >> destination variable.
std::cout << command; // Output stream << value to display.
```

`>>` and `<<` each form one operator: keep the two angle brackets together.
With these streams they mean extraction and insertion. With integer operands,
the same symbols can mean bit shifting; their meaning depends on the operands.
We are using their stream meaning today.

## Worked example — predict before running

```cpp
char command = '?';                         // Prepare one character of storage.
std::cout << "Type one letter: ";           // Write a prompt to standard output.
std::cin >> command;                        // Read from standard input into command.
std::cout << "You typed: " << command << "\n"; // Write text, the value, then a newline.
```

If the player enters d, command contains 'd' and the echoed message includes d. The initial '?' is replaced by the input.

Text after `//` is a **comment** for the reader, up to the end of that line.
The compiler does not execute the comment.

### Understand the supplied file's surrounding syntax

The runnable starter includes a few more pieces:

| Syntax | Meaning |
| --- | --- |
| `#include <iostream>` | A preprocessing directive that makes the standard stream declarations available; it has no trailing semicolon |
| `int main()` | Define the program's main function; `int` says it returns an integer status, and this empty `()` declares no parameters |
| `{` and `}` | Mark the beginning and end of the function's body |
| `return 0;` | Finish `main` and report successful completion to the operating system |

The starter uses this guarded version of the read:

```cpp
if (!(std::cin >> command)) return 0;
```

Read it from the inside out:

1. `std::cin >> command` attempts to read the character and returns the stream.
2. In a condition, that stream tells us whether it is still in a successful state.
3. `!` means “not”, so `!(...)` is true when the read has failed.
4. `if (...)` runs the following statement only when its condition is true.
5. `return 0;` ends the program, so it does not print a reply using a failed read.

The inner parentheses group the read for `!`; the outer parentheses enclose the
`if` condition. Here the following action is one statement, so it needs no extra
braces. We will practise conditions in lesson 6. For now, keep this supplied guard:
it handles input ending or failing. Zero is the chosen exit status for this small
example; it does not mean the read succeeded.

## Guided practice

1. Predict what happens if the player types w and presses Enter.
2. Run and try w.
3. Run again and type x. Does changing the input require recompiling? Explain.
4. Change the prompt to say that one letter and Enter are required.
5. Compare changing an instruction, which needs a rebuild, with supplying new input, which does not.
6. Point to `>>` and name its destination. Point to each `<<` and name the value
   it sends to standard output.
7. Predict the reply if the spaces around `command` in the C++ source are changed.
   Then predict what happens if the final space inside `"You typed: "` is removed.
   Source formatting and characters inside a string have different jobs.

## Independent challenge

Choose another prompt that asks for one letter. Keep the echo so that the player can see what was received. Do not try a full player name with a char variable.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan distinguishes changing source from changing input and can explain the value that gets echoed.
He can also read `std::cin >> command` aloud, explain how `std::cout << command`
differs, and distinguish a variable name, a character literal and a string literal.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The prompt does not itself store a command. Reading input updates command. Enter is normally needed before the console supplies the line.

With formatted char input, whitespace is skipped. If the player types several letters, one is consumed by this read and the rest remain available; do not call this a full-line parser. Use single-letter examples now.

If the learner expects w to move a player, ask where the movement instruction is. Input alone does not invent behaviour.

### What the comparison target demonstrates

The target improves only the prompt; the echo behaviour is unchanged.

### Source connection

A: line 140, `GetAsyncKeyState`; typed input is a new bridge and requires Enter.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [06 — Choose an action](../06-conditions/LESSON.md)

