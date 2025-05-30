#include "Baron.hpp"

namespace coup{

bool Baron::invest() {
    Player::ValidateMove("invest", nullptr, 3);
   
    this->addCoins(3); 
    return true;
}
}
