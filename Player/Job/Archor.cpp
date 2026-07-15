#include "Archor.h"
#include <iostream>

Archor::Archor(PlayerStatus& hs, PlayerInventory& hi) : Player(hs, hi, JobType::Archor) {
    std::cout << "* 궁수로 전직하였습니다. (방어력 + 30)\n";
    StatModifier plusDP{std::plus<int>(), 30};
    playerStatus.controlPlayerStatus(StatusType::DP, plusDP);
    std::cout << "* 활을 쏜다!\n";
};

void Archor::attack(Monster* monster) {
    std::cout << "* 활을 쏜다!\n";
    
    monster->takeDamage(playerStatus.getStatus().ap);
}
