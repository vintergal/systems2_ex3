#ifndef GENERAL_HPP
#define GENERAL_HPP

#include "Player.hpp"
#include "Game.hpp"
namespace coup{
class General : public Player{
public:
    General(Game& game,const std::string& name) : Player(game,name) { this->setRole("General");
    game.addPlayer(this);}  
    void undo(Player& who);
};
};

#endif // GENERAL_HPP