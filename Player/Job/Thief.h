#pragma once
#include "../Player.h"
#include "../../Monster/Monster.h"

class Thief : public Player {
public:
    Thief(PlayerStatus& hs, PlayerInventory& hi);

    void attack(Monster* monster) override;
};
