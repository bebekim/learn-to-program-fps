#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::vector<std::string> map = {
        "#######", "#..#..#", "#.....#", "#######"
    };
    int x = 1;
    int y = 1;
    int moves = 0;
    char command = '?';
    std::cout << "w/a/s/d then Enter; q quits.\n";
    while (true) {
        for (int row = 0; row < static_cast<int>(map.size()); ++row) {
            for (int col = 0; col < static_cast<int>(map[row].size()); ++col) {
                std::cout << ((col == x && row == y) ? 'P' : map[row][col]);
            }
            std::cout << "\n";
        }
        if (!(std::cin >> command) || command == 'q') break;
        int next_x = x;
        int next_y = y;
        if (command == 'd') ++next_x;
        else if (command == 'a') --next_x;
        else if (command == 's') ++next_y;
        else if (command == 'w') --next_y;
        else { std::cout << "Unknown command\n"; continue; }
        bool inside = next_y >= 0 && next_y < static_cast<int>(map.size())
            && next_x >= 0 && next_x < static_cast<int>(map[0].size());
        if (!inside) { std::cout << "Outside map\n"; continue; }
        // TRY THIS: change the success message, preserving the movement rule.
        if (map[next_y][next_x] != '#') {
            x = next_x;
            y = next_y;
            ++moves;
            std::cout << "Moved\n";
        } else {
            std::cout << "Blocked\n";
        }
        std::cout << "Position: " << x << ", " << y << "; moves: " << moves << "\n";
    }
    return 0;
}
