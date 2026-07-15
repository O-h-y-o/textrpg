#include "Wolf.h"
#include "../Player/Player.h"

Wolf::Wolf(MonsterInfo mi) : Monster(mi) {};

void Wolf::attack(Player* player) {
    cout << "늑대가 물어뜯습니다.\n";
    player->takeDamage(mi.ap, mi.name);
}

