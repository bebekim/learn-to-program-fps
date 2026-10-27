#include <iostream>

int main()
{
    bool running = true;
    while (running) {
        char command = '?';
        std::cout << "w = walk, q = quit: ";
        if (!(std::cin >> command)) break; // Adult-supplied EOF handling.
        if (command == 'q') {
            running = false;
        } else if (command == 'w') {
            std::cout << "Walk\n";
        } else {
            // Teacher comparison: intended change shown here.
            std::cout << "Use w to walk or q to quit\n";
        }
    }
    std::cout << "Goodbye\n";
    return 0;
}
