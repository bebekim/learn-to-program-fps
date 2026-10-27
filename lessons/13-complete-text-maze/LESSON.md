# 13 — Finish a game you can explain

CLI foundations. Work in short sessions; a lesson is a learning unit, not one uninterrupted talk.

## Before you begin

12: safe movement; introduce one game-state flag at a time.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
This starter intentionally contains the specific logic fault described below. It compiles and runs so Nathan can compare behaviour with a prediction.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

A complete game needs rules about progress and ending, not just movement. Our maze adds a key K and exit E. The player remembers has_key and won as bool values.

Do this over three sessions: first a reachable exit; then a key requirement; then reset and post-win behaviour. The supplied checkpoint already contains these systems so you can isolate one at a time while reading.

The map records the key's location. has_key records whether it has been collected. Drawing hides K after collection without destroying the original map; reset can therefore restore the world from its initial state.

## Worked example — predict before running

Our rows are:

```text
#######
#..#E.#
#.K...#
#.....#
#######
```

Begin at (1,1). The route d,s,d,d,w reaches (4,1) with the key in five accepted moves. At the second command, the player enters K at (2,2).

Now try s,s,d,d,d,w,w. This travels along the lower corridor, bypassing K, and attempts to enter E from (4,2). The final w is blocked because has_key is false. The player remains at (4,2) after six accepted moves.

After winning, movement is ignored. r resets, and q quits. The lower corridor makes the missing-key condition genuinely reachable: map design affects which rules we can test.

## Guided practice

1. Predict the five-command winning route; run it.
2. Try movement after winning and explain why position stays still.
3. Press r. Inspect position, key, moves, and won.
4. The starter intentionally forgets to reset has_key. Identify the mismatch with a true new game.
5. Repair that single omission. Repeat win → restart → inspect.
6. Restart and try the seven-command bypass route from the worked example. Check that E refuses entry without the key.

Unknown input and blocked movement must not increment the count. Read the existing map/drawing code as supplied infrastructure and introduce one new rule per short session.

## Independent challenge

Design a different map that still has two routes, one bypassing the key. Move K or E, then predict a failed exit attempt, key collection, successful exit, and complete restart. Use a genuinely new layout rather than reproducing the worked route.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan demonstrates a locked exit, key collection, winning, post-win behaviour and full restart, and explains how both routes exercise different cases.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The target adds has_key = false in the restart branch. A fresh game has position (1,1), moves 0, key false and won false.

A game-state table is useful: playing accepts movement; won accepts restart or quit; restart returns either state to playing. Quit ends execution rather than being stored as won.

Ask Nathan to list everything that reset must restore before suggesting code. Reset bugs reveal that game state is more than position.

The winning route has five accepted moves: d,s,d,d,w. The missing-key bypass has six accepted moves followed by one rejected exit attempt. A restart must clear has_key before that bypass is a valid missing-key test.

### What the comparison target demonstrates

The target repairs key reset only. The supplied bypass route checks the rule; designing another layout is the independent transfer exercise.

### Source connection

A: lines 99–115, maze representation. Keys, exit and restart are new course features; book §10.2 is adult state-machine background.

A/B/C resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [14 — Organise without changing the game](../14-program-structure/LESSON.md)

