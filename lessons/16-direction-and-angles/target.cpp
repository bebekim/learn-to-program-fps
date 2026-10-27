#include <cmath>
#include <iomanip>
#include <iostream>
int main()
{
    constexpr double pi = 3.141592653589793;
    // Teacher comparison: intended change shown here.
    double degrees = 90.0;
    double radians = degrees * pi / 180.0;
    double dx = std::sin(radians);
    double dy = std::cos(radians);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Direction: " << dx << ", " << dy << "\n";
    std::cout << "After 2 units from (1,1): " << 1.0 + dx * 2.0
              << ", " << 1.0 + dy * 2.0 << "\n";
    return 0;
}
