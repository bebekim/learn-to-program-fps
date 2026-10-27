# 15 — Distance depends on time

Optional depth lab after CLI foundations. These portable console experiments isolate ideas for a later raylib or console-rendering implementation.

## Before you begin

14: organised rules; separate float lesson from keyboard and clock plumbing.

Files: [starter.cpp](starter.cpp) is the runnable starting point.
Keep [target.cpp](target.cpp) for the adult's comparison after the attempt.
The starter runs before any edits; its TRY THIS comment identifies the initial small change.

Use [the common compile/run instructions](../RUN-COMMANDS.md). Copy into Nathan's active
working file rather than overwriting his previous work. Do not ask him to retype
the whole supplied program.

## Explain it together

The CLI maze changes once per command. In a real-time game, updates occur repeatedly while time passes. The new question is not “how far per key command?” but “how far in this amount of time?”

Speed has units: world units per second. Elapsed time has units: seconds. Their product is distance in world units. A floating-point value can represent fractions such as 0.1, but many decimal fractions are approximate in binary.

Today's runnable lab uses supplied time values. It does not poll keys or measure a real clock. This isolates the rule before you attach it to raylib's frame time.

## Worked example — predict before running

For speed 2 units/second:

| Elapsed time | Calculation | Distance |
| --- | --- | --- |
| 0.25 s | 2 × 0.25 | 0.5 |
| 0.5 s | 2 × 0.5 | 1 |
| 1 s | 2 × 1 | 2 |

One 1-second update and ten 0.1-second updates should each cover about 2 units in empty space. They need not have identical stored floating-point bits.

Fixed displacement per frame behaves differently: at 0.1 units/frame, 30 frames cover 3 units and 60 cover 6 units. That depends on update rate rather than elapsed seconds.

## Guided practice

1. Work the distance table with a number line.
2. Run starter.cpp and compare the two update schedules.
3. Double speed to 4 and predict both totals.
4. Try a total simulated duration of 0.5 seconds using different-sized updates.
5. When moving to raylib, let an adult supply the window loop and frame time. Replace only the supplied dt with elapsed frame seconds after the arithmetic is understood.

Do not replace this with a frame-count timer while claiming it is elapsed time.

## Revisit time in the Rust port

Adult comparison after the arithmetic is secure. In D2 (`terminal-fps/src/main.rs`),
lines 25–32 use Instant to measure elapsed time. Compare the role of this clock
with a monotonic C++ clock, std::chrono::steady_clock. Do not ask Nathan to learn
Rust's time types; ask which value has the meaning “seconds since the last update.”

Then inspect D2, lines 35–47. Movement occurs when a keyboard event is read.
Ask: “If no event arrives during an update, does this branch move the player?”
No. Multiplying by elapsed time only matters on updates where the branch runs.
Event arrival and held-key state are different input models. Key-repeat events
are not automatically the same as a continuous movement command every frame.

Paper experiment: speed 2 units/second, ten updates of 0.1 seconds. If movement is
active for all ten updates, displacement is about 2. If it runs for only two of
those updates, each using that update's 0.1 seconds, displacement is about 0.4.
The formula is unchanged; the schedule of applying it is different.

Instructor answer: the port is useful for clock separation, but its source alone
does not prove frame-rate-independent held-key behaviour. Our later input adapter
must explicitly define how long movement intent remains active. These are
reasoning exercises; no runtime behaviour of the Rust port has been measured here.

## Independent challenge

Design two different update schedules totalling two seconds. Predict the final position at speed 3 in empty space.

Ask for a prediction before execution. Offer one hint at a time; do not reveal the
target as the answer to the independent challenge.

## Understanding checkpoint

Nathan calculates a new speed/time example, explains why fixed movement per frame is rate-dependent, and distinguishes the arithmetic lab from a real-time game loop.

Record three short entries: **My rule; My prediction; What happened.** Save a working
copy and stop before introducing another idea if the explanation is still uncertain.

---

## Instructor answers and troubleshooting

The unchanged totals print approximately 2 and 2; the target prints approximately 4 and 4. At speed 3 over two seconds, distance is about 6.

If Nathan multiplies by the number of frames, ask for the units. A unit calculation often exposes the mistake more clearly than a code correction.

Frame-rate-independent arithmetic alone does not make collision robust. A large update can skip a wall. Discuss bounded substeps or a swept collision query later; do not claim this lab proves all movement behaves identically at every frame rate.

### What the comparison target demonstrates

The target doubles speed only.

### Source connection

A: lines 117–128 and 140–143. Supply std::chrono::steady_clock rather than system_clock; real-time backend is Windows-specific.
D2: lines 25–47, monotonic elapsed-time measurement and event-triggered movement.

Lettered references resolve to exact local filenames in [the reference index](../references.md).
These are teacher references, not student reading prerequisites. The supplied lesson
examples are original small teaching programs; they do not copy the reference's
Windows engine infrastructure.

Next: [16 — Face and turn](../16-direction-and-angles/LESSON.md)

