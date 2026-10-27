#include <iostream>
int main()
{
    // Teacher comparison: intended change shown here.
    double speed = 4.0;
    double one_step = speed * 1.0;
    double ten_steps = 0.0;
    for (int i = 0; i < 10; ++i) ten_steps += speed * 0.1;
    std::cout << "One second: " << one_step << "\n";
    std::cout << "Ten short updates: " << ten_steps << "\n";
    return 0;
}
