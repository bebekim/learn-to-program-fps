# Teacher reference index

Line numbers were checked against the local copies on 24 October 2026. They may
move after edits. Search for the named symbol as well as jumping to the line.
These are adult references, not prerequisite student reading.

- **A**: `/Users/marcus.kim/repositories/edu/CommandLineFPS/CommandLineFPS.cpp`.
- **B**: `/Users/marcus.kim/repositories/edu/Javidx9/ConsoleGameEngine/BiggerProjects/FirstPersonShooter/OneLoneCoder_ComandLineFPS_2.cpp`.
  The filename really spells it Comand.
- **C**: `/Users/marcus.kim/repositories/edu/Javidx9/SimplyCode/OneLoneCoder_Snake.cpp`.
  Search Input, Logic, and Presentation sections.
- Teaching structure: `/Users/marcus.kim/repositories/game/learn-to-program-game-ruby/README.md`,
  `LESSON-TEMPLATE.md`, `00-instructor-guide.md`, and `03-movement-and-walls/README.md`.

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

