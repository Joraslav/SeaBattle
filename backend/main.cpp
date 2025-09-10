#include "Ship.hpp"

using namespace game;

int main() {
    Cruiser ship;
    Destroyer ship2;
    ship2.SetPositions({{1, 1}, {1, 2}, {1, 3}});
    return 0;
}
