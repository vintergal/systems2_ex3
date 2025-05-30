#ifndef JUDGE_HPP
#define JUDGE_HPP

#include "Player.hpp"
#include "Game.hpp"
namespace coup{
class Judge : public Player{
    public:
    Judge(Game& game,const std::string& name) : Player(game,name) {  this->setRole("Judge");
    game.addPlayer(this);}   
    void undo(Player& who); 
};}

#endif // JUDGE_HPP