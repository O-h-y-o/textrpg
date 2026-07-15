#pragma once
#include "PlayerStatus.h"
#include "../Inventory/PlayerInventory.h"
#include "../GameManagement/GameManagement.h"

class PlayerEnhancement  {
private:
    PlayerStatus& playerStatus;
    PlayerInventory& playerInventory;

public:
    PlayerEnhancement(PlayerStatus& hs, PlayerInventory& hi) : playerStatus(hs), playerInventory(hi) {};

    void controlEnhancement();
};
