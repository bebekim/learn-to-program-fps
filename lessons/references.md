# Teacher reference index

## Design and later engine references

- [How to Design Programs](https://htdp.org/) informs the design-recipe adaptation:
  describe data, purpose and allowed inputs; work examples; implement; check;
  refactor with behaviour preserved. Introduce the vocabulary gradually.
- [raylib](https://github.com/raysan5/raylib) supplies graphics and input for the
  shared target range; [its examples](https://www.raylib.com/examples.html) are API
  references. The project pins 5.5 as a teaching baseline, not a latest-version claim.
- [LimonEngine](https://github.com/enginmanap/limonEngine) is a later architecture
  comparison, not a build dependency. Inspect its current license and build
  instructions before any separate build; do not assume current platform support.

## Exact local source connections

Line numbers were checked against the local copies on 24 October 2026. They may
move after edits. Search for the named symbol as well as jumping to the line.
These are adult references, not prerequisite student reading.

- **A**: `/Users/marcus.kim/repositories/game/CommandLineFPS/CommandLineFPS.cpp`.
- **B**: `/Users/marcus.kim/repositories/game/Javidx9/ConsoleGameEngine/BiggerProjects/FirstPersonShooter/OneLoneCoder_ComandLineFPS_2.cpp`.
  The filename really spells it Comand.
- **C**: `/Users/marcus.kim/repositories/game/Javidx9/SimplyCode/OneLoneCoder_Snake.cpp`.
  Search Input, Logic, and Presentation sections.
- **D1**: `/Users/marcus.kim/repositories/game/terminal-fps/src/player.rs`.
  Lines 2–6 group player data; 25–40 name movement and turning operations.
- **D2**: `/Users/marcus.kim/repositories/game/terminal-fps/src/main.rs`.
  Lines 17–25 initialise terminal/player/clock; 35–75 handle input; 45–55 move
  and roll back on a wall; 79–171 render; 173–203 compose/display the frame;
  206–207 restore the terminal on normal exit.
- **D3**: `/Users/marcus.kim/repositories/game/terminal-fps/src/utils.rs`.
  Lines 3–11 name configuration values; 16–25 name drawing characters; 28–45
  store the map. This module mixes several responsibilities despite its name.
- Teaching structure: `/Users/marcus.kim/repositories/game/learn-to-program-game-ruby/README.md`,
  `LESSON-TEMPLATE.md`, `00-instructor-guide.md`, and `03-movement-and-walls/README.md`.

## How to use the Rust port

The terminal-fps project manually ports CommandLineFPS to Rust using crossterm.
Use it as a second organisation of familiar behaviour, not a fifth course pass or
a requirement to learn Rust. No Rust installation or build is needed for these
comparisons. Only point to data and responsibilities; the student exercises stay C++.

| Lesson | Comparison task | Exact port reference |
| --- | --- | --- |
| 12 | Distinguish coordinate updates from permission to enter a square | D1: 25–28; D2: 45–55 |
| 14 | Trace who stores, changes, validates and draws player state | D1: 2–40; D2: 22, 35–75, 173–203 |
| 15 | Distinguish elapsed-time arithmetic from held-input behaviour | D2: 25–47 |
| 22 | Compare plain related data with named operations | D1: 2–6 and 25–40 |
| 24 | Separate world rules from terminal resources and cleanup | D2: 17–20 and 206–207; D3: 3–45 |

Borrow explicit Player data, meaningful operation names and separation of terminal
interaction from world rules. Do not treat the port as a finished architecture:
most work is still in main, movement looks up map cells without an explicit bounds
check, and cleanup after the loop can be bypassed by an earlier error return.
Movement is performed when a keyboard event is read; elapsed-time multiplication
alone does not establish consistent held-key movement. These are source-review
observations, not measured runtime results. The port has not been built or run here.

Adaptation matters: A uses Windows console APIs, a flattened map, inconsistent
coordinate naming across rendering and map queries, and unchecked movement lookups.
Use x = column, y = row and map[y][x] consistently in beginner material. Validate
bounds before indexing, and test rectangular maps. Source reuse means extracting
an idea with attribution and license compliance, not presenting every original
implementation choice as a recommended pattern. If source is redistributed,
preserve the applicable upstream license and attribution.

Book pointers are from the publicly hosted C edition checked in the preceding
discussion, not a successful read of the uploaded PDF: §1.3 Data Models p.6;
§1.5 Algorithms and the Design of Programs p.20; §2.2 Iteration p.27;
§2.5 Proving Properties of Programs p.52; §§3.2–3.3 pp.90–91;
§10.2 State Machines and Automata p.530; §§12.3–12.4 pp.645–649.
These support the adult's teaching; formal proof and notation are deferred.


The four-pass destination and source demo links are in [See where we’re going](START-HERE.md).
