#pragma once
#include "../Player.h"

class Monster;

class Archor : public Player {
public:
    Archor(const std::string playerName);

    void attack(Monster* monster) override;
};
