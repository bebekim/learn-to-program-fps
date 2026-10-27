# 03 — Remember a value

CLI foundations. Work in short sessions; a lecture is a learning unit, not one uninterrupted talk.

## Before you begin

02: sequential output.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../SETUP.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

Sometimes a program must remember a value rather than print the same fixed text forever. A **variable** gives a value a name.

In `int health = 5;`, int means a whole-number value, health is our chosen name, and 5 is the initial value. Read it as “create health and start it at five.” For this lesson, leave the value unchanged after creation.

A label on screen and a variable name are different. The text Health: is just a message. The identifier health tells the program which remembered value to display.

## Worked example — predict before running

```cpp
int health = 5;
std::cout << "Health: " << health << "\n";
std::cout << "Remembered health: " << health << "\n";
```

Both instructions use the same variable. Expected values are five and five.

Compare:

```cpp
std::cout << "health\n";
std::cout << health << "\n";
```

The first prints the letters health because they are quoted. The second displays its value because it names the variable.

## Guided practice

1. Make a table with name, value, and meaning: health; 5; the player's remaining health points.
2. Predict both output lines.
3. Change the initial value to 8. Predict both lines before compiling.
4. Run and check that both uses show 8.
5. Print the word health in quotes on a separate line and compare it with the value.

Do not update health midway through the program today; that is the next lecture.

## Independent challenge

Add an integer named keys starting at zero and print a labelled key count. Ask Nathan to explain why it is a number rather than a quoted word.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan can identify a name and its value, explain quoted text versus a variable use, and create one similarly shaped integer declaration.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

Both uses of health display the changed initial value. A quoted identifier prints its spelling instead.

If Nathan changes one displayed literal instead of the variable, ask “Which thing is being remembered?” If he expects the text Health: to change when the value changes, distinguish the label from the data.

C++ is case-sensitive: health and Health are different identifiers. Explain this only if it arises; do not add a naming-rules lecture.

### What the comparison target demonstrates

The teacher target changes health from 5 to 8. The keys declaration is an independent exercise.

### Source connection

A: lines 78–88, named dimensions, position and speed; introduce integers before floats.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [04 — A value can change](../04-changing-state/README.md)

