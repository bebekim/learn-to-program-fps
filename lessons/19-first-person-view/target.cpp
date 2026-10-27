#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

struct Hit { bool wall; double distance; int samples; };
using Map = std::vector<std::string>;

// Supplied lab helper. Ray direction must have length 1, step > 0,
// limit > 0, and all values must be finite. Returns radial distance.
Hit cast_ray(const Map& map, double x, double y, double dx, double dy,
             double step, double limit)
{
    int samples = 0;
    for (double distance = 0.0; distance <= limit; distance += step) {
        ++samples;
        int col = static_cast<int>(std::floor(x + dx * distance));
        int row = static_cast<int>(std::floor(y + dy * distance));
        if (row < 0 || row >= static_cast<int>(map.size()))
            return {false, distance, samples};
        if (col < 0 || col >= static_cast<int>(map[row].size()))
            return {false, distance, samples};
        if (map[row][col] == '#') return {true, distance, samples};
    }
    return {false, limit, samples};
}

std::vector<std::string> render(const Map& map, double x, double y,
                                double angle, double fov, int width, int height)
{
    std::vector<std::string> screen(height, std::string(width, '.'));
    for (int column = 0; column < width; ++column) {
        double offset = ((column + 0.5) / width - 0.5) * fov;
        double ray_angle = angle + offset;
        Hit hit = cast_ray(map, x, y, std::sin(ray_angle), std::cos(ray_angle), 0.02, 20.0);
        if (!hit.wall) continue;
        double depth = std::max(0.1, hit.distance * std::cos(offset));
        int wall_height = std::clamp(static_cast<int>(height / depth), 1, height);
        int top = (height - wall_height) / 2;
        for (int row = top; row < top + wall_height; ++row) screen[row][column] = '#';
    }
    return screen;
}

int main()
{
    const Map map = {"#########", "#.......#", "#.......#", "#.......#", "#.......#", "#.......#", "#########"};
    // Teacher comparison: intended change shown here.
    double fov_degrees = 90.0;
    double fov = fov_degrees * 3.141592653589793 / 180.0;
    for (const auto& row : render(map, 4.5, 1.5, 0.0, fov, 31, 12))
        std::cout << row << "\n";
    return 0;
}
