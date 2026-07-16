#include "Mage.h"
#include <iostream>
#include "../../Monster/Monster.h"
#include "../PlayerStatus.h"

Mage::Mage(const std::string playerName) : Player(playerName, JobType::Mage) {
    std::cout << "* 마법사를 선택하셨습니다. (MP + 30)\n";
    StatModifier plusMP{std::plus<int>(), 30};
    playerStatus->controlPlayerStatus(StatusType::MP, plusMP);
    std::cout << "* 파이어볼 발사!\n";
};

void Mage::attack(Monster* monster) {
    std::cout << "* 파이어볼 발사!\n";

    monster->takeDamage(playerStatus->getStatus().ap);
}
