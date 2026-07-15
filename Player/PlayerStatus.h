#pragma once
#include <string>
#include <iostream>
#include "../Types.h"

class PlayerStatus {
private:
    const std::string playerName;
    Status stat;

public:
    explicit PlayerStatus(std::string playerName) : playerName(playerName) {};

    void inputPlayerStatus(std::istream& in);
    void controlPlayerStatus(StatusType st, const StatModifier& modi);
    void printPlayerStatus();
    std::string getPlayerName();
    Status getStatus();
};
