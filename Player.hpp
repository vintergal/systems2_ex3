
#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <stdexcept>
#include <string>
namespace coup{
    
class Game;
class Player{
    Game* game; 
    std::string _name;
    int _coins;
    bool _isAlive;
    bool _wasSanctioned;
    std::string _role;
    bool _wasCouped;
    bool _wasArrested;
    bool _wasTaxed;
    bool _wasBribed;
    bool _preventArrest;
    protected:
        void ValidateMove(const std::string action,  Player* target = nullptr,int cost = 0);
    public:
        Player(Game& game,const std::string& name) :game(&game), _name(name), _coins(0), _isAlive(true), _wasSanctioned(false), _wasCouped(false),_wasArrested(false),_wasTaxed(false),_wasBribed(false),_preventArrest(false) {}
        Player() : game(nullptr), _name(""), _coins(0), _isAlive(true), _wasSanctioned(false), _wasCouped(false), _wasArrested(false), _wasTaxed(false), _wasBribed(false), _preventArrest(false) {}
        std::string getName() const { return _name; }
        std::string role() const { return _role; }
        void setRole(const std::string& newRole) { _role = newRole; }
        int coins() const { return _coins; }
        void gather();
        void tax();
        void bribe();
        void arrest(Player& who);
        void sanction(Player& who);
        void resetStatus();
        bool startTurn(); //return false if the player cannot start a turn, else return true
        void coup(Player& who);
        void addCoins(int amount) {
            
            _coins += amount;
        }
        void setTax(bool status) {
            _wasTaxed = status;
        }
        void setPreventArrest(bool status) {
            _preventArrest = status;
        }
        void setSanctioned(bool status) {
            _wasSanctioned = status;
        }
        void setArrested(bool status) {
            _wasArrested = status;
        }
        void setCouped(bool status) {
            _wasCouped = status;
        }
        void setBribed(bool status) {
            _wasBribed = status;
        }
        bool wasBribed() {
            return _wasBribed;
        }
        bool wasTaxed() {
            return _wasTaxed;
        }
        bool wasCouped() const {
            return _wasCouped;
        }
        bool wasArrested() const {
            return _wasArrested;
        }
        bool wasSanctioned() const {
            return _wasSanctioned;
        }
        bool isAlive() const {
            return _isAlive;
        }
    

};
}
#endif