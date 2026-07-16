#include <iostream>
#include "Goblin.h"
#include "../Player/Player.h"

Goblin::Goblin(MonsterInfo mi) : Monster(mi) {};

void Goblin::attack(Player& player) {
    std::cout << "고블린이 공격합니다.\n";
    player.takeDamage(mi.ap, mi.name);
}

