#include "Governor.hpp"
namespace coup{
void Governor::tax() {
    Player::ValidateMove("tax");
    
    this->addCoins(3); // Add 3 coins to the Governor's balance
    this->setTax(true); // Mark that the Governor has taxed
}

void Governor::undo(Player& who) {
    Player::ValidateMove("undo", &who, 2);
    who.setTax(false); 
    if (who.role() == "Governor") {
        who.addCoins(-3); 
    }
    else {
        who.addCoins(-2); 
    }
    
}
}