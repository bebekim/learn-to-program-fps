# C++ lessons: understand a world before drawing it

Nathan starts at zero. The core idea is: **represent a world as data, then apply
precise rules to change that data in response to input**. Execution and feedback
connect the written rule to what actually happens.

This is a spiral course. Revisit familiar ideas in CommandLineFPS, the Javidx9 upgrade, raylib, and
Unreal, with a different question at each pass. Do not repeat identical exercises
simply because a new tool is available.

## Start with a picture

Begin [lesson 00 — Compile and run](00-compile-and-run/LESSON.md).
It reuses the [visual C++ guide](VISUAL-GUIDE.md) charts: source → compile → object
file → link → executable → run. Point to each box; no terminology quiz.
Return to its two-file linking experiment after functions. Later sections are visual
reminders alongside the lessons below. [Emacs preview setup](../docs/emacs-markdown-preview.md).

## The upward spiral: four passes

[Show the destinations first](START-HERE.md): CommandLineFPS → Javidx9
upgraded FPS → raylib → Unreal. The familiar input → rules → state → picture loop
returns at every pass. Each return adds a new demand, not a repeat of identical exercises.

### Pass 1 — CommandLineFPS

Start with lesson 00's build/run workflow, then lessons 01–14: small C++ experiments leading to a text maze.
That maze is a stepping stone, not the final picture of this pass. Lessons 15–20 then
isolate time, direction, rays, and projection on the way to the original CommandLineFPS
walking world. An adult supplies and verifies the platform-specific console scaffold.
The labs are not yet an integrated real-time FPS.

### Pass 2 — Javidx9 upgraded FPS

Keep the world and movement ideas. Revisit them with textured walls, lamps, moving
fireballs, and depth handling. Lessons 21–24 provide related small labs. The destination
is the upgraded FirstPersonShooter example in the Javidx9 collection; it is not a tour
of every unrelated example. Assembling the upgraded game remains a separate project.

### Pass 3 — raylib

Move one known interaction into a graphical window, then add continuous input,
3D presentation, aiming, and hit feedback. Preserve known movement and game-rule checks.
The existing `src/main.cpp` target range is an adult-supplied destination demo, not
an already-completed student port. Use it to show the end picture before building.

### Pass 4 — Unreal Engine

Revisit the same small interaction using actors, components, engine lifecycle,
collision, and UI. Aim for a small playable level, not a large commercial-game scope.
No Unreal project or packaged lessons are supplied yet.

Progress follows understanding, not a timetable. If a prerequisite needs another
example, revisit it within the current pass before adding more machinery.

## How to teach each lesson

The Rust [terminal-fps port](https://github.com/unrenamed/terminal-fps) is a comparison
reference, not another language track. Lessons 12, 14, 15, 22 and 24 revisit its
player data, named operations, timing and terminal lifecycle. Use the exact local
filenames and line numbers in [the reference index](references.md). The learning
changes remain C++; no Rust installation is needed. Compare what improved and
what responsibilities still need clearer boundaries.

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

## File names and audiences

| Filename | Audience and purpose |
| --- | --- |
| `LESSON.md` in every numbered folder | Nathan's teaching material: explanations, charts and exercises; adult answers are labelled within it |
| `ADULT-SETUP.md` in lesson 00 | Adult-only installation, configuration and readiness checks; complete once |
| `ADULT-INSTRUCTOR-GUIDE.md` | Adult-only guidance for teaching the course |
| `RUN-COMMANDS.md` | Quick command reminders after setup and lesson 00 |
| `COURSE-INDEX.md` | This course sequence and navigation |

Open `LESSON.md` to teach a lesson. Open adult setup only to prepare or repair the tools.

## Lesson notes

Lesson 00 introduces the toolchain and supplies hello.cpp. Lessons 01–24 contain explanations, worked predictions, guided practice,
independent challenges, understanding checks, and instructor answers. Each of those folders
includes a runnable `starter.cpp` and adult comparison `target.cpp`.
Use [RUN-COMMANDS.md](RUN-COMMANDS.md) for the common compile/run workflow.

The first 14 establish the CLI foundations. Lessons 15–20 support the CommandLineFPS destination; 21–24 support the
Javidx9 upgrade. These portable labs do not yet form integrated destination games. In 11 and 13, the starter intentionally contains the named logic fault for
Nathan to diagnose. In 14, the modular source is a reference while Nathan refactors
his own saved game one function at a time.

Adult verification: `node lessons/verify-checkpoints.mjs` from the repository root.
It builds both checkpoints per lesson and checks selected expected results,
termination, links, and cross-version state traces. It does not establish student
understanding or Windows/Geany readiness.

| Lesson | Main idea | Track |
| --- | --- | --- |
| [00 — Compile and run a C++ program](00-compile-and-run/LESSON.md) | Source text becomes an executable; running it produces observable output. | Toolchain foundations |
| [01 — Run, change, run again](01-first-program/LESSON.md) | Source text is compiled into a program; running it shows the result. | CLI foundations |
| [02 — Instructions have an order](02-instructions-and-output/LESSON.md) | Statements execute in sequence. | CLI foundations |
| [03 — Remember a value](03-variables/LESSON.md) | A named variable stores a value. | CLI foundations |
| [04 — A value can change](04-changing-state/LESSON.md) | Assignment updates the remembered value. | CLI foundations |
| [05 — Ask the player](05-input/LESSON.md) | Input supplies a value while the program runs. | CLI foundations |
| [06 — Choose an action](06-conditions/LESSON.md) | A comparison selects which instructions run. | CLI foundations |
| [07 — Ask again until quit](07-loops/LESSON.md) | A loop repeats while its condition remains true. | CLI foundations |
| [08 — Locate the player](08-coordinates/LESSON.md) | Two numbers locate a square; x is column and y is row. | CLI foundations |
| [09 — Store and query a maze](09-map-data/LESSON.md) | A representation connects a square to a stored character. | CLI foundations |
| [10 — Draw what the world remembers](10-drawing-the-map/LESSON.md) | A renderer visits stored cells and chooses what to show. | CLI foundations |
| [11 — Name a rule](11-functions-and-examples/LESSON.md) | A function answers one named question from given inputs. | CLI foundations |
| [12 — Propose, check, accept](12-valid-movement/LESSON.md) | Validate a proposed state before changing the real state. | CLI foundations |
| [13 — Finish a game you can explain](13-complete-text-maze/LESSON.md) | A game changes between named situations. | CLI foundations |
| [14 — Organise without changing the game](14-program-structure/LESSON.md) | Separate responsibilities so a change has a clear home. | CLI foundations |
| [15 — Distance depends on time](15-real-time-movement/LESSON.md) | Distance equals speed multiplied by elapsed seconds. | CommandLineFPS destination |
| [16 — Face and turn](16-direction-and-angles/LESSON.md) | Facing determines the direction of a movement vector. | CommandLineFPS destination |
| [17 — Ask what is ahead](17-one-ray/LESSON.md) | A ray samples successive positions until a stopping condition. | CommandLineFPS destination |
| [18 — Turn distance into a wall column](18-wall-projection/LESSON.md) | The same wall appears shorter when farther away. | CommandLineFPS destination |
| [19 — Build a view from columns](19-first-person-view/LESSON.md) | Repeat an understood operation for different viewing directions. | CommandLineFPS destination |
| [20 — Demonstrate and debug the FPS](20-fps-checkpoint/LESSON.md) | Evidence comes from predictions, checks and explanations. | CommandLineFPS destination |
| [21 — Choose a sample from a picture](21-wall-textures/LESSON.md) | A screen point maps to a location in texture data. | Javidx9 upgrade |
| [22 — Group information about one thing](22-world-objects/LESSON.md) | Related values describe one object; the same update can apply to many. | Javidx9 upgrade |
| [23 — Create, update and remove](23-projectiles/LESSON.md) | Objects have a lifecycle; creation and removal happen at defined points. | Javidx9 upgrade |
| [24 — Explain what is visible and who does what](24-depth-and-architecture/LESSON.md) | Visibility compares depths; architecture assigns responsibilities. | Javidx9 upgrade |
| [25 — Be the scorekeeper](25-raylib-scorekeeper/LESSON.md) | Transfer contracts, examples and tests into the supplied graphical target range. | raylib |

Lesson 25 uses the shared raylib project under `src/`, `include/`, and `tests/`;
it does not have a separate console starter. See [raylib setup](../docs/ADULT-RAYLIB-SETUP.md).
[Further raylib feature plans](raylib-next-steps.md) are future briefs, not a second numbered course.

