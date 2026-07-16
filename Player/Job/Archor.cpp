#include "Archor.h"
#include <iostream>
#include "../../Monster/Monster.h"
#include "../PlayerStatus.h"

Archor::Archor(const std::string playerName) : Player(playerName, JobType::Archor) {
    std::cout << "* 궁수를 선택하셨습니다. (방어력 + 30)\n";
    StatModifier plusDP{std::plus<int>(), 30};
    playerStatus->controlPlayerStatus(StatusType::DP, plusDP);
    std::cout << "* 활을 쏜다!\n";
};

void Archor::attack(Monster* monster) {
    std::cout << "* 활을 쏜다!\n";
    
    int split = 3;
    for(int i = 0; i < split; i++) {
        monster->takeDamage(playerStatus->getStatus().ap / split);
    }
}
