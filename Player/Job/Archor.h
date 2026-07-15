#pragma once
#include "../Player.h"
#include "../../Monster/Monster.h"

class Archor : public Player {
public:
    Archor(PlayerStatus& hs, PlayerInventory& hi);

    void attack(Monster* monster) override;
};
