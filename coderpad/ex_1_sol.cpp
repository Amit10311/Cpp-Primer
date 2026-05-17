#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <tuple>

class TilePosError : public std::runtime_error {
public:
    TilePosError() : std::runtime_error("Tile position error") {}
};

enum class Direction {
    UP = 0,
    UP_RIGHT = 1,
    RIGHT = 2,
    DOWN_RIGHT = 3,
    DOWN = 4,
    DOWN_LEFT = 5,
    LEFT = 6,
    UP_LEFT = 7
};

std::vector<Direction> ALL_DIRS = {
    Direction::UP, Direction::UP_RIGHT, Direction::RIGHT, Direction::DOWN_RIGHT,
    Direction::DOWN, Direction::DOWN_LEFT, Direction::LEFT, Direction::UP_LEFT
};

std::vector<Direction> CARDINAL_DIRS = {
    Direction::UP, Direction::RIGHT, Direction::DOWN, Direction::LEFT
};

std::vector<Direction> DIAGONAL_DIRS = {
    Direction::UP_RIGHT, Direction::DOWN_RIGHT, Direction::DOWN_LEFT, Direction::UP_LEFT
};

// Fix 1: forward declaration so Tile can reference Board* before Board is defined
class Board;

class Tile {
public:
    // Fix 3: std::string instead of char to hold multi-byte UTF-8 glyphs
    Tile(std::string char_data = " ") : char_data(char_data), adjacencies(8, nullptr) {}

    Tile* get_adjacent(Direction direction) {
        Tile* adj_tile = adjacencies[static_cast<int>(direction)];
        if (adj_tile == nullptr) {
            throw TilePosError();
        }
        return adj_tile;
    }

    void set_adjacencies(Board* board_owner, int x, int y);

    std::string char_data;
    std::vector<Tile*> adjacencies;
};

class Board {
public:
    Board(int width, int height) : width(width), height(height) {
        _tiles.resize(height, std::vector<Tile>(width));
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                _tiles[y][x].set_adjacencies(this, x, y);
            }
        }
    }

    Tile* get_tile(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height) {
            throw TilePosError();
        }
        return &_tiles[y][x];
    }

    std::string render() {
        std::string str_rendered_board;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                str_rendered_board += _tiles[y][x].char_data;
            }
            str_rendered_board += '\n';
        }
        return str_rendered_board;
    }

    // Fix 2: _tiles[y][x] is already a Tile, not Tile* — remove the spurious *
    Tile& operator()(int x, int y) {
        return _tiles[y][x];
    }

    int width, height;
    std::vector<std::vector<Tile>> _tiles;
};

void Tile::set_adjacencies(Board* board_owner, int x, int y) {
    static const std::vector<std::tuple<Direction, int, int>> direction_offset_coords = {
        std::make_tuple(Direction::UP,         0, -1),
        std::make_tuple(Direction::UP_RIGHT,   1, -1),
        std::make_tuple(Direction::RIGHT,      1,  0),
        std::make_tuple(Direction::DOWN_RIGHT, 1,  1),
        std::make_tuple(Direction::DOWN,       0,  1),
        std::make_tuple(Direction::DOWN_LEFT, -1,  1),
        std::make_tuple(Direction::LEFT,      -1,  0),
        std::make_tuple(Direction::UP_LEFT,   -1, -1)
    };

    for (const auto& t : direction_offset_coords) {
        Direction direc    = std::get<0>(t);
        int       offset_x = std::get<1>(t);
        int       offset_y = std::get<2>(t);
        try {
            Tile* adj_tile = board_owner->get_tile(x + offset_x, y + offset_y);
            adjacencies[static_cast<int>(direc)] = adj_tile;
        } catch (TilePosError&) {
            // pass
        }
    }
}

int main() {
    Board chess_board(8, 8);
    chess_board(7, 2).char_data = "♖";   // Fix 3: double-quoted string, not char
    chess_board(3, 4).char_data = "♛";   // Fix 3: double-quoted string, not char

    // Fix 3: vector of strings so each multi-byte glyph is kept intact
    std::vector<std::string> arrows = {"↑", "↗", "→", "↘", "↓", "↙", "←", "↖"};
    for (size_t i = 0; i < ALL_DIRS.size(); ++i) {
        Direction direc = ALL_DIRS[i];
        std::string char_arrow = arrows[i];
        Tile* tile = &chess_board(3, 4);
        try {
            while (true) {
                tile = tile->get_adjacent(direc);
                tile->char_data = char_arrow;
            }
        } catch (TilePosError&) {
            // pass
        }
    }

    std::string render_reference =
        "   ↑   ↗\n"
        "↖  ↑  ↗ \n"
        " ↖ ↑ ↗ ♖\n"
        "  ↖↑↗   \n"
        "←←←♛→→→→\n"
        "  ↙↓↘   \n"
        " ↙ ↓ ↘  \n"
        "↙  ↓  ↘ \n";
    std::string render_test = chess_board.render();
    std::cout << render_test;
    if (render_test == render_reference) {
        std::cout << "Render test passed!" << std::endl;
    } else {
        std::cout << "Render test failed!" << std::endl;
    }
    return 0;
}