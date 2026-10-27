#include <algorithm>
#include <iostream>
int main()
{
    const int screen_height = 12;
    // TRY THIS: double distance; predict the wall height.
    double distance = 2.0;
    double near_distance = std::max(0.25, distance);
    int wall_height = std::clamp(static_cast<int>(8.0 / near_distance), 1, screen_height);
    int top = (screen_height - wall_height) / 2;
    for (int row = 0; row < screen_height; ++row) {
        bool wall = row >= top && row < top + wall_height;
        std::cout << (wall ? '#' : '.') << "\n";
    }
    std::cout << "Height: " << wall_height << "\n";
    return 0;
}
