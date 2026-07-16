#include "Player.h"
#include "../Monster/Monster.h"
#include "PlayerStatus.h"
#include "PlayerEnhancement.h"
#include "../Inventory/PlayerInventory.h"
#include <iostream>

Player::Player(const std::string playerName, JobType job) : 
playerStatus(std::make_unique<PlayerStatus>()), playerInventory(std::make_unique<PlayerInventory>()), playerName(playerName), job(job), level(1) {};

Player::~Player() {};

void Player::takeDamage(int damage, std::string monsterName) {
    std::cout << monsterName << "에게 공격을 받습니다.\n";
    Status* stat = &playerStatus->getStatus();
    int takeDamage = damage - stat->dp;
    if(takeDamage < 1) takeDamage = 1;
    StatModifier minusHP{std::minus<int>(), takeDamage};
    playerStatus->controlPlayerStatus(StatusType::HP, minusHP);
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

void Player::obtainItem(InventoryItem setItemValue) {
    playerInventory->addItem(setItemValue);
}

const std::string& Player::getPlayerName() const { return playerName; }

const JobType& Player::getPlayerJob() const { return job; }

const int& Player::getPlayerLevel() const { return level; }


void Player::setPlayerLevel() { level++; }