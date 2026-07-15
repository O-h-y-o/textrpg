#pragma once
#include "../Player.h"
#include "../../Monster/Monster.h"

class Mage : public Player {
public:
    Mage(PlayerStatus& hs, PlayerInventory& hi);

    void attack(Monster* monster) override;
};
