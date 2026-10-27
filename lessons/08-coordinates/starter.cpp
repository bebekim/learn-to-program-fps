#include <iostream>

int main()
{
    int x = 1;
    int y = 1;
    char command = '?';
    std::cout << "w/a/s/d then Enter; q quits. No walls yet.\n";
    while (std::cin >> command && command != 'q') {
        if (command == 'd') x = x + 1;
        if (command == 'a') x = x - 1;
        if (command == 'w') y = y - 1;
        if (command == 's') y = y + 1;
        std::cout << "Position: " << x << ", " << y << "\n";
    }
    return 0;
}
