#include <iostream>

int main()
{
    int w_cnt = 0;
    bool running = true;
    while (running) {
        char command = '?';
        std::cout << "w = walk, q = quit: ";
        if (!(std::cin >> command)) break; // Adult-supplied EOF handling.
        if (command == 'q') {
            running = false;
            w_cnt = 0;
        } else if (command == 'w') {
            w_cnt++;
            std::cout << "Walk\n";
            std::cout << w_cnt << "\n";
        } else {
            // TRY THIS: explain which commands are accepted.
            std::cout << "Unknown command\n";
        }
    }
    std::cout << "Goodbye\n";
    return 0;
}
