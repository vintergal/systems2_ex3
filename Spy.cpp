#include "Spy.hpp"

namespace coup {
void Spy::undo(Player& who) {
    Player::ValidateMove("undo", &who, 1);
    who.setPreventArrest(true);
}

}