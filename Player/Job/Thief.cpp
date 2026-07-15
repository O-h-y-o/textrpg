#include "Thief.h"
#include <iostream>
using namespace std;

Thief::Thief(PlayerStatus& hs, PlayerInventory& hi) : Player(hs, hi, JobType::Thief) {
    cout << "* 도적으로 전직하였습니다. (공격력 + 30)\n";
    StatModifier plusAP{plus<int>(), 30};
    playerStatus.controlPlayerStatus(StatusType::AP, plusAP);
    cout << "* 표창을 던진다!\n";
};

void Thief::attack(Monster* monster) {
    cout << "* 표창을 던진다!\n";
    
    monster->takeDamage(playerStatus.getStatus().ap);
}
