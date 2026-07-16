#pragma once
#include "Monster.h"

class Goblin : public Monster {
public:
    Goblin(MonsterInfo mi);

    void attack(Player& player) override;
};
