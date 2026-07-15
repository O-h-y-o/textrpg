#pragma once
#include "../Inventory/PlayerInventory.h"
#include "../Player/PlayerStatus.h"

class Item {
protected:
    PlayerInventory& inventory;
    PlayerStatus& status;

public:
    Item(PlayerInventory& inventory, PlayerStatus& status);

    virtual ~Item() = default;
};