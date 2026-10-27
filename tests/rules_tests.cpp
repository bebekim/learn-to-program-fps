#include "game_rules.hpp"
#include <iostream>

int main()
{
    struct Example { int score; bool hit; int expected; };
    const Example examples[] = {
        {0, false, 0}, {0, true, 1}, {1, false, 1}, {1, true, 2},
        {2, false, 2}, {2, true, 3}, {3, false, 3}, {3, true, 3}
    };
    int failures = 0;
    // Explicit expected answers; checks remain enabled in Release builds.
    for (const auto& example : examples) {
        const int actual = score_after_shot(example.score, example.hit);
        if (actual != example.expected || actual < 0 || actual > target_count) {
            std::cerr << "Failed: score=" << example.score
                      << " hit=" << example.hit << " expected=" << example.expected
                      << " actual=" << actual << '\n';
            ++failures;
        }
    }
    return failures == 0 ? 0 : 1;
}
