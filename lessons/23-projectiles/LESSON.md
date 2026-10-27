# 23 — Create, update and remove

Optional extension. This is a focused runnable experiment, not a finished engine feature.

## Before you begin

22: structs, collections, collision and elapsed time.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

A projectile is an object with a lifecycle: create it, update it while active, mark it for removal when its life ends or it hits something, then clean up the collection.

Creation, update and cleanup should be distinct steps. Removing an element while an unsafe loop still refers to it can invalidate the loop's references. The supplied erase/remove_if plumbing is adult-provided.

Fast movement introduces another problem: checking only the endpoint can skip a wall. The lab supplies short substeps for point projectiles crossing full grid walls. This is not a general swept-shape physics engine.

## Worked example — predict before running

The shot begins at (1.5,1.5), moving east at 8 units/second for .5 seconds. Its unblocked endpoint would be x=5.5.

The row "#..#..#" has a wall at column 3. Both x=1.5 and x=5.5 are floor, so an endpoint-only test would miss that wall. Substeps visit the intervening cells and mark removal when entering column 3.

Before cleanup, the collection still contains one marked record. After cleanup, it contains zero. Marking and erasing are different events.

## Guided practice

1. Draw the start, endpoint and intervening wall.
2. Predict the collection count before and after cleanup.
3. Run the starter.
4. Change vx to zero. The shot no longer crosses the wall and remains alive after one .5-second update.
5. For the stationary case, change starting life to .25 seconds. Predict removal despite no movement.
6. Restore the working example after each isolated experiment.

The lab has one supplied shot rather than interactive firing; connecting a key to creation is a later integration task.

## Independent challenge

Choose a shot speed and lifetime in an empty corridor. Predict its free-space travel distance, then place a wall and explain which event ends its life first.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan traces creation/update/mark/cleanup, explains endpoint tunnelling, and distinguishes wall removal from lifetime removal.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

Original output is Before cleanup: 1 then After cleanup: 0. The target with vx=0 prints 1 then 1 because remaining life is 1.5 seconds and the shot stays on floor. With initial life .25 and dt .5, it is removed due to expiry.

This teaching lab moves the full dt before lifetime cleanup; it does not simulate an exact fractional expiry time within that update. Do not use it to promise precise endpoint-at-expiry behaviour.

Bounds checks run before map access. Collection size shrinks only at cleanup.

### What the comparison target demonstrates

The target makes the shot stationary; the lifetime experiment remains independent.

### Source connection

B: lines 207–220, 314–324 and 372–373; original object lookup lacks bounds checks. Supply substeps or swept checks for fast shots.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [24 — Explain what is visible and who does what](../24-depth-and-architecture/LESSON.md)

