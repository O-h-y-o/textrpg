#pragma once
#include "MonsterInfo.h"

class Player;

class Monster {
protected:
    MonsterInfo mi;

public:
    Monster(MonsterInfo mi);
    virtual ~Monster() {};

    virtual void attack(Player* player) = 0;
    void takeDamage(int damage);
    int getHP();
    pair<string, int> getDropItem();
};
