# 14 — Organise without changing the game

CLI foundations. Work in short sessions; a lecture is a learning unit, not one uninterrupted talk.

## Before you begin

13: complete text maze and basic functions.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
For the actual refactoring exercise, continue Nathan's corrected lecture 13 game; the provided modular program is a comparison checkpoint.

Use [the common compile/run instructions](../SETUP.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

As a program grows, we need to know where each rule lives. **Refactoring** changes organisation while preserving intended behaviour.

Separate input, update, and drawing. Input reads a command; update returns the resulting state; drawing displays state. Drawing should not collect a key or increment moves.

The provided comparison groups related fields in a State struct. The grouping syntax and const-reference map parameter are adult-supplied at first. Introduce only what is needed to extract one function; do not turn this into an all-at-once lesson on structs, copying and references.

## Worked example — predict before running

Trace one command through the organised version:

1. main reads d.
2. update receives the map, current State and command.
3. update proposes coordinates and asks can_enter.
4. If allowed, update changes its local state value and returns it.
5. main stores that returned state.
6. draw displays it on the next loop.

`state = update(map, state, command);` matters: update returns a new value. Calling it and discarding the returned value would leave main's state unchanged.

`const Map&` lets a function read the shared map without making a full copy or changing its contents. State is passed by value deliberately so that the update's result is explicit.

## Guided practice

1. Save lecture 13's corrected checkpoint.
2. Record the state after d,s,d,d,w,r and q.
3. Starting from that checkpoint, extract drawing into a function. Compare the same state trace.
4. Extract the movement decision in another session. Compare again.
5. Use target.cpp as an adult structural comparison only after Nathan's first extraction.
6. Change only the displayed player glyph. Explain why movement results should remain identical.

The supplied modular example has quieter feedback messages than lecture 13. Exact text is not an identical-output reference; compare gameplay state. A strict refactor of Nathan's version should preserve its messages too.

## Independent challenge

Point to where a future locked-door rule belongs. Then point to where a colour or text change belongs. Give a reason for each without implementing both.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan explains input → update → state → drawing, extracts one familiar operation, and checks that recorded state transitions remain the same.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

After the winning route: x=4, y=1, moves=5, has_key=true, won=true. After r: x=1, y=1, moves=0, has_key=false, won=false. Both organised and corrected monolithic versions should match.

The provided checkpoint is an adult reference, not an assignment to retype a complete new architecture. The marked starter comment asks for explanation rather than a fake missing feature. The actual work is extracting one function from the student's saved version.

If drawing changes state, calling draw twice can alter the game. That is evidence of mixed responsibilities.

### What the comparison target demonstrates

Starter and target implement the same modular reference. The intended student artefact is a small refactor of their own lecture 13 checkpoint, not a copied target file.

### Source connection

A: line 90 onward, large main; C: input/logic/presentation sections (see references).

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [15 — Distance depends on time](../15-real-time-movement/README.md)

