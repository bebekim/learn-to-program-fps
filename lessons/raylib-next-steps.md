# Later raylib feature plans

This is the raylib target-range progression for pass 3 of
CommandLineFPS → Javidx9 upgraded FPS → raylib → Unreal. The active beginner roadmap is [the lesson index](COURSE-INDEX.md).
Show [the destinations](START-HERE.md) first, then begin
the primer and CommandLineFPS foundations before the scorekeeper task below.

Advance by evidence, not a fixed birthday or calendar. Repeat a stage with a new
example if Nathan cannot explain it yet. Each stage ends with tests where useful,
a playable check and a short journal entry. [Lesson 25](25-raylib-scorekeeper/LESSON.md)
is the current scorekeeper task. The other ideas below are future briefs, not
implemented or separately numbered lessons.

| Extension | Playable goal | Construction ideas | Evidence before moving on |
| --- | --- | --- | --- |
| Scorekeeper | Explain score; show remaining targets | Integers, booleans, signatures, contracts, examples, pure functions | Student-written rule and boundary tests; explain invariant |
| Fair movement | Make a predictable walking speed | Coordinates, units, floats, elapsed time, tolerances | Predict distance at different frame rates; test a pure movement rule |
| Range boundaries | Design a wall or obstacle | Player data, radius, valid positions, collision contracts | Examples inside, touching, outside; no penetration invariant |
| Target data | Define different target kinds | Structs, arrays, iteration, state transitions | Draw data examples; explain hit-once invariant and reset |
| Shots and feedback | Add deliberate shot feedback | Ray queries vs game rules, optional results, nearest-hit examples | Hit/miss/nearest cases; keep rendering out of pure tests |
| A small challenge | Add a timer or limited shots | Enumerated game states, transitions, input validation | State table, win/lose/reset examples, regression tests |
| Grow and tidy | Extend one feature Nathan chooses | Refactoring, module boundaries, value ownership, const references | Same tests pass before/after; explain each lifetime; no needless heap allocation |
| Read another engine | Compare one path with LimonEngine | Navigation, interfaces, resources, RAII, tradeoffs | Trace input → update → draw in both projects and explain one design difference |
| Independent mini-project | Plan and finish a small FPS challenge | Requirements, task slicing, debugging, release checklist | Student-owned plan, tests, readable diff history, demonstration |

Do not add networking, a general engine framework, inheritance trees, or a large
asset pipeline before a concrete feature needs them. Introduce standard containers,
references, resource ownership and RAII as their uses arise; avoid manual new/delete
in the beginner game. Explain compiler errors one at a time. A debugger and a small
reproducing example come before random edits.

For the LimonEngine comparison, inspect its current README, license, dependencies,
and build instructions before attempting a separate checkout. Choose one subsystem,
not the entire engine. Compare our explicit rules with its organization; ask what
each approach makes easy or hard. Do not replace Nathan's project with engine code.
