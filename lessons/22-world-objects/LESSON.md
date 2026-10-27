# 22 — Group information about one thing

Optional extension. This is a focused runnable experiment, not a finished engine feature.

## Before you begin

20; texture lesson optional. Introduce struct before collection iteration.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

When one thing has several related values, group them. An Object record contains x, y, vx and vy. x and y describe location; vx and vy describe velocity components.

A collection holds several such records. The same update rule can operate on each record: x changes by vx × dt and y by vy × dt.

This is a useful architecture idea before a general ECS. We do not need an entity manager, inheritance tree, or raw owning pointer to move two objects.

## Worked example — predict before running

At dt=.5 seconds:

| Object | Start | Velocity | End |
| --- | --- | --- | --- |
| Lamp | (2,1) | (0,0) | (2,1) |
| Moving object | (1,1) | (2,0) | (2,1) |

The equal final positions do not mean these are the same object. Their records and velocities remain distinct.

In `for (auto& object : objects)`, & means that object refers to the actual collection element. With `auto object` instead, the loop operates on a copy; changes would not update the collection. Demonstrate that distinction only after the basic movement is familiar.

## Guided practice

Session A: draw one record and name its fields. Session B: place two records in the collection and trace the shared rule.

1. Predict both output positions.
2. Run the starter.
3. Add a stationary object at (4,2).
4. Predict three output records and run.
5. On an adult-guided saved copy, remove & from the update loop and compare; restore it afterwards.

## Revisit a Player as grouped data

Look with the adult at D1 (`terminal-fps/src/player.rs`), lines 2–6 and 25–40.
The port groups x, y and facing angle in Player, then names operations such as
move_forward and turn_left. Translate the idea into familiar C++, not Rust syntax:

```cpp
struct Player {
    float x;
    float y;
    float angle;
};
```

Paper task: begin at x=2, y=2, angle=0. A displacement (1,0) should give x=3,
y=2, with angle still 0. Turning by 0.25 radians should change angle, not position.
List which fields each operation reads or changes before discussing methods.

Ask: “Does putting x and y in a Player automatically prevent entering a wall?”
No. D2, lines 49–55, still performs collision checking outside the Player operation.
A struct groups data; a legality rule must still be designed and checked.

Our current Object records deliberately have a shared external update loop.
The port puts coordinate changes behind named player operations. Both are designs
to discuss. Do not require getters, private fields or member functions merely to
imitate the Rust file. Introduce restricted access when a concrete rule needs it.

Instructor answer: for the displacement example the final position is (3,2),
angle unchanged. For the separate turn example starting at angle 0, final angle
is 0.25. These are arithmetic examples; a map-aware movement rule may reject the
proposed position. Keep that distinction from lesson 12.

## Independent challenge

Create an object that moves upward by one unit over half a second under our y-down convention. Choose its initial position and velocity, and predict its endpoint.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan distinguishes one record from the collection, predicts a shared update for different velocities, and explains why the zero-velocity object stays still.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The target adds the stationary record (4,2,0,0). Its printed position remains (4,2). Moving upward one unit in .5 seconds requires vy=-2 units/second.

Avoid saying that structs “are objects in an engine” automatically. They are a grouping mechanism; the game decides their meaning.

When discussing references, use the concrete observation that updating a copy leaves the original unchanged. Detailed C++ lifetimes can come later as ownership questions arise.

### What the comparison target demonstrates

The target adds one stationary record without altering the update rule.

### Source connection

B: lines 86–96 and 140–144; adapt list and raw sprite pointers to simple value data and supplied asset handles.
D1: lines 2–6 and 25–40; compare related data with named operations without changing teaching language.

Lettered references resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [23 — Create, update and remove](../23-projectiles/LESSON.md)

