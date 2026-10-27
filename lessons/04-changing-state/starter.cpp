#include <iostream> // Make standard output declarations available.

int main() // Main function: no parameters; returns an integer exit status.
{ // Begin the main function body.
    int moves = 0; // Declare moves and initialise it to zero.
    std::cout << "Before: " << moves << "\n"; // Write the label, current variable value, then a newline.
    // TRY THIS: make this update add two instead of one.
    moves = moves + 1; // Calculate using the old moves value, then store the result.
    std::cout << "After: " << moves << "\n"; // Write the label, current variable value, then a newline.
    moves = moves + 1; // Calculate using the old moves value, then store the result.
    std::cout << "After another move: " << moves << "\n"; // Write the label, current variable value, then a newline.
    return 0; // Finish main with a successful exit status.
} // End the main function body.
