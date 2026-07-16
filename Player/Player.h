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

inline std::vector<int> expTable = {
    0, 100, 200, 350, 500, 700, 850, 1000, 1300, 1600
};

class Player {
protected:
    const std::string playerName;
    std::unique_ptr<PlayerStatus> playerStatus;
    std::unique_ptr<PlayerEnhancement> playerEnhancement;
    std::unique_ptr<PlayerInventory> playerInventory;
    JobType job;
    int level;
    int exp;

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

    // getter
    const std::string& getPlayerName() const;
    const JobType& getPlayerJob() const;
    const int& getPlayerLevel() const;
    const int& getPlayerExp() const;

    // setter
    void setPlayerExp(int addExp);
};
