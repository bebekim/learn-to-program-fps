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
        // Teacher comparison: intended change shown here.
        std::cout << "Use w to walk or q to quit\n";
    }
    return 0;
}
