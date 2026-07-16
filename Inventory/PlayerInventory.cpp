#include "PlayerInventory.h"
#include "../Item/Potion/Potion.h"
#include <iostream>

PlayerInventory::PlayerInventory() : maxCapacity(20) {
    std::cout << "* HP, MP 소형 포션 3개, AP, DP 소형 포션 1개, 소형 포션 1개가 기본 지급됩니다.\n";
    InventoryItem hpPotion = HP_POTION_SMALL;
    InventoryItem mpPotion = MP_POTION_SMALL;
    InventoryItem apPotion = AP_POTION_SMALL;
    InventoryItem dpPotion = DP_POTION_SMALL;
    hpPotion.count = 3;
    mpPotion.count = 3;
    addItem(hpPotion);
    addItem(mpPotion);
    addItem(apPotion);
    addItem(dpPotion);
    // showInventory();
    std::cout << "===================================\n";
}

int PlayerInventory::getTotalItemCount() const {
    int total = 0;
    for (const auto& key : inventory) {
        total += key.second.count;
    }
    return total;
};

std::optional<InventoryItem> PlayerInventory::getItem(const std::string& itemName) const {
    auto it = inventory.find(itemName);
    if(it != inventory.end()) {
        return it->second;
    } else {
        return std::nullopt;
    }
}

void PlayerInventory::addItem(const InventoryItem setItemValue) {
    if(getTotalItemCount() < 10) {
        if(getItem(setItemValue.itemName)) {
            inventory[setItemValue.itemName].count += setItemValue.count;
        } else {
            inventory[setItemValue.itemName] = setItemValue;
        }
        std::cout << setItemValue.itemName <<" 이(가) " << setItemValue.count << "개 추가되었습니다.\n";
    } else {
        std::cout << "인벤토리에 더 이상 보관할 수 없습니다.\n";
    }
}

RemoveItemResult PlayerInventory::removeItem(const std::string& itemName, const int& count) {
    if(getItem(itemName)) {
        if(inventory[itemName].count < count) {
            return RemoveItemResult::InsufficientCount;
        } else {
            inventory[itemName].count -= count;
            return RemoveItemResult::Success;
        }
    } else { 
        return RemoveItemResult::NotFound;
    }
}

Inventory PlayerInventory::getInventory() const {
    return inventory;
}

void PlayerInventory::showInventory() const {
    int itemTotalCount = 0;
    int count = 1;
    std::cout << "********** 인벤토리 **********\n";
    for(auto& item : inventory) {
        itemTotalCount += item.second.count;
        std::cout << count << ". " << item.second.itemName;
        std::cout << " (" << item.second.price << "G) ";
        std::cout << item.second.count << "개\n";
        count++;
    }
    std::cout << "*** 총 보유 수량 (" << itemTotalCount << "/" << maxCapacity << ")***\n\n";
}