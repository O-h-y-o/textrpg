#include <iostream>
#include "Wolf.h"
#include "../Player/Player.h"

Wolf::Wolf(MonsterInfo mi) : Monster(mi) {};

void Wolf::attack(Player* player) {
    std::cout << "늑대가 물어뜯습니다.\n";
    player->takeDamage(mi.ap, mi.name);
}

