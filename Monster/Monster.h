#pragma once
#include <string>
#include <utility>
#include "MonsterInfo.h"

class Player;

class Monster {
protected:
    MonsterInfo mi;

public:
    Monster(MonsterInfo mi);
    virtual ~Monster() {};

    void attack(Player& player);
    void takeDamage(int damage);
    int getHP();
    InventoryItem getDropItem();
    const int& getExp() const;
};
