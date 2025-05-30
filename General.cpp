#include "General.hpp"
namespace coup{

void General::undo(Player& who) {
    Player::ValidateMove("undo", &who, 5);
    
    who.setCouped(false); // Reset the couped status
    who.addCoins(-5); // Refund the coup cost
}
}