#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::vector<std::string> map = {
        "#######", "#..#..#", "#.....#", "#######"
    };
    // TRY THIS: move only the displayed player to another floor square.
    int player_x = 1;
    int player_y = 1;
    for (int y = 0; y < static_cast<int>(map.size()); y = y + 1) {
        for (int x = 0; x < static_cast<int>(map[y].size()); x = x + 1) {
            if (x == player_x && y == player_y) {
                std::cout << 'P';
            } else {
                std::cout << map[y][x];
            }
        }
        std::cout << "\n";
    }
    std::cout << "Stored cell under P: " << map[player_y][player_x] << "\n";
    return 0;
}
