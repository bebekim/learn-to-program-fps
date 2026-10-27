#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

struct Shot { double x; double y; double vx; double vy; double life; bool remove; };
bool is_floor(const std::vector<std::string>& map, double x, double y)
{
    int col = static_cast<int>(std::floor(x));
    int row = static_cast<int>(std::floor(y));
    if (row < 0 || row >= static_cast<int>(map.size())) return false;
    if (col < 0 || col >= static_cast<int>(map[row].size())) return false;
    return map[row][col] != '#';
}

int main()
{
    const std::vector<std::string> map = {"#######", "#..#..#", "#######"};
    // Teacher comparison: intended change shown here.
    std::vector<Shot> shots = {{1.5, 1.5, 0.0, 0.0, 2.0, false}};
    double dt = 0.5;
    for (auto& shot : shots) {
        shot.life -= dt;
        // Adult-supplied collision substeps: movement per substep <= 0.1.
        int steps = std::max(1, static_cast<int>(std::ceil(
            std::max(std::abs(shot.vx), std::abs(shot.vy)) * dt / 0.1)));
        for (int step = 0; step < steps && !shot.remove; ++step) {
            double next_x = shot.x + shot.vx * dt / steps;
            double next_y = shot.y + shot.vy * dt / steps;
            if (!is_floor(map, next_x, next_y)) shot.remove = true;
            else { shot.x = next_x; shot.y = next_y; }
        }
        if (shot.life <= 0.0) shot.remove = true;
    }
    std::cout << "Before cleanup: " << shots.size() << "\n";
    shots.erase(std::remove_if(shots.begin(), shots.end(),
        [](const Shot& shot) { return shot.remove; }), shots.end());
    std::cout << "After cleanup: " << shots.size() << "\n";
    return 0;
}
