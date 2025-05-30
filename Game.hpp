#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"
namespace coup
{


    class Game{
        public:
        
            Game() :  currentTurn(0) {}
            std::string turn() {
                return this->_players.at(this->currentTurn)->getName();} 
            void addPlayer( Player* player) {
                
                _players.push_back(player);
                
            }
            std::vector<std::string> players();
            void nextTurn() {
                currentTurn = (currentTurn + 1) % _players.size();
            }

        
        private:
            int currentTurn;
            std::vector<coup::Player*> _players; 
};
} 

#endif // GAME_HPP