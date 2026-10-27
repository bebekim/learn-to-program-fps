#include "game_rules.hpp"
#include "raylib.h"
#include "raymath.h"
#include <array>
#include <algorithm>
#include <cstring>

// Teacher-supplied platform scaffold. Nathan changes the small rules first.
struct Target {
    Vector3 position;
    bool active;
};

std::array<Target, target_count> starting_targets()
{
    return {{{{-4.0f, 1.0f, -6.0f}, true},
             {{0.0f, 1.0f, -9.0f}, true},
             {{4.0f, 1.0f, -6.0f}, true}}};
}

int main(int argc, char** argv)
{
    const bool smoke = argc > 1 && std::strcmp(argv[1], "--smoke-test") == 0;
    InitWindow(1000, 700, "Nathan's FPS - target range");
    if (!IsWindowReady()) return 1;
    SetTargetFPS(60);
    Camera3D camera = {{0, 1.7f, 6}, {0, 1.7f, 0}, {0, 1, 0}, 65, CAMERA_PERSPECTIVE};
    auto targets = starting_targets();
    int score = 0;
    bool paused = false;
    int frames = 0;
    DisableCursor();
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_TAB)) {
            paused = !paused;
            if (paused) EnableCursor(); else DisableCursor();
        }
        if (IsKeyPressed(KEY_R)) {
            targets = starting_targets();
            score = 0;
        }
        if (!paused) {
            // World units per second; cap long frames after dragging the window.
            const float step = 4.0f * std::min(GetFrameTime(), 0.05f);
            const float forward = float(IsKeyDown(KEY_W)) - float(IsKeyDown(KEY_S));
            const float sideways = float(IsKeyDown(KEY_D)) - float(IsKeyDown(KEY_A));
            const float scale = (forward != 0 && sideways != 0) ? 0.70710678f : 1.0f;
            const Vector2 mouse = GetMouseDelta();
            UpdateCameraPro(&camera, {forward * step * scale, sideways * step * scale, 0},
                            {mouse.x * 0.07f, mouse.y * 0.07f, 0}, 0);
            // Keep the eye inside the range without changing its look direction.
            const Vector3 old = camera.position;
            camera.position.x = Clamp(camera.position.x, -10.0f, 10.0f);
            camera.position.z = Clamp(camera.position.z, -12.0f, 10.0f);
            camera.position.y = 1.7f;
            camera.target = Vector3Add(camera.target, Vector3Subtract(camera.position, old));
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                const Ray ray = {camera.position, Vector3Normalize(Vector3Subtract(camera.target, camera.position))};
                int nearest = -1;
                float distance = 1000.0f;
                for (int i = 0; i < target_count; ++i) {
                    if (!targets[i].active) continue;
                    const auto collision = GetRayCollisionSphere(ray, targets[i].position, 0.7f);
                    if (collision.hit && collision.distance < distance) {
                        nearest = i;
                        distance = collision.distance;
                    }
                }
                if (nearest >= 0) targets[nearest].active = false;
                score = score_after_shot(score, nearest >= 0);
            }
        }
        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode3D(camera);
        DrawPlane({0, 0, 0}, {24, 28}, DARKGREEN);
        DrawGrid(24, 1.0f);
        for (const auto& target : targets) {
            if (target.active) DrawSphere(target.position, 0.7f, ORANGE);
        }
        EndMode3D();
        DrawLine(490, 350, 510, 350, WHITE);
        DrawLine(500, 340, 500, 360, WHITE);
        DrawRectangle(0, 0, 1000, 92, Fade(BLACK, 0.7f));
        DrawText(TextFormat("Targets: %i / %i", score, target_count), 20, 14, 26, WHITE);
        DrawText("WASD move | Mouse aim | Click shoot | R reset | Tab release mouse | Esc quit", 20, 54, 18, WHITE);
        if (score == target_count) DrawText("Range complete! R to try again.", 260, 610, 28, YELLOW);
        if (paused) DrawText("Paused - Tab to resume", 320, 120, 24, WHITE);
        EndDrawing();
        if (smoke && ++frames >= 3) break;
    }
    EnableCursor();
    CloseWindow();
    return 0;
}
