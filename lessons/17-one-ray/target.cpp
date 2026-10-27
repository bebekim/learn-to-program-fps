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

int main()
{
    const Map map = {"#######", "#.....#", "#.....#", "#######"};
    // Teacher comparison: intended change shown here.
    Hit hit = cast_ray(map, 1.5, 1.5, 1.0, 0.0, 0.125, 10.0);
    std::cout << "Wall: " << hit.wall << "; distance: " << hit.distance
              << "; samples: " << hit.samples << "\n";
    return 0;
}
