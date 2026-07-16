#pragma once
#include "../Player.h"

class Monster;

class Mage : public Player {
public:
    Mage(const std::string playerName);

    void attack(Monster* monster) override;
};
