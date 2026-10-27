# 24 — Explain what is visible and who does what

Optional extension. This is a focused runnable experiment, not a finished engine feature.

## Before you begin

23 plus optional 21; revisit data and responsibilities.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

Several things can project onto the same screen location. The renderer must decide which one is in front. A **depth buffer** remembers the closest depth drawn so far for each location.

All compared depths must use the same meaning and units. Our column lab uses perpendicular camera depth for both walls and object fragments. Mixing corrected wall depth with raw radial object distance can produce incorrect visibility.

Architecture now becomes a practical question: which part owns the world data, applies rules, manages resources, and decides pixels? These are responsibilities, not necessarily four classes.

## Worked example — predict before running

Every column initially contains a wall at depth 4. Object A projects to column 1 at depth 2; object B projects to column 3 at depth 6.

| Fragment | Comparison | Visible? | Stored depth afterwards |
| --- | --- | --- | --- |
| A | 2 <= 4 | yes | 2 |
| B | 6 <= 4 | no | 4 |

The five-character output is #A###. Moving B to depth 3 makes it visible, producing #A#B#.

This lab treats fragments as opaque and stores one depth per column. A full sprite renderer may need per-pixel handling so transparent parts do not hide things behind them.

## Guided practice

1. Work both comparisons on paper.
2. Run the starter and compare the five characters.
3. Change B's depth to 3 and predict again.
4. Swap the order of the two fragments. Explain why these different columns do not interfere.
5. Put two unequal-depth fragments in the same column; predict which survives regardless of their order.
6. Draw a responsibility map: input chooses intent, update changes world state, render reads state and depth, asset handling supplies picture data.

## Revisit platform boundaries and resource lifetime

The port supplies a concrete reason to separate gameplay from its platform.
In D2 (`terminal-fps/src/main.rs`), lines 17–20 enable raw input, enter an alternate
screen and hide the cursor. Lines 206–207 restore the screen/cursor and normal input
on the normal exit path. These jobs change terminal state, not maze rules.

Ask which responsibilities survive a move to raylib:

| Responsibility | Terminal implementation | raylib revisit |
| --- | --- | --- |
| Describe the world | Map and player data | Keep their gameplay meaning |
| Decide valid movement | Bounds/wall rules | Reuse the rule or deliberately adapt geometry |
| Read player intent | Terminal key events | Window input adapter |
| Present the world | Character buffer and terminal writes | Graphical drawing/camera code |
| Restore platform resources | Terminal mode, screen and cursor | Window, cursor and resource lifetime |

### Cleanup is part of correctness — adult extension

Trace two paths on paper: Esc exits the loop normally; an input/output operation
returns an error before the loop finishes. In the Rust source, the error-propagation
operators can return before reaching the cleanup lines. Restoring at the bottom
therefore does not guarantee restoration on every exit path.

In a later C++ implementation, an adult can supply a terminal-session RAII guard:
acquire terminal state when the guard is created, restore it when the guard leaves
scope during normal return or exception unwinding. Do not promise restoration after
forced process termination. No terminal guard is implemented in this lesson's small
depth-buffer program; this is a design/lifecycle comparison.

Independent paper task: assign input, movement, ray casting, display and cleanup
to the file boundaries designed in lesson 14. Which two jobs should know the
terminal library? Which rules can be checked without opening a terminal session?

Instructor answers: the terminal input/output adapter and its session-lifetime
handling know the platform. Bounds and gameplay rules should be testable using
plain data. D3's utils.rs mixes configuration, map data and shading names; a general
utils name alone does not demonstrate a coherent responsibility. Split only when
a real change or dependency makes the boundary useful.

## Independent challenge

Explain which code would change when moving the same key/exit game to raylib. Identify one gameplay rule that should survive unchanged and one piece of presentation that must change.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan predicts occlusion, names a consistent depth convention, traces one object's lifecycle, and identifies a gameplay/presentation boundary for a raylib revisit.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The target outputs #A#B#. For unequal opaque depths in the same column, the nearer fragment wins regardless of order because a successful draw also updates stored depth. At equal depths, the <= tie policy lets the later fragment win; do not claim order independence for ties.

The key/exit rule can remain a pure gameplay decision; std::cout-based map drawing becomes window drawing. Engine input and lifecycle conventions are new integration work, not evidence that the rule itself changed.

The current labs do not constitute a general engine or complete sprite system. Their purpose is a precise explanation that can be transferred.

### What the comparison target demonstrates

The target moves B in front of the wall by changing only its depth from 6 to 3.

### Source connection

B: lines 288–289, 362–365, 99 and 149. Do not compare perpendicular wall depth with unconverted object distance.
D2: lines 17–20, 35–36, 182–207, terminal operations, fallible calls and normal
cleanup; D3: lines 3–45, mixed responsibilities worth discussing.

Lettered references resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [25 — Be the scorekeeper](../25-raylib-scorekeeper/LESSON.md). Revisit the familiar rule-design and feedback habits in the supplied raylib target range.

