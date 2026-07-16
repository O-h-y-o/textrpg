#include "Thief.h"
#include <iostream>
#include "../../Monster/Monster.h"
#include "../PlayerStatus.h"

Thief::Thief(const std::string playerName) : Player(playerName, JobType::Thief) {
    std::cout << "* 도적을 선택하셨습니다. (공격력 + 30)\n";
    StatModifier plusAP{std::plus<int>(), 30};
    playerStatus->controlPlayerStatus(StatusType::AP, plusAP);
    std::cout << "* 표창을 던진다!\n";
};

void Thief::attack(Monster* monster) {
    std::cout << "* 표창을 던진다!\n";
    
    monster->takeDamage(playerStatus->getStatus().ap);
}
