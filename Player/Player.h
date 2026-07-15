#pragma once
#include "PlayerStatus.h"
#include "../Inventory/PlayerInventory.h"
#include "../Types.h"

class Monster;

class Player {
protected:
    PlayerStatus& playerStatus;
    PlayerInventory& playerInventory;
    JobType job;
    int level;

public:
    Player(PlayerStatus& hs, PlayerInventory& hi, JobType job) : playerStatus(hs), playerInventory(hi), job(job), level(1) {};
    virtual ~Player() {};

    virtual void attack(Monster* monster) = 0;
    void printPlayerStatus();
    void takeDamage(int damage, string monsterName);
    PlayerStatus getPlayerStatus();
    PlayerInventory getPlayerInventory();
    void obtainItem(InventoryItem setItemValue);
};
