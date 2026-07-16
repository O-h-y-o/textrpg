#include "Player.h"
#include "../Monster/Monster.h"
#include "PlayerStatus.h"
#include "PlayerEnhancement.h"
#include "../Inventory/PlayerInventory.h"
#include "../Item/Potion/Potion.h"
#include <iostream>

Player::Player(const std::string playerName, JobType job) :
playerStatus(std::make_unique<PlayerStatus>()), playerInventory(std::make_unique<PlayerInventory>()), playerName(playerName), job(job), level(1), exp(0) {
    potion = std::make_unique<Potion>(*playerInventory, *playerStatus);
    playerInventory->setPotion(*potion);
};

Player::~Player() {};

void Player::takeDamage(int damage, std::string monsterName) {
    std::cout << monsterName << "에게 공격을 받습니다.\n";
    Status* stat = &playerStatus->getStatus();
    int takeDamage = damage - stat->dp;
    if(takeDamage < 1) takeDamage = 1;
    playerStatus->plusPlayerStatus(StatusType::HP, -takeDamage);
    if(playerStatus->getStatus().hp <= 0) {
        std::cout << "@@플레이어 사망@@\n";
    }
}

PlayerStatus& Player::getPlayerStatus() {
    return *playerStatus;
}

void Player::printPlayerStatus() const {
    playerStatus->printPlayerStatus(*this);
}

PlayerEnhancement& Player::getPlayerEnhancement() {
    return *playerEnhancement;
}

PlayerInventory& Player::getPlayerInventory() {
    return *playerInventory;
}

const std::string& Player::getPlayerName() const { return playerName; }

const JobType& Player::getPlayerJob() const { return job; }

const int& Player::getPlayerLevel() const { return level; }

const int& Player::getPlayerExp() const { return exp; }

void Player::setPlayerExp(int addExp) {
    int sumExp = exp + addExp;
    int needExp = expTable.at(level);
    if(sumExp >= needExp) {
        std::cout << "\n*** 레벨업! ***\n";
        level++;
        exp = 0;
        setPlayerExp(sumExp - needExp);
        std::cout << "HP +10, MP +5, Attack +5\n";
        playerStatus->plusPlayerStatus(StatusType::HP, 10);
        playerStatus->plusPlayerStatus(StatusType::MP, 5);
        playerStatus->plusPlayerStatus(StatusType::AP, 5);
    } else {
        exp += addExp;
    }
}
