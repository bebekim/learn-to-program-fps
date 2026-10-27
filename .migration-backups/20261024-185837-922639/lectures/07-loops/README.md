# 07 — Ask again until quit

CLI foundations. Work in short sessions; a lecture is a learning unit, not one uninterrupted talk.

## Before you begin

06: comparison and branching.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../SETUP.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

The current program reads one command and stops. A game needs to keep asking. A **loop** repeats a region of instructions.

`while (running)` means: check the current running value; if it is true, execute the body; then check again. running is a bool, a value that is either true or false.

The condition is checked again after the whole loop body. Changing running to false does not magically skip the remaining statements in that body. In this starter there is no further action after the quit branch.

## Worked example — predict before running

Trace the input sequence w, x, q:

| Repetition | Input | Response | running at end |
| --- | --- | --- | --- |
| 1 | w | Walk | true |
| 2 | x | Unknown command | true |
| 3 | q | no walk action | false |

The condition is false at the next check, so the loop finishes and Goodbye is printed once. Predict three prompts and one Goodbye.

## Guided practice

1. Draw a box around the loop body.
2. Trace w, x, q before running.
3. Try q as the first command. Count prompts and Goodbye messages.
4. Improve the unknown-command help inside the loop.
5. With the adult ready to stop the program, inspect what would happen if the quit branch never changed running. Prefer explaining before running an accidental endless loop.

## Independent challenge

Change the quit command to e and update the prompt. Predict what q now does. Preserve the unknown-command response and one final goodbye.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan identifies what repeats, what is remembered between repetitions, and what makes repetition stop.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

For q first, there is one prompt and one Goodbye. After moving quit to e, q is unknown unless deliberately given another branch.

If the input stream ends, the supplied read check breaks out of the loop. This is adult-supported robustness; it does not replace the game rule for quitting.

Ask “What can make the condition false?” before suggesting new code. A loop that repeats correctly but cannot stop is incomplete.

### What the comparison target demonstrates

The target improves help while keeping q as quit. The e variation is independent.

### Source connection

A: line 120, `while (1)`; course adaptation uses an explicit stop condition.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [08 — Locate the player](../08-coordinates/README.md)

