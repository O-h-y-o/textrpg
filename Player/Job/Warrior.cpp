#include "Warrior.h"
#include <iostream>

Warrior::Warrior(PlayerStatus& hs, PlayerInventory& hi) : Player(hs, hi, JobType::Warrior) {
    std::cout << "* 전사로 전직하였습니다. (HP + 30)\n";
    StatModifier plusHP{std::plus<int>(), 30};
    playerStatus.controlPlayerStatus(StatusType::HP, plusHP);
    std::cout << "* 검을 휘두른다!\n";
};

void Warrior::attack(Monster* monster) {
    std::cout << "* 검을 휘두른다!\n";

    monster->takeDamage(playerStatus.getStatus().ap);
}
