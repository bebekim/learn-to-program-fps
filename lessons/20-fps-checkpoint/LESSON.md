# 20 — Demonstrate and debug the FPS

Optional depth lab after CLI foundations. These portable console experiments isolate ideas for a later raylib or console-rendering implementation.

## Before you begin

19: integrated first-person maze.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

Integration can hide faults that each isolated demonstration missed. We need evidence about rules and connections, not just an attractive screenshot.

Use three sorts of evidence: an arithmetic or rule check with literal expected answers; a command trace through gameplay; and a visual inspection of the renderer. Each answers a different question.

The provided runnable checkpoint is a small automated geometry check. It is not a claim that the FPS game is complete. Use the earlier text-maze checkpoint for movement, key, exit and restart checks, and the static view lab for projection.

## Worked example — predict before running

A check compares an actual answer with a separately worked expected answer:

```cpp
Hit east = cast_ray(map, 1.5, 1.5, 1.0, 0.0, 0.25, 10.0);
if (!east.wall || std::abs(east.distance - 4.5) > 0.001) {
    ++failures;
}
```

The expected 4.5 comes from the paper map: 6.0 - 1.5. It must not be calculated by calling cast_ray again. The tolerance acknowledges approximate numeric work.

The starter checks an east ray, a negative outside start, and screen dimensions. These do not cover every rendering or movement rule.

## Guided practice

1. Write the east-ray expected answer on paper before reading the check.
2. Run the starter; it should report Failures: 0.
3. Add a north ray from (1.5,1.5), direction (0,-1), step .25. Trace the boundary samples before choosing the expected stepped answer.
4. Deliberately change that expected value and confirm the check fails with nonzero exit status.
5. Restore it.
6. Revisit the text game with a recorded win/restart trace and a non-square map.

Only add a test when it represents a useful case or guards a known risk.

## Independent challenge

Choose one missing case: an open map edge, maximum ray distance, unknown command, or reset after winning. Explain what it checks and why the existing checks do not already establish it.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan designs a useful counterexample, explains an observed failure, and distinguishes rule, integration and visual evidence.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The north ray's reported hit is .75 with this helper: at distance .5, y=1.0 still selects row 1; at .75, y=.75 selects wall row 0. The exact geometric boundary is .5. Keep the expected stepped answer distinct from an exact intersection.

A failing test can mean an incorrect implementation, an incorrect expectation, or a misunderstood contract. Investigate rather than editing until green.

The teacher target adds the north-ray check. Rendering dimensions alone do not validate perspective or game feel.

### What the comparison target demonstrates

The target adds one explicit north-ray expected/actual check.

### Source connection

A: lines 98–279 as integration reference; existing tests/rules_tests.cpp illustrates explicit expected/actual checks.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [21 — Choose a sample from a picture](../21-wall-textures/LESSON.md)

