#include "Thief.h"
#include <iostream>

Thief::Thief(PlayerStatus& hs, PlayerInventory& hi) : Player(hs, hi, JobType::Thief) {
    std::cout << "* 도적으로 전직하였습니다. (공격력 + 30)\n";
    StatModifier plusAP{std::plus<int>(), 30};
    playerStatus.controlPlayerStatus(StatusType::AP, plusAP);
    std::cout << "* 표창을 던진다!\n";
};

void Thief::attack(Monster* monster) {
    std::cout << "* 표창을 던진다!\n";
    
    monster->takeDamage(playerStatus.getStatus().ap);
}
