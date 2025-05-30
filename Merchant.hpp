#ifndef MERCHANT_HPP
#define MERCHANT_HPP

#include "Player.hpp"
#include "Game.hpp"
namespace coup{
class Merchant : public Player{
    public:
    Merchant(Game& game,const std::string& name) : Player(game,name) {  this->setRole("Merchant");
    game.addPlayer(this);}   
    bool undo(Player& who); 
};}

#endif // MERCHANT_HPP