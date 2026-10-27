#include "game_rules.hpp"
#include <cassert>

int score_after_shot(int score, bool hit)
{
    assert(score >= 0 && score <= target_count);
    if (hit && score < target_count) {
        return score + 1;
    }
    return score;
}
