# Instructor guide: four passes, increasing depth

## The fundamental message

A program executes instructions over represented state. Input affects which rules
run; output lets us observe the consequences. We design the rules, predict concrete
cases, then use evidence to correct our understanding or implementation.

CLI removes drawing and timing demands while this becomes familiar. It is not
valuable merely because its screen looks simpler. A real-time ASCII ray caster
already involves substantial geometry, timing and rendering complexity.

## Show the destination before the machinery

Open [See where we’re going](START-HERE.md). Show the original console
world, the Javidx9 upgrade, and the raylib example before opening source files.
Ask what stays the same and what gets richer. Revisit that preview at each transition.
The destination is motivation; today’s task remains a small, understandable change.

## Distinct work in each pass

| Pass | Familiar loop | What gets deeper? | Finish picture |
| --- | --- | --- | --- |
| CommandLineFPS | Input → rules → state → drawing | C++ basics, maps, time, rays and projection | Walk through a shaded text world |
| Javidx9 upgraded FPS | The same world loop | Textures, world objects, projectiles, visibility | Textured walls, lamps, and fireballs |
| raylib | The same rules in a graphical window | Camera, continuous input, 3D drawing, hit feedback | A small graphical target range |
| Unreal | The same interaction in an engine | Actors/components, lifecycle, engine collision and UI | A small playable 3D level |

This is an upward spiral. Transfer one familiar rule, identify the new responsibility,
and compare behavior. The intended order includes the Javidx9 upgrade before raylib.
Avoid making every new pass a rewrite of everything at once.

## Begin with lesson 00

After showing the destination, teach [00 — Compile and run](00-compile-and-run/LESSON.md).
The adult handles installation using its ADULT-SETUP.md. Nathan follows the source → build
→ executable → run chart and runs hello.cpp. Lesson 01 then uses this known workflow
to change the game messages. Keep the optional two-stage linking experiment for
later if the initial build is enough for one session.

## Adaptation from the Ruby project

Reuse cumulative working checkpoints, tiny marked edits, predictions, short
feedback cycles, creative variations, and explanation before advancing.
Split broad Ruby lessons into smaller C++ units: compiler workflow, stored values,
assignment, conditions and loops each need their own encounter.
Keep AI-generated solutions out of student work. Adult-authored infrastructure
is allowed, clearly identified, and gradually explained.

## Using the supplied lesson packages

Lesson 00 contains hello.cpp and an illustrated build/run walkthrough.
Lessons 01–24 each contain substantive teaching notes, a runnable starter.cpp, and an
adult comparison target.cpp. Keep one active student working file; copies are
recovery aids. The early sources are small experiments, followed by the combined
maze in 12–14. The later sources isolate geometry and architecture ideas; they are
not a ready-made integrated real-time FPS.

Use [RUN-COMMANDS.md](RUN-COMMANDS.md) for build/run instructions. Run the supplied verification
script before changing checkpoints. Its expected results validate the provided
examples; they are not a grading rubric for independent student solutions.

Lessons 11 and 13 contain documented intentional logic faults. Observe their
counterexamples before showing target.cpp. Lesson 14's modular source is a
comparison, not a demand that Nathan copy a whole new program. Let him extract
one function from his own corrected lesson 13 checkpoint first.

Before teaching: run the starting checkpoint, identify the one edit, check the
ordinary and boundary examples, and verify the rescue copy independently.
For 00–14, standard C++ console input/output is enough; no raylib is required.
For real-time console work, adult supplies Windows key polling and screen handling.
Do not transplant Windows APIs into the portable beginner rules.

Start at 20–30 minutes, with a few minutes of explanation and most time spent on
prediction, small changes and discussion. Stop at a stable checkpoint.
No fixed completion dates. Separate subskills over sessions rather than lecturing
through everything written in a lesson.

## Readiness to move up the spiral

Nathan can describe state; trace commands; write a small conditional or function;
stop a loop deliberately; explain map indices; reject walls and invalid positions;
restart consistently; and transfer a rule to a changed maze.
If syntax still needs a reference card, that alone does not block progress.

After the CommandLineFPS and Javidx9 passes, the first raylib transfer changes presentation only: show the same map and use
single key presses for the same one-cell moves. Preserve the row/column convention
and examples. Only afterwards add held keys, floating positions and elapsed time.

## Use the Rust port as a construction comparison

terminal-fps is a manual Rust port of the familiar CommandLineFPS. The adult can
point to names and responsibility boundaries without teaching Rust syntax. Start
in lesson 12 with “moving is not the same as being allowed to move.” Lesson 14
compares original globals, the port's Player and our value-returning State update.
Later revisits distinguish event input from held movement (15), data grouping from
permission rules (22), and platform resources from gameplay (24).

Each comparison includes paper examples, exact source locations and instructor
answers. Keep the existing working C++ game and its checks. Do not ask Nathan to
port Rust line by line, install Cargo, build every proposed module at once, or
assume the port's organisation proves its movement/cleanup correct.

## Save points and checks

This folder currently is not a Git repository. Do not claim commits exist.
Use named local copies until an adult deliberately configures version control.
Do not initialise Git, publish, or upload just to teach an early concept.
Later, inspect diffs and save small commits with Nathan.

Use manual traces initially, then explicit expected/actual checks for pure rules.
A compiler accepts syntax and types; it does not validate game intentions.
Play checks integration and feel; it does not cover every boundary case.
Refactoring changes structure while keeping observed behaviour and rule checks.

