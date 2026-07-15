#pragma once
#include "Monster.h"

class Slime : public Monster {
public:
    Slime(MonsterInfo mi);

    void attack(Player* player) override;
};
