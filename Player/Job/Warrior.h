#pragma once
#include "../Player.h"

class Monster;

class Warrior : public Player {
public:
    Warrior(const std::string playerName);

    void attack(Monster* monster) override;
};
