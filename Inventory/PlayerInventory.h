#pragma once
#include <map>
#include <string>
#include <optional>
#include "../Types.h"
#include "../ErrorCodes.h"

class PlayerInventory {
private:
    Inventory inventory;
    int maxCapacity;

public:
    PlayerInventory();

    int getTotalItemCount() const;
    std::optional<InventoryItem> getItem(const std::string& itemName) const;
    void addItem(const InventoryItem setItemValue);
    RemoveItemResult removeItem(const std::string& itemName, const int& count);
    Inventory getInventory() const;
    void showInventory() const;
};
