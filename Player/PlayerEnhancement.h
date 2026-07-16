#pragma once
#include "../GameManagement/GameManagement.h"
// #include "../Item/Potion/Potion.h"

class Player;
class Potion;

class PlayerEnhancement  {
private:

public:
    PlayerEnhancement();

    void controlEnhancement(Player& player, Potion& potion);
};
