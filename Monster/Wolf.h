#pragma once
#include "Monster.h"

class Wolf : public Monster {
public:
    Wolf(MonsterInfo mi);

    void attack(Player& player) override;
};
