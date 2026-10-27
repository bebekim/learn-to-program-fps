#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::vector<std::string> map = {
        "#######", "#..#E.#", "#.K...#", "#.....#", "#######"
    };
    int x = 1, y = 1, moves = 0;
    bool has_key = false, won = false;
    char command = '?';
    std::cout << "w/a/s/d move, r restarts, q quits; Enter after each.\n";
    while (true) {
        for (int row = 0; row < static_cast<int>(map.size()); ++row) {
            for (int col = 0; col < static_cast<int>(map[row].size()); ++col) {
                char tile = map[row][col];
                if (tile == 'K' && has_key) tile = '.';
                if (col == x && row == y) tile = 'P';
                std::cout << tile;
            }
            std::cout << "\n";
        }
        std::cout << "Key: " << has_key << "; won: " << won << "; moves: " << moves << "\n";
        if (!(std::cin >> command) || command == 'q') break;
        if (command == 'r') {
            x = 1; y = 1; moves = 0;
            // TRY THIS: reset the key as well as the won flag.
            won = false;
            continue;
        }
        if (won) { std::cout << "Restart or quit\n"; continue; }
        int next_x = x, next_y = y;
        if (command == 'd') ++next_x;
        else if (command == 'a') --next_x;
        else if (command == 's') ++next_y;
        else if (command == 'w') --next_y;
        else { std::cout << "Unknown command\n"; continue; }
        bool inside = next_y >= 0 && next_y < static_cast<int>(map.size())
            && next_x >= 0 && next_x < static_cast<int>(map[0].size());
        if (!inside) { std::cout << "Outside map\n"; continue; }
        char tile = map[next_y][next_x];
        if (tile == '#') { std::cout << "Blocked\n"; continue; }
        if (tile == 'E' && !has_key) { std::cout << "Need key\n"; continue; }
        x = next_x; y = next_y; ++moves;
        if (tile == 'K') has_key = true;
        if (tile == 'E' && has_key) {
            won = true;
            std::cout << "You escaped\n";
        }
    }
    return 0;
}
