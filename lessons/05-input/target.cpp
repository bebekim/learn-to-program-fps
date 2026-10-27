#include <iostream> // Declares the standard input/output streams.

int main() // The program starts here; returns an integer exit status.
{
    char command = '?'; // Store one character, initially '?'.
    // Teacher comparison: intended change shown here.
    // std:: means a name in the standard library; << sends a value to output.
    std::cout << "Type one letter, then press Enter: ";
    // >> reads from standard input into command. ! means "not".
    // If the read fails (for example, input ends), return from main.
    if (!(std::cin >> command)) return 0;
    // Write the text, stored character, then a newline (\n), in order.
    std::cout << "You typed: " << command << "\n";
    return 0; // End the program successfully.
}
