# 08 — Locate the player

CLI foundations. Work in short sessions; a lecture is a learning unit, not one uninterrupted talk.

## Before you begin

07: repeated commands; practise number lines first.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../SETUP.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

We need a way to say where the player is. A coordinate pair names a location: x is the column, increasing to the right; y is the row, increasing down the page. This is our explicit screen/map convention.

Start with a number line for x alone. Then add rows. The pair (1,1) means column 1, row 1. Do not teach map indexing in the same breath.

The current program has no walls or boundaries. Negative coordinates are possible here. That is a deliberately incomplete world rule, not a compiler error.

## Worked example — predict before running

Begin at (1,1) and use d for east, a for west, s for south, w for north:

| Command | Change | New position |
| --- | --- | --- |
| d | x increases by 1 | (2,1) |
| d | x increases by 1 | (3,1) |
| s | y increases by 1 | (3,2) |
| a | x decreases by 1 | (2,2) |
| w | y decreases by 1 | (2,1) |

The starter intentionally has no w update. First predict its current behaviour: w leaves the position unchanged. Then describe the desired rule.

## Guided practice

1. Draw axes and walk the first three commands on paper.
2. Run the starter with d, d, s and compare.
3. Try w and observe the missing feature.
4. Add the one north-movement condition after explaining which coordinate changes.
5. Run the full five-command route and compare it with the table.
6. Use q to exit.

## Independent challenge

Invent a four-command route that returns to (1,1). Predict every intermediate position, not just the last one.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan traces a new route and changes the correct coordinate for a direction without copying the route from the demonstration.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The target adds `if (command == 'w') y = y - 1;`. It must not decrease x. The five-command trace ends at (2,1); the first three end at (3,2).

d,s,a,w is one valid closed route. Reversing the vertical convention could also work in a different design, but mixing conventions within this game is a fault.

If Nathan can predict only by running, return to the paper grid and move a counter one instruction at a time.

### What the comparison target demonstrates

The target supplies only the missing north update. Map storage remains a separate next step.

### Source connection

A: lines 83–84 and 142–143, player coordinates; our row/column convention is made explicit.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [09 — Store and query a maze](../09-map-data/README.md)

