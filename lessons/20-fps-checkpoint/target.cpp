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
    const Map rectangle = {"#######", "#.....#", "#.....#", "#######"};
    int failures = 0;
    Hit east = cast_ray(rectangle, 1.5, 1.5, 1.0, 0.0, 0.25, 10.0);
    // Teacher comparison: intended change shown here.
    if (!east.wall || std::abs(east.distance - 4.5) > 0.001) {
        std::cout << "FAIL east ray\n"; ++failures;
    }
    Hit north = cast_ray(rectangle, 1.5, 1.5, 0.0, -1.0, 0.25, 10.0);
    if (!north.wall || std::abs(north.distance - 0.75) > 0.001) {
        std::cout << "FAIL north ray\n"; ++failures;
    }
    Hit outside = cast_ray(rectangle, -0.2, 1.5, -1.0, 0.0, 0.25, 10.0);
    if (outside.wall || outside.samples != 1) {
        std::cout << "FAIL outside start\n"; ++failures;
    }
    auto image = render(rectangle, 3.5, 1.5, 0.0, 0.8, 21, 10);
    if (image.size() != 10 || image[0].size() != 21) {
        std::cout << "FAIL image dimensions\n"; ++failures;
    }
    std::cout << "Failures: " << failures << "\n";
    return failures == 0 ? 0 : 1;
}
