#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::vector<std::string> map = {
        "#######",
        "#..#..#",
        "#.....#",
        "#######"
    };
    // TRY THIS: query another known valid square; predict its character first.
    int x = 3;
    int y = 1;
    std::cout << "Cell: " << map[y][x] << "\n";
    std::cout << "Rows: " << map.size() << "\n";
    std::cout << "Columns: " << map[0].size() << "\n";
    return 0;
}
