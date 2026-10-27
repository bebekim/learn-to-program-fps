#include <algorithm>
#include <iostream>
#include <vector>
struct Fragment { int column; double depth; char glyph; };
int main()
{
    // All depths in this lab are perpendicular camera depth, not mixed distances.
    std::vector<double> depth = {4.0, 4.0, 4.0, 4.0, 4.0};
    std::vector<char> screen(5, '#');
    // TRY THIS: move the hidden B in front of the wall by changing only its depth.
    const std::vector<Fragment> objects = {{1, 2.0, 'A'}, {3, 6.0, 'B'}};
    for (const auto& object : objects) {
        if (object.column < 0 || object.column >= static_cast<int>(depth.size())) continue;
        if (object.depth <= depth[object.column]) {
            screen[object.column] = object.glyph;
            depth[object.column] = object.depth;
        }
    }
    for (char glyph : screen) std::cout << glyph;
    std::cout << "\n";
    return 0;
}
