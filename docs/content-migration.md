# Consolidation into edu/learn-to-program-fps

The `edu` course is the canonical teaching project. Its 24 lessons, instructor answers,
starter/target programs, Windows workflow, raylib project, and checkpoint verifier are preserved.

Imported from the former `game/learn-to-program-fps` workspace:

- Visual C++ primer, including object files and linking, now in `lessons/VISUAL-GUIDE.md`.
- Inline diagrams added to 12 relevant lessons without replacing their practice or answers.
- Corrected Emacs/Pandoc/Mermaid browser-preview instructions and code shading.
- Root README.md as the single entry point to the merged course.

Earlier standalone HTML previews, raster/SVG experiments, patches, and the old renderer
are historical artifacts, not the current teaching path. A complete pre-migration
snapshot is retained in `archives/game-workspace-before-merge.tar.gz` for recovery.
The source folder is retained until the merged destination has been checked.

The teaching sequence is explicitly CommandLineFPS → Javidx9 upgraded FPS → raylib → Unreal. The showcase page precedes the primer and links each of the first three destinations to a demo.

## Single lesson structure — 24 October 2026

The active course now uses `lessons/` for every teaching unit and guide.
The former `lectures/` directory was moved into it. Existing diagrams and edited
teaching notes were preserved. Guides are named START-HERE.md, VISUAL-GUIDE.md and
INSTRUCTOR.md. The former standalone scorekeeper became lesson 25.
The root LECTURE.md redirect and the competing roadmap location were removed;
use README.md and lessons/README.md.

Graphical setup is in docs/raylib-setup.md, separate from the console setup.
The future raylib ideas are in lessons/raylib-next-steps.md, without a second
lesson numbering scheme. No material in the external game folder was changed.
The complete pre-consolidation layout is saved in
archives/course-before-lessons-consolidation-2026-10-24.tar.gz.

## Audience-specific filenames — 24 October 2026

Every numbered lesson's README.md was renamed to LESSON.md. The one-time installation
guide is now 00-compile-and-run/ADULT-SETUP.md. Course-wide navigation and teaching
support are COURSE-INDEX.md, ADULT-INSTRUCTOR-GUIDE.md and RUN-COMMANDS.md under lessons/.
The graphical setup is docs/ADULT-RAYLIB-SETUP.md. Links and the checkpoint verifier
use the new names. The previous layout is recoverable from
archives/course-before-role-filenames-2026-10-24.tar.gz.
