#pragma once
#include "PlayerStatus.h"
#include "../Inventory/PlayerInventory.h"
#include "../GameManagement/GameManagement.h"
#include "../Item/Potion/Potion.h"

class PlayerEnhancement  {
private:
    PlayerStatus& playerStatus;
    PlayerInventory& playerInventory;
    Potion potion;

public:
    PlayerEnhancement(PlayerStatus& hs, PlayerInventory& hi);

    void controlEnhancement();
};
