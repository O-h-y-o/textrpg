#pragma once
#include <string>
#include "../Item.h"
#include "PotionInfo.h"

class Potion : public Item {
public:
    Potion(PlayerInventory& inventory, PlayerStatus& status);
    void use(const std::string& itemName, const int& count);
};