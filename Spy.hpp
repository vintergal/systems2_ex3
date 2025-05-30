#ifndef SPY_HPP
#define SPY_HPP

#include "Player.hpp"
#include "Game.hpp"
namespace coup{
class Spy : public Player{
    public:
    Spy(Game& game,const std::string& name) : Player(game,name) { setRole("Spy");
    game.addPlayer(this);
}  
    void undo(Player& who); 
};}

#endif // SPY_HPP