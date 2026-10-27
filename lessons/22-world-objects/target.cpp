#include <iostream>
#include <vector>
struct Object { double x; double y; double vx; double vy; };
int main()
{
    // Teacher comparison: intended change shown here.
    std::vector<Object> objects = {{2.0, 1.0, 0.0, 0.0}, {1.0, 1.0, 2.0, 0.0}, {4.0, 2.0, 0.0, 0.0}};
    double dt = 0.5;
    for (auto& object : objects) {
        object.x += object.vx * dt;
        object.y += object.vy * dt;
    }
    for (const auto& object : objects)
        std::cout << "Object: " << object.x << ", " << object.y << "\n";
    return 0;
}
