# 11 — Name a rule

CLI foundations. Work in short sessions; a lecture is a learning unit, not one uninterrupted talk.

## Before you begin

10: comparisons, coordinates and maps; pause for function syntax.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
This starter intentionally contains the specific logic fault described below. It compiles and runs so Nathan can compare behaviour with a prediction.

Use [the common compile/run instructions](../SETUP.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

A **function** gives one operation a name. Its parameters are named inputs for that operation. A returned value is its answer.

Read the signature `bool is_inside_map(int x, int y, int width, int height)` as “given a position and map dimensions, answer true or false.” A parameter's name is local to this function; the caller supplies values for it.

Its purpose is narrow: tell whether coordinates are inside a rectangle. It does not inspect walls or move the player. Assume width and height are positive integers.

## Worked example — predict before running

For width 7 and height 4:

| Position | Inside? | Reason |
| --- | --- | --- |
| (0,0) | true | first column and row |
| (6,3) | true | last column and row |
| (7,1) | false | column 7 does not exist |
| (-1,1) | false | before first column |
| (2,4) | false | row 4 does not exist |

The starter deliberately uses x <= width. This answers true for (7,1), contradicting the example. It compiles and runs, but its rule is wrong.

&& means all joined questions must be true. Return supplies the resulting bool to the caller.

## Guided practice

1. Work the table before opening the function body.
2. Run the starter and compare each displayed answer.
3. Locate the condition responsible for the right edge. Repair it.
4. Add a call for (2,4) and predict false.
5. Try a second rectangle, width 3 and height 2, with its own examples.

After hand-worked examples are clear, an adult can show how expected/actual comparisons become executable checks.

## Independent challenge

Add examples for just beyond the bottom edge and just above the top edge. Explain why checking only x is insufficient.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan explains arguments and result, fixes the right-edge counterexample, and predicts an unshown boundary case.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The repair is x < width. After it, the supplied four lines report true, true, false, false. The added (2,4) answer is false.

Explain < as strictly before the limit, rather than memorising “always use <”. Other problems may legitimately have inclusive bounds.

Calling is_inside_map does not change a player coordinate. It returns information; movement code will decide what to do with that answer.

### What the comparison target demonstrates

The target changes <= width to < width. It does not silently add a wall check.

### Source connection

A: lines 187–195, bounds before lookup. Existing include/game_rules.hpp is an adult design-recipe comparison, not the beginner starter.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [12 — Propose, check, accept](../12-valid-movement/README.md)

