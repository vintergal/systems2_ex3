#ifndef BARON_HPP
#define BARON_HPP

#include "Player.hpp"
#include "Game.hpp"
namespace coup{
    class Baron : public Player{
public:
    Baron(Game& game,const std::string& name) : Player(game,name) {this->setRole("Baron");
    game.addPlayer(this);} 
    bool invest();

    };
}

#endif // BARON_HPP