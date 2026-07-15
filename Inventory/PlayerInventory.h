#pragma once
#include <map>
#include <string>
#include "../Types.h"
using namespace std;

class PlayerInventory {
private:
    Inventory inventory;

public:
    PlayerInventory();

    int getTotalItemCount() const;
    bool canUsePotion(StatusType st);
    void setPotion(StatusType st, int count);
    void usePotion(StatusType st);
    int getPotionEffect(StatusType st);
    void addInventory(InventoryItem setItemValue);
    Inventory getInventory();
    void showInventory();
};
