# 16 — Face and turn

Optional depth lab after CLI foundations. These portable console experiments isolate ideas for a later raylib or console-rendering implementation.

## Before you begin

15: fractional coordinates and timed movement; teach angles on paper first.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

A direction tells us how movement is split between x and y. A unit direction has length one; multiply it by distance to obtain coordinate changes.

Use four cardinal arrows before trigonometry. Our convention matches the reference: angle 0 points down the map, positive y. At 90 degrees, the player faces right, positive x. Positive turning moves that facing from down towards right.

A full turn is 360 degrees or 2π radians. The C++ sine and cosine functions expect radians. Conversion is an explicit step, not a naming preference.

## Worked example — predict before running

| Degrees | Direction (dx,dy), approximately | End after 2 units from (1,1) |
| --- | --- | --- |
| 0 | (0,1) | (1,3) |
| 90 | (1,0) | (3,1) |
| 180 | (0,-1) | (1,-1) |
| 270 | (-1,0) | (-1,1) |

With our convention, dx = sin(angle) and dy = cos(angle). Another consistent convention could use a different pairing.

The lab calculates radians = degrees × π / 180, then uses the resulting direction. Very small values near zero may print as -0.000 because of floating-point rounding.

## Guided practice

1. Move a paper counter two units along each cardinal arrow.
2. Predict the starter's output at zero degrees and run it.
3. Change degrees to 90. Predict direction and final position.
4. Try 45 degrees only after the cardinal cases are secure. The changes should be approximately equal in magnitude.
5. Explain why (1,1) is not a unit direction: moving by that pair covers more than one unit diagonally.

## Independent challenge

Choose a heading for going left. Predict its direction and the end position after travelling three units from (4,2).

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan sketches a heading, connects direction components to movement, and explains degrees versus radians using a cardinal counterexample.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The target at 90 degrees prints approximately Direction: 1.000, 0.000 and endpoint (3,1). Going left uses 270 degrees under this convention and ends at (1,2) after three units from (4,2).

Do not say that sine “always gives x”. It does so because of our chosen angle origin and axes.

The supplied lab has no map bounds or collision. Negative coordinates in its arithmetic are not a memory access.

### What the comparison target demonstrates

The target changes only degrees from 0 to 90.

### Source connection

A: lines 85 and 131–143. Reference angle zero moves along positive y; document course convention explicitly.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [17 — Ask what is ahead](../17-one-ray/LESSON.md)

