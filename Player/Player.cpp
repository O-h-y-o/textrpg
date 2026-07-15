#include "Player.h"
#include "../Monster/Monster.h"
#include <iostream>

void Player::printPlayerStatus() {
    std::cout << "===================================\n";
    std::cout << "닉네임: " << playerStatus.getPlayerName() << " | 직업: " << jobTypeToString(job) << " | Lv." << level << '\n';
    Status stat = playerStatus.getStatus();
    std::cout << "HP: " << stat.hp << " | MP: " << stat.mp << " | 공격력 : " << stat.ap << " | 방어력" << stat.ap << '\n';
    std::cout << "===================================\n";
}

void Player::takeDamage(int damage, std::string monsterName) {
    std::cout << monsterName << "에게 공격을 받습니다.\n";
    Status* stat = &playerStatus.getStatus();
    int takeDamage = damage - stat->dp;
    if(takeDamage < 1) takeDamage = 1;
    StatModifier minusHP{std::minus<int>(), takeDamage};
    playerStatus.controlPlayerStatus(StatusType::HP, minusHP);
    if(playerStatus.getStatus().hp <= 0) {
        std::cout << "@@플레이어 사망@@\n";
    }
}

PlayerStatus Player::getPlayerStatus() {
    return playerStatus;
}

PlayerInventory Player::getPlayerInventory() {
    return playerInventory;
}

void Player::obtainItem(InventoryItem setItemValue) {
    playerInventory.addItem(setItemValue);
}