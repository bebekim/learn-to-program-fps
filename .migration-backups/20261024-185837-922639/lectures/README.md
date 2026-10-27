# C++ lectures: understand a world before drawing it

Nathan starts at zero. The core idea is: **represent a world as data, then apply
precise rules to change that data in response to input**. Execution and feedback
connect the written rule to what actually happens.

This is a spiral course. Revisit the same game in CLI, raylib, and eventually
Unreal, with a different question at each pass. Do not repeat identical exercises
simply because a new tool is available.

## First pass: CLI foundations

Lectures 01–14 lead to one turn-based text maze. Early checkpoints are small,
isolated experiments; 12 combines them into a maze, 13 adds progress and ending,
and 14 reorganises those rules. They establish sequence, values,
input, decisions, repetition, coordinates, representation, functions, validation,
state transitions, and responsibility. They are learning units, not weekly deadlines.
One may require several 20–30-minute sessions. No trigonometry or real-time console
plumbing is needed to complete this pass.

Finish when Nathan can predict a command trace, implement a small rule, explain
why invalid movement is rejected, diagnose one fault, and adapt the rules to a
different maze. A compiled game alone does not meet this checkpoint.

## Second pass: raylib

After 14, the next implementation step is to move the same maze rules into an
adult-supplied raylib window/input/drawing scaffold. That maze port is not packaged
in these console lessons yet.
First keep turn-based grid movement: a new presentation should preserve known rules.
Then introduce continuous movement, elapsed time, vectors, collision geometry and
visual feedback separately. Existing src/main.cpp is an adult target-range example,
not a ready-made port of the text maze.

Lectures 15–20 contain deeper time/direction/ray/projection topics. They can be
adapted to raylib, or taken as an optional command-line rendering track.
Completing a Windows console ray caster is **not** a prerequisite for raylib.
Lectures 21–24 are optional advanced extensions, not beginner entry requirements.

## How to teach each lecture

1. Start with a working checkpoint and state the mission.
2. Demonstrate for at most a few minutes; ask for a prediction.
3. Nathan makes one small change and rebuilds.
4. Compare actual and expected behaviour; inspect a mismatch.
5. Ask for a fresh variation and a short explanation.
6. Save progress with adult help; do not overwrite student work with a target.

Use child-friendly questions first: What does it remember? What happens next?
What should happen here? Why? Gradually introduce state, contract and invariant
after concrete examples. Compiler diagnostics, rule checks and play answer different
questions; none alone proves understanding.

## Lecture notes

All 24 lectures contain explanations, worked predictions, guided practice,
independent challenges, understanding checks, and instructor answers. Each folder
includes a runnable `starter.cpp` and adult comparison `target.cpp`.
Use [SETUP.md](SETUP.md) for the common compile/run workflow.

The first 14 establish the CLI foundations. The remaining 10 are portable console
labs for deeper ideas; they do not yet form an integrated real-time FPS or raylib
port. In 11 and 13, the starter intentionally contains the named logic fault for
Nathan to diagnose. In 14, the modular source is a reference while Nathan refactors
his own saved game one function at a time.

Adult verification: `node lectures/verify-checkpoints.mjs` from the repository root.
It builds both checkpoints per lecture and checks selected expected results,
termination, links, and cross-version state traces. It does not establish student
understanding or Windows/Geany readiness.

| Lecture | Main idea | Track |
| --- | --- | --- |
| [01 — Run, change, run again](01-first-program/README.md) | Source text is compiled into a program; running it shows the result. | CLI foundations |
| [02 — Instructions have an order](02-instructions-and-output/README.md) | Statements execute in sequence. | CLI foundations |
| [03 — Remember a value](03-variables/README.md) | A named variable stores a value. | CLI foundations |
| [04 — A value can change](04-changing-state/README.md) | Assignment updates the remembered value. | CLI foundations |
| [05 — Ask the player](05-input/README.md) | Input supplies a value while the program runs. | CLI foundations |
| [06 — Choose an action](06-conditions/README.md) | A comparison selects which instructions run. | CLI foundations |
| [07 — Ask again until quit](07-loops/README.md) | A loop repeats while its condition remains true. | CLI foundations |
| [08 — Locate the player](08-coordinates/README.md) | Two numbers locate a square; x is column and y is row. | CLI foundations |
| [09 — Store and query a maze](09-map-data/README.md) | A representation connects a square to a stored character. | CLI foundations |
| [10 — Draw what the world remembers](10-drawing-the-map/README.md) | A renderer visits stored cells and chooses what to show. | CLI foundations |
| [11 — Name a rule](11-functions-and-examples/README.md) | A function answers one named question from given inputs. | CLI foundations |
| [12 — Propose, check, accept](12-valid-movement/README.md) | Validate a proposed state before changing the real state. | CLI foundations |
| [13 — Finish a game you can explain](13-complete-text-maze/README.md) | A game changes between named situations. | CLI foundations |
| [14 — Organise without changing the game](14-program-structure/README.md) | Separate responsibilities so a change has a clear home. | CLI foundations |
| [15 — Distance depends on time](15-real-time-movement/README.md) | Distance equals speed multiplied by elapsed seconds. | Deeper revisit: raylib or optional console |
| [16 — Face and turn](16-direction-and-angles/README.md) | Facing determines the direction of a movement vector. | Deeper revisit: raylib or optional console |
| [17 — Ask what is ahead](17-one-ray/README.md) | A ray samples successive positions until a stopping condition. | Deeper revisit: raylib or optional console |
| [18 — Turn distance into a wall column](18-wall-projection/README.md) | The same wall appears shorter when farther away. | Deeper revisit: raylib or optional console |
| [19 — Build a view from columns](19-first-person-view/README.md) | Repeat an understood operation for different viewing directions. | Deeper revisit: raylib or optional console |
| [20 — Demonstrate and debug the FPS](20-fps-checkpoint/README.md) | Evidence comes from predictions, checks and explanations. | Deeper revisit: raylib or optional console |
| [21 — Choose a sample from a picture](21-wall-textures/README.md) | A screen point maps to a location in texture data. | Optional extension |
| [22 — Group information about one thing](22-world-objects/README.md) | Related values describe one object; the same update can apply to many. | Optional extension |
| [23 — Create, update and remove](23-projectiles/README.md) | Objects have a lifecycle; creation and removal happen at defined points. | Optional extension |
| [24 — Explain what is visible and who does what](24-depth-and-architecture/README.md) | Visibility compares depths; architecture assigns responsibilities. | Optional extension |

