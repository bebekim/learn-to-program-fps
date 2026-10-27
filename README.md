# Nathan's C++ FPS course

This is the single course workspace: `~/repositories/edu/learn-to-program-fps`.
All teaching material lives in **[lessons/](lessons/COURSE-INDEX.md)**. We use “lesson”
for each learning unit; there is no separate lecture sequence.

## Start here

1. [See the destinations](lessons/START-HERE.md): CommandLineFPS → Javidx9 upgraded FPS → raylib → Unreal.
2. Begin [00 — Compile and run a C++ program](lessons/00-compile-and-run/LESSON.md), using its build/run charts.
3. Continue to [01 — Run, change, run again](lessons/01-first-program/LESSON.md), then follow [the lesson index](lessons/COURSE-INDEX.md).

Nathan starts with no assumed programming knowledge. The fundamental idea is to
represent a world as data, apply precise rules to input, and predict/check the
resulting state. Revisit those ideas with greater depth at each pass.

## What is ready

| Lessons | Purpose | Material |
| --- | --- | --- |
| 00 | Install/verify the compiler, build supplied C++ and run it | Build-process charts, hello.cpp, Mac/Windows instructions |
| 01–14 | C++ foundations leading to a turn-based maze | Worked notes, exercises, instructor answers, runnable starters and comparison targets |
| 15–20 | Time, direction, ray casting and projection | Runnable isolated console labs supporting the CommandLineFPS destination |
| 21–24 | Textures, objects, projectiles and visibility | Runnable isolated labs supporting the Javidx9 upgrade |
| 25 | Apply rule design and tests to the raylib target range | Scorekeeper task using the shared graphical project |

The console labs are not yet integrated real-time destination games. The supplied
raylib target range is an adult demo and teaching scaffold, not Nathan's completed
maze port. Unreal is a later goal; no Unreal project is supplied.

## File names

Every numbered lesson uses `LESSON.md` for the teaching material.
`ADULT-SETUP.md` is the adult's one-time preparation guide in lesson 00.
The course-wide files are `lessons/COURSE-INDEX.md`,
`lessons/ADULT-INSTRUCTOR-GUIDE.md`, and `lessons/RUN-COMMANDS.md`.
Graphical preparation is `docs/ADULT-RAYLIB-SETUP.md`.

## Setup and teaching

- [Console command reference](lessons/RUN-COMMANDS.md) for lessons 00–24.
- [Instructor guide](lessons/ADULT-INSTRUCTOR-GUIDE.md) for short sessions, checkpoints and readiness.
- [raylib setup](docs/ADULT-RAYLIB-SETUP.md) for the graphical demo and lesson 25.
- [Emacs browser preview](docs/emacs-markdown-preview.md) for diagrams and shaded code.
- [Exact source references](lessons/references.md) for the original FPS examples.
- [Session journal](notes/journal.md) for predictions, observations and questions.

Keep AI-generated solutions out of student work. Adult-provided infrastructure is
labelled; Nathan makes the learning changes and explains them. Work in short sessions:

**Describe → predict → make a small change → build and run → observe → explain → refine → save.**

Use concrete examples before formal terms. Compiler diagnostics check language
rules; rule tests check expected answers; playing checks integration and feel.
Refactoring changes organisation while preserving behaviour.

## Project files

- `lessons/`: the single course index, teaching units, visual guides, setup and instructor notes.
- `src/main.cpp`: supplied raylib window, input, rendering and target-range scaffold.
- `include/game_rules.hpp`, `src/game_rules.cpp`, `tests/rules_tests.cpp`: graphical game's small rules and executable checks.
- `docs/`: platform setup, preview help and validation/migration records.
- `archives/`: recovery snapshots, outside the active learning path.

## Verify and save

From this project root, an adult can verify the lesson 00 greeting and 48 console starter/target programs:

```sh
node lessons/verify-checkpoints.mjs
```

Graphical build/test commands are in [raylib setup](docs/ADULT-RAYLIB-SETUP.md).
A successful Mac check does not establish Nathan's Windows/Geany setup or human playtesting.

Keep named working copies until version control is deliberately configured.
This folder currently has no Git metadata; no commits or uploads are implied.
If an adult chooses Git later, review diffs and save only intended files.
Do not erase a failed experiment simply to make a check pass.

The previous layout is recoverable from
`archives/course-before-lessons-consolidation-2026-10-24.tar.gz`.
The original game-folder visual materials are also archived here; its source folder
has been left untouched.
