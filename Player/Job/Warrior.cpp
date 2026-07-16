#include "Warrior.h"
#include <iostream>
#include "../../Monster/Monster.h"
#include "../PlayerStatus.h"

Warrior::Warrior(const std::string playerName) : Player(playerName, JobType::Warrior) {
    std::cout << "* 전사를 선택하셨습니다. (HP + 30)\n";
    StatModifier plusHP{std::plus<int>(), 30};
    playerStatus->controlPlayerStatus(StatusType::HP, plusHP);
    std::cout << "* 검을 휘두른다!\n";
};

void Warrior::attack(Monster* monster) {
    std::cout << "* 검을 휘두른다!\n";

    monster->takeDamage(playerStatus->getStatus().ap);
}
