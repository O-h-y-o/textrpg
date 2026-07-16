#pragma once
#include <string>
#include <iostream>
#include "../Types.h"

class Player;

class PlayerStatus {
private:
    Status stat;

public:
    PlayerStatus();

    void inputPlayerStatus();
    void controlPlayerStatus(StatusType st, const StatModifier& modi);
    void printPlayerStatus(const Player& player) const;
    Status& getStatus();
};
