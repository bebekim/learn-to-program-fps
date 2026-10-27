#pragma once

// Data: a score is an integer in [0, 3]. One point per target.
constexpr int target_count = 3;

// Contract: score is in [0, target_count].
// Purpose: award one point for a hit, without exceeding target_count.
// Examples: score_after_shot(0, true) == 1; (2, false) == 2; (3, true) == 3.
int score_after_shot(int score, bool hit);
