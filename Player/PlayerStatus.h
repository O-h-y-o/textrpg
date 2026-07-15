#pragma once
#include <string>
#include <iostream>
#include "../Types.h"
using namespace std;

class PlayerStatus {
private:
    const string heroName;
    Status stat;

public:
    explicit PlayerStatus(string heroName) : heroName(heroName) {};

    void inputPlayerStatus(istream& in);
    void controlPlayerStatus(StatusType st, const StatModifier& modi);
    void printHereStatus();
    string getHeroName();
    Status getStatus();
};
