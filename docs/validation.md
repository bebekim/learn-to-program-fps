# Starter validation — 20 October 2026

Validated on macOS with AppleClang 21, CMake, and pinned raylib 5.5.

- Full Debug configure and build: passed.
- Debug CTest: passed (one executable, eight explicit scoring examples).
- Independent Release rules-only configure/build/CTest: passed.
- Graphical `--smoke-test`: passed outside the sandbox; window and OpenGL
  initialized, three frames completed, window closed, exit code 0.
- The first sandboxed launch could not reach macOS desktop services; stopped it.
- Interactive movement, aiming, hit/miss, reset and pause still need a human play check.
- Windows build/run not tested on this Mac.

The dependency emitted an old CMake compatibility warning, a macOS OpenGL
  deprecation warning, and a bundled stb_vorbis pointer-comparison warning.
No project compiler errors occurred.

Ripwire's explicit-file test gate located the scoring test with no reported
untested impacted symbols; its contract check reported no incompatible callers.
These static results do not establish coverage of graphics/input behavior.
Quality-delta and contract comparison could not establish a before/after baseline
because the starting folder had no Git history or quality snapshot.
`opcore check --changed` could not run because the starting folder was not a Git
repository. Opcore status reported degraded graph evidence. These are limitations,
not passed checks. Once a first commit exists, run the repository checks for the
next change. The README explains creating the first Git save point.

Build products were kept outside the source folder in `/private/tmp/nathan-fps-build`
and `/private/tmp/nathan-rules-release`; they are temporary and can be rebuilt using
the README. No dependencies were installed globally and no future lesson solutions
were added.
