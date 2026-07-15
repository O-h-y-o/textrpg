#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(PlayerStatus& hs, PlayerInventory& hi) : Player(hs, hi, JobType::Warrior) {
    cout << "* 전사로 전직하였습니다. (HP + 30)\n";
    StatModifier plusHP{plus<int>(), 30};
    playerStatus.controlPlayerStatus(StatusType::HP, plusHP);
    cout << "* 검을 휘두른다!\n";
};

void Warrior::attack(Monster* monster) {
    cout << "* 검을 휘두른다!\n";

    monster->takeDamage(playerStatus.getStatus().ap);
}
