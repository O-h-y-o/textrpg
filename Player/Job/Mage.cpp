#include "Mage.h"
#include <iostream>

Mage::Mage(PlayerStatus& hs, PlayerInventory& hi) : Player(hs, hi, JobType::Mage) {
    std::cout << "* 마법사로 전직하였습니다. (MP + 30)\n";
    StatModifier plusMP{std::plus<int>(), 30};
    playerStatus.controlPlayerStatus(StatusType::MP, plusMP);
    std::cout << "* 파이어볼 발사!\n";
};

void Mage::attack(Monster* monster) {
    std::cout << "* 파이어볼 발사!\n";

    monster->takeDamage(playerStatus.getStatus().ap);
}
