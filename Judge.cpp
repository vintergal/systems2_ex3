#include "Judge.hpp"
namespace coup{
void Judge::undo(Player& who) {
        Player::ValidateMove("undo", &who);
        who.setBribed(false); 
        }
    }
