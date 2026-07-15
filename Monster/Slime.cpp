#include "Slime.h"
#include "../Player/Player.h"

Slime::Slime(MonsterInfo mi) : Monster(mi) {};

void Slime::attack(Player* player) {
    cout << "슬라임이 엉겨붙습니다.\n";
    player->takeDamage(mi.ap, mi.name);
}

