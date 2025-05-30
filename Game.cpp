#include "Game.hpp"
#include "Player.hpp"
#include <vector>
#include <string>

namespace coup {
    std::vector<std::string> Game::players() {
        std::vector<std::string> playerNames;
        for (const auto& player : _players) {
            if (player->isAlive()) // Only include alive players
                playerNames.push_back(player->getName());
        }
        return playerNames;

    }
}