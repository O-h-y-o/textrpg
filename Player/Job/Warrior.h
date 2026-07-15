#pragma once
#include "../Player.h"
#include "../../Monster/Monster.h"

class Warrior : public Player {
public:
    Warrior(PlayerStatus& hs, PlayerInventory& hi);

    void attack(Monster* monster) override;
};
