#ifndef GOVERNOR_HPP
#define GOVERNOR_HPP

#include "Player.hpp"
#include "Game.hpp"
namespace coup{
    class Governor : public Player{
        public:
            void tax();
            Governor(Game& game,const std::string& name) : Player(game,name) { setRole("Governor");
            game.addPlayer(this);}  
            void undo(Player& who);
           
};}

#endif // GOVERNOR_HPP