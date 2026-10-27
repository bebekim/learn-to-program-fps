# 09 — Store and query a maze

CLI foundations. Work in short sessions; a lesson is a learning unit, not one uninterrupted talk.

## Before you begin

08: coordinates; introduce one string and index before a collection of rows.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

A printed maze is only output. A stored maze is **data** that a program can query. We represent a wall with '#' and floor with '.'. The character is a symbol for something in our world.

Start with one string, such as "#..#". Its characters have indices 0,1,2,3. Then introduce a collection of rows. The supplied `std::vector<std::string>` syntax means a collection of text rows; do not teach allocation or templates today.

For our row-based representation, `map[y][x]` first selects row y, then character x. This order follows the representation, even though we speak a position as (x,y).

## Worked example — predict before running

Use the starter's rectangular map, width 7 and height 4:

```text
    x: 0123456
y=0    #######
y=1    #..#..#
y=2    #.....#
y=3    #######
```

At (3,1), select row 1 "#..#..#", then character 3 '#'. At (2,1), the character is '.'. At (1,2), it is also '.'.

A width of 7 means valid x indices are 0 through 6, not 0 through 7. A height of 4 means valid y indices are 0 through 3.

## Guided practice

Session A: write one row on paper, number its characters, and predict three character lookups. Session B: select a row from the map, then a character from that row.

1. Predict the starter lookup at (3,1); run it.
2. Change the query to (2,1). Predict before rebuilding.
3. Change one wall in a supplied row and predict which queries change.
4. Compare the number of rows with the number of columns.

Only use known valid indices. Do not “see what happens” with an out-of-range access; C++ does not promise a helpful error.

## Independent challenge

Draw a different rectangular maze of equal-length rows. Choose three valid coordinates and predict the character at each. Keep the player idea on paper for now.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan maps a drawn location to row, column, and stored character, and states the valid index ranges for a new rectangle.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The original lookup prints #, Rows: 4, Columns: 7. The target lookup at (2,1) prints a dot.

Swapping x and y can remain unnoticed on a symmetric part of a map. Use the valid position (3,2): map[2][3] is floor, while the swapped lookup map[3][2] is a wall. Both lookups stay in range, so this safely demonstrates the error. By contrast, (2,1) and (1,2) both contain floor and would not distinguish the two implementations. Choosing a revealing example matters.

The original FPS uses a flat string and different coordinate naming. Preserve our row/column convention rather than copying its formula.

### What the comparison target demonstrates

The target changes only the lookup to floor at (2,1).

### Source connection

A: lines 99–115 and 195; reference uses a flattened string and transposed coordinate naming. Do not copy its lookup blindly.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [10 — Draw what the world remembers](../10-drawing-the-map/LESSON.md)

