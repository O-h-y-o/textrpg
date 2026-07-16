#pragma once
#include "../Player.h"

class Monster;

class Thief : public Player {
public:
    Thief(const std::string playerName);

    void attack(Monster* monster) override;
};
