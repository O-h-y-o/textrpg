#include "Archor.h"
#include <iostream>
using namespace std;

Archor::Archor(PlayerStatus& hs, PlayerInventory& hi) : Player(hs, hi, JobType::Archor) {
    cout << "* 궁수로 전직하였습니다. (방어력 + 30)\n";
    StatModifier plusDP{plus<int>(), 30};
    playerStatus.controlPlayerStatus(StatusType::DP, plusDP);
    cout << "* 활을 쏜다!\n";
};

void Archor::attack(Monster* monster) {
    cout << "* 활을 쏜다!\n";
    
    monster->takeDamage(playerStatus.getStatus().ap);
}
