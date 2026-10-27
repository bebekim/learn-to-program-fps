#include <iostream>

bool is_inside_map(int x, int y, int width, int height)
{
    // Teacher comparison: intended change shown here.
    return x >= 0 && x < width && y >= 0 && y < height;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "(0,0): " << is_inside_map(0, 0, 7, 4) << "\n";
    std::cout << "(6,3): " << is_inside_map(6, 3, 7, 4) << "\n";
    std::cout << "(7,1): " << is_inside_map(7, 1, 7, 4) << "\n";
    std::cout << "(-1,1): " << is_inside_map(-1, 1, 7, 4) << "\n";
    return 0;
}
