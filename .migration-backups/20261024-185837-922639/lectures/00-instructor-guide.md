# Instructor guide: three passes, different depth

## The fundamental message

A program executes instructions over represented state. Input affects which rules
run; output lets us observe the consequences. We design the rules, predict concrete
cases, then use evidence to correct our understanding or implementation.

CLI removes drawing and timing demands while this becomes familiar. It is not
valuable merely because its screen looks simpler. A real-time ASCII ray caster
already involves substantial geometry, timing and rendering complexity.

## Distinct work in each pass

| Question | CLI | raylib | Unreal |
| --- | --- | --- | --- |
| What is remembered? | Coordinates, maze, key, game status | Related values, object collections | Actors/components and engine-managed state |
| How does it change? | One command produces one update | Continuous input and timed updates | Lifecycle, controller and physics responsibilities |
| What does output mean? | Print the model | Convert world state to drawing | Engine rendering and UI integration |
| Why believe the rule? | Examples and traces, then small executable checks | Preserve rule checks; compare frame rates and visuals | Preserve gameplay checks; test engine integration |
| What gets deeper? | Exact execution and valid state | Space, time, resources and presentation | Ownership, architecture and engine conventions |

These are revisits of familiar questions with new demands. Do not immediately
rebuild a whole game in the next tool. Port one known interaction and compare it.

## Adaptation from the Ruby project

Reuse cumulative working checkpoints, tiny marked edits, predictions, short
feedback cycles, creative variations, and explanation before advancing.
Split broad Ruby lessons into smaller C++ units: compiler workflow, stored values,
assignment, conditions and loops each need their own encounter.
Keep AI-generated solutions out of student work. Adult-authored infrastructure
is allowed, clearly identified, and gradually explained.

## Using the supplied lesson packages

Every lecture contains substantive teaching notes, a runnable starter.cpp, and an
adult comparison target.cpp. Keep one active student working file; copies are
recovery aids. The early sources are small experiments, followed by the combined
maze in 12–14. The later sources isolate geometry and architecture ideas; they are
not a ready-made integrated real-time FPS.

Use [SETUP.md](SETUP.md) for build/run instructions. Run the supplied verification
script before changing checkpoints. Its expected results validate the provided
examples; they are not a grading rubric for independent student solutions.

Lectures 11 and 13 contain documented intentional logic faults. Observe their
counterexamples before showing target.cpp. Lecture 14's modular source is a
comparison, not a demand that Nathan copy a whole new program. Let him extract
one function from his own corrected lecture 13 checkpoint first.

Before teaching: run the starting checkpoint, identify the one edit, check the
ordinary and boundary examples, and verify the rescue copy independently.
For 01–14, standard C++ console input/output is enough; no raylib is required.
For real-time console work, adult supplies Windows key polling and screen handling.
Do not transplant Windows APIs into the portable beginner rules.

Start at 20–30 minutes, with a few minutes of explanation and most time spent on
prediction, small changes and discussion. Stop at a stable checkpoint.
No fixed completion dates. Separate subskills over sessions rather than lecturing
through everything written in a lecture.

## Readiness for raylib

Nathan can describe state; trace commands; write a small conditional or function;
stop a loop deliberately; explain map indices; reject walls and invalid positions;
restart consistently; and transfer a rule to a changed maze.
If syntax still needs a reference card, that alone does not block progress.

The first raylib task changes presentation only: show the same map and use
single key presses for the same one-cell moves. Preserve the row/column convention
and examples. Only afterwards add held keys, floating positions and elapsed time.

## Save points and checks

This folder currently is not a Git repository. Do not claim commits exist.
Use named local copies until an adult deliberately configures version control.
Do not initialise Git, publish, or upload just to teach an early concept.
Later, inspect diffs and save small commits with Nathan.

Use manual traces initially, then explicit expected/actual checks for pure rules.
A compiler accepts syntax and types; it does not validate game intentions.
Play checks integration and feel; it does not cover every boundary case.
Refactoring changes structure while keeping observed behaviour and rule checks.

