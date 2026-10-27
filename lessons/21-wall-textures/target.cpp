#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
char sample(const std::vector<std::string>& texture, double u, double v)
{
    int width = static_cast<int>(texture[0].size());
    int height = static_cast<int>(texture.size());
    int x = std::clamp(static_cast<int>(u * width), 0, width - 1);
    int y = std::clamp(static_cast<int>(v * height), 0, height - 1);
    return texture[y][x];
}
int main()
{
    const std::vector<std::string> texture = {"ABCD", "EFGH", "IJKL", "MNOP"};
    // Teacher comparison: intended change shown here.
    std::cout << "Sample: " << sample(texture, 0.75, 0.5) << "\n";
    std::cout << "Edge: " << sample(texture, 1.0, 1.0) << "\n";
    return 0;
}
