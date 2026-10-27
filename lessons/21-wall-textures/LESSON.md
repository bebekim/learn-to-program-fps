# 21 — Choose a sample from a picture

Optional extension. This is a focused runnable experiment, not a finished engine feature.

## Before you begin

20: view and coordinates; optional extension after mastery.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

A texture is stored picture data. **Sampling** chooses a location in that data. Before using images or sprite loaders, use a grid of letters so that the chosen value is unambiguous.

We describe texture positions with u horizontally and v vertically. They are often normalised: 0 is the start, 1 is the far edge. To choose a cell in a width-4 texture, multiply u by 4 and take the integer part, with a defined edge policy.

The supplied function clamps to the first or last cell. A wrapping texture would use a different policy.

## Worked example — predict before running

```text
ABCD
EFGH
IJKL
MNOP
```

At u=.5, v=.25: x=int(.5×4)=2 and y=int(.25×4)=1. Row 1 is EFGH; character 2 is G.

At u=1, v=1, multiplication gives indices 4,4, which are outside a 4-by-4 picture. The helper clamps them to 3,3, selecting P. This policy is deliberate.

The helper's contract is a nonempty rectangular texture and finite sample coordinates. It is not a general image-file validator.

## Guided practice

1. Label the grid with x and y indices.
2. Work samples (0,0), (.5,.25), and (.75,.5).
3. Run the starter; compare G and the edge P.
4. Change the main sample to (.75,.5).
5. Explain how sampling differs from drawing: a sample reads data; the renderer decides where to display the result.
6. Stretch one row into a wider output using repeated samples only after the lookup is clear.

## Independent challenge

Design a 4-by-4 stripe pattern. Predict four sample values before running. State whether edge samples should clamp or wrap.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan predicts a new letter sample and explains the normalised coordinate, integer cell and edge policy separately.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

(.75,.5) maps to column 3, row 2: L. The target therefore prints Sample: L and Edge: P.

C++ truncation is not floor for negative numbers, but this helper clamps a negative result to zero, providing its chosen edge policy. Do not reuse that fact as a general map-coordinate conversion rule.

Texture loading, GPU resources, and the reference's wall-hit-angle calculation are adult infrastructure for now. Sampling is the student-owned concept.

### What the comparison target demonstrates

The target changes the sample coordinates only.

### Source connection

B: lines 135–137, 273–279 and 301–302; engine and sprite loading supplied by adult.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [22 — Group information about one thing](../22-world-objects/LESSON.md)

