# Lesson 25 — Be the scorekeeper

Track: raylib, after the console foundations. Use [raylib setup](../../docs/ADULT-RAYLIB-SETUP.md) to run the existing shared target-range project. Return to [the course index](../COURSE-INDEX.md).

Aim: explain a rule, predict its results, and write one small function yourself.
Allow two or three 25-minute sessions. Stop at a save point when tired.

## 1. Play and predict

Run the tests, then play. Miss, hit one sphere twice, clear the range, and reset.
Before each action, predict the score. Record what happened in `notes/journal.md`.
Can one sphere give two points? Find the line that prevents this.

Read only `game_rules.hpp`, `game_rules.cpp`, and `rules_tests.cpp` first. Ask an
adult about `int`, `bool`, `return`, and `if`; you need not understand rendering yet.
Trace `score_after_shot(2, true)` on paper, then trace `(3, true)`.
The score data is an integer from 0 through 3. Legal input is part of the contract;
negative scores are programming errors, not normal game events. The debug assert
helps catch them; it is not a general input-validation system.

## 2. Design before typing

Your task is a new pure function named `targets_remaining`. It accepts a score and
returns how many targets are left. Do not change the shooting code yet.

Write in your journal:

1. A data definition with the legal score range and what each value means.
2. A C++ signature, one-sentence purpose, input requirement, and output promise.
3. Expected results for scores 0, 1, 2, and 3, worked out by hand.
4. A template: which input and named constant will the answer depend on?
5. The invariant relating score, remaining targets, and total targets.

Explain why score 4 is outside this function's contract. What would have to change
if we wanted a range with five targets? No need to implement that today.

## 3. Examples become tests

In `rules_tests.cpp`, add explicit checks for your examples using the existing
failure counter and error-reporting pattern. Avoid `assert` in tests: release
builds can remove assertions. Declare your function in the header, add a stub body
that compiles, and run the checks. Observe at least one useful failure before
replacing the stub with your implementation. Keep expected answers literal so the
test does not merely repeat your implementation.

Run the tests again. Deliberately break the function briefly: does a test catch it?
Restore it, then optionally show the remaining count in the on-screen HUD using
`DrawText` and `TextFormat` as examples. Play after changing the display.

## 4. Refactor and explain

With tests green, improve one unclear name or repeated expression if you found one.
If no improvement is needed, explain why. Re-run tests: refactoring must preserve
behavior. Review the diff together and make a Git save point.

Done when Nathan can explain the data, contract, each example, the invariant, one
observed test failure, and why the implementation works. A working HUD alone is
not enough. Leave movement, weapons, and extra targets for later lessons.

Adult prompts: “What goes in?”, “What comes out?”, “Which example is the edge?”,
“What stays true?”, “What evidence would show this is wrong?” Give one hint at a
time. Do not supply the function body.
