#pragma once
#include <string>
#include <memory>
#include <vector>
#include "../Types.h"

class Monster;
class PlayerStatus;
class PlayerEnhancement;
class PlayerInventory;
class Potion;


class Player {
protected:
    const std::string playerName;
    std::unique_ptr<PlayerStatus> playerStatus;
    std::unique_ptr<PlayerEnhancement> playerEnhancement;
    std::unique_ptr<PlayerInventory> playerInventory;
    JobType job;
    int level;

public:
    Player(const std::string playerName, JobType job);
    virtual ~Player();

    virtual void attack(Monster* monster) = 0;
    // void printPlayerStatus();
    void takeDamage(int damage, std::string monsterName);
    PlayerStatus& getPlayerStatus();
    void printPlayerStatus() const;

    PlayerEnhancement& getPlayerEnhancement();
    PlayerInventory& getPlayerInventory();
    void obtainItem(InventoryItem setItemValue);

    // getter
    const std::string& getPlayerName() const;
    const JobType& getPlayerJob() const;
    const int& getPlayerLevel() const;
    const int& getPlayerExp() const;

    // setter
    void setPlayerLevel();
};
