#include "Player.hpp"

#include "Game.hpp"
namespace coup{


    void Player::ValidateMove(const std::string action,  Player* target,int cost) {
        // Check if the player is alive and not sanctioned
        if (!this->isAlive()) {
            throw std::runtime_error("Player is not alive and cannot gather.");
        }
        // Check if it's the player's turn
        if (this->game->turn() != this->getName()) {
           throw std::runtime_error("It's not " + this->getName() + "'s turn.");
        }
        if (this->wasSanctioned() && (action == "tax" || action == "gather")) {
            throw std::runtime_error("Player is sanctioned and cannot perform " + action + ".");
        }
        if (!target->isAlive()) {
            throw std::runtime_error("Target player is not alive.");
        }
        if (this->role() == "Judge" && action == "undo" && !target->wasBribed()) {
            throw std::runtime_error("Judge cannot undo bribe as the player were not bribed.");
        }
        if (this->role() == "General" && action == "undo" && !target->wasCouped()) {
            throw std::runtime_error("General cannot undo coup as the player were not couped.");
        }
        if (this->role() == "Governor" && action == "undo" && !target->wasTaxed()) {
            throw std::runtime_error("Governor cannot undo tax as the player were not taxed.");
        }
        if (action == "arrest" && target->wasArrested()) {
            throw std::runtime_error("Target player is already arrested.");
        }
        
        if (this->coins() < cost) {
            throw std::runtime_error("Player does not have enough coins to perform " + action + ".");
        }
    }
    
    void Player::resetStatus() {
        // Reset the player's state at the start of their turn
        this->_wasTaxed = false;
        this->_wasBribed = false;
        this->_wasArrested = false;
        this->_wasSanctioned = false;
        this->_wasCouped = false;
    }
    bool Player::startTurn() { //return false if the player cannot start a turn, else return true
        if (this->wasCouped()) {
            this->_isAlive = false; 
            return false; 
        }
        if (this->role()=="Merchant" && this->coins() >=3) {
           this->addCoins(1); 
        }

        // Reset the player's status at the start of their turn
        this->resetStatus();
        return true;
    }
    void Player::gather() {
        this->ValidateMove("gather");
        this->_coins += 1; 

    }
    void Player::tax() {
        this->ValidateMove("tax");
        this->_coins += 2; 
        this->_wasTaxed = true;
    }
    void Player::bribe() {
        this->ValidateMove("bribe",nullptr, 4);
        this->_wasBribed = true;
        this->_coins -= 4;
    }
    void Player::arrest(Player& who) {
        this->ValidateMove("arrest", &who, 1);
        if (who.role()!="Merchant"){
            who._coins -= 2;
        }else{
            if (who.role()!="General"){
                who._coins -= 1;
            }
            this->_coins += 1;
        }
        who._wasArrested = true;
    }
    void Player::sanction(Player& who) {
        this->ValidateMove("sanction", &who, 3);
        who._wasSanctioned = true;
        this->_coins -= 3;
        if (who.role()=="Baron"){
            who.addCoins(1); 
        }
        if (who.role()=="Judge"){
            this->_coins -= 1;
        }
    }
    void Player::coup(Player& who) {
        this->ValidateMove("coup", &who, 7);
        this->_coins -= 7; 
        if (who.role()=="General") {
            who.addCoins(-5); // Refund the coup cost
        } else {
            who.setCouped(true); // Other players are also couped
        }
    }
}
