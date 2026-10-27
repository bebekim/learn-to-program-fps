#include <iostream>
#include <string>
#include <vector>

// Adult-supplied grouping syntax; Nathan first extracts one familiar function.
struct State {
    int x = 1;
    int y = 1;
    int moves = 0;
    bool has_key = false;
    bool won = false;
};
using Map = std::vector<std::string>;

bool can_enter(const Map& map, int x, int y, bool has_key)
{
    if (y < 0 || y >= static_cast<int>(map.size())) return false;
    if (x < 0 || x >= static_cast<int>(map[y].size())) return false;
    char tile = map[y][x];
    return tile != '#' && (tile != 'E' || has_key);
}

void draw(const Map& map, const State& state)
{
    for (int y = 0; y < static_cast<int>(map.size()); ++y) {
        for (int x = 0; x < static_cast<int>(map[y].size()); ++x) {
            char tile = map[y][x];
            if (tile == 'K' && state.has_key) tile = '.';
            if (x == state.x && y == state.y) tile = 'P';
            std::cout << tile;
        }
        std::cout << "\n";
    }
    std::cout << "Key: " << state.has_key << "; won: " << state.won
              << "; moves: " << state.moves << "\n";
}

State update(const Map& map, State state, char command)
{
    if (command == 'r') return State{};
    if (state.won) return state;
    int x = state.x, y = state.y;
    if (command == 'd') ++x;
    else if (command == 'a') --x;
    else if (command == 's') ++y;
    else if (command == 'w') --y;
    else return state;
    if (!can_enter(map, x, y, state.has_key)) return state;
    state.x = x; state.y = y; ++state.moves;
    if (map[y][x] == 'K') state.has_key = true;
    if (map[y][x] == 'E' && state.has_key) state.won = true;
    return state;
}

int main()
{
    const Map map = { "#######", "#..#E.#", "#.K...#", "#.....#", "#######" };
    State state;
    char command = '?';
    std::cout << "w/a/s/d move, r restarts, q quits; Enter after each.\n";
    while (true) {
        draw(map, state);
        if (!(std::cin >> command) || command == 'q') break;
        // TRY THIS: extract this existing call into your own explanation of update.
        state = update(map, state, command);
    }
    return 0;
}
