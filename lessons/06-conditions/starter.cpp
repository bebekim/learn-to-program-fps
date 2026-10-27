#include <iostream>

int main()
{
    char command = '?';
    std::cout << "w = walk, q = quit: ";
    if (!(std::cin >> command)) return 0;
    if (command == 'w') {
        std::cout << "Walk\n";
    } else if (command == 'q') {
        std::cout << "Quit\n";
    } else {
        // TRY THIS: make the unknown-command response helpful.
        std::cout << "Unknown command\n";
    }
    return 0;
}
