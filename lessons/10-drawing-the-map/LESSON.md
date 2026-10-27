# 10 — Draw what the world remembers

CLI foundations. Work in short sessions; a lesson is a learning unit, not one uninterrupted talk.

## Before you begin

09: rows and indexing; teach one counted loop before nesting.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

A **renderer** turns stored information into output. It should show the world without changing the world just to draw it.

A counted for loop has a starting value, a condition checked before each repetition, and an update after each body. Teach a single row first. Nesting a column loop inside a row loop then means “for each row, visit each column.”

The player's location is separate data. At that coordinate we display P; elsewhere we display the stored map character. We do not replace floor in the map with P.

## Worked example — predict before running

With the player at (1,1), the map row "#..#..#" is displayed as "#P.#..#". The stored row is still "#..#..#".

Trace row 1:

| x | Stored character | Is it the player? | Printed character |
| --- | --- | --- | --- |
| 0 | # | no | # |
| 1 | . | yes | P |
| 2 | . | no | . |
| 3 | # | no | # |

The newline belongs after the inner column loop. If printed after every cell, the map becomes one character per line.

## Guided practice

1. Cover the outer loop and trace the inner loop for one supplied row.
2. Uncover the row loop and predict the first two complete rows.
3. Run the starter.
4. Change the player coordinate to (2,2), which is floor. Predict both the old and new display rows.
5. Inspect the final message showing the stored cell under P. It should remain a dot.

The casts around size() and loop packaging are adult-supported C++ details. Explain their purpose only as needed.

## Independent challenge

Choose a different valid floor position. Draw the complete expected output before running. Explain why moving P must make its old displayed square reappear as floor.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan traces the next visited cell, explains the placement of the newline, and distinguishes stored floor from displayed player.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The target shows P in row 2, column 2. Underlying data remains '.'. The original player square becomes floor on the next render because its stored map value never changed.

If a learner writes P directly into the map, ask what the original character was and how it would be restored. Separate the map and player rather than adding cleanup code.

Using width as both row and column limits is wrong on this 7-by-4 map. Count rows with height and columns with the chosen row's length.

### What the comparison target demonstrates

The target changes the player coordinates only; renderer behaviour is otherwise identical.

### Source connection

A: lines 269–275; line 271 uses map width for both loops. Use height for rows in the course.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [11 — Name a rule](../11-functions-and-examples/LESSON.md)

