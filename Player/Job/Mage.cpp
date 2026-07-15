#include "Mage.h"
#include <iostream>
using namespace std;

Mage::Mage(PlayerStatus& hs, PlayerInventory& hi) : Player(hs, hi, JobType::Mage) {
    cout << "* 마법사로 전직하였습니다. (MP + 30)\n";
    StatModifier plusMP{plus<int>(), 30};
    playerStatus.controlPlayerStatus(StatusType::MP, plusMP);
    cout << "* 파이어볼 발사!\n";
};

void Mage::attack(Monster* monster) {
    cout << "* 파이어볼 발사!\n";

    monster->takeDamage(playerStatus.getStatus().ap);
}
