#include "PlayerInventory.h"
#include "../Item/Potion/Potion.h"
#include "../Utils/Input.h"
#include <iostream>
#include <limits>

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

void PlayerInventory::setPotion(Potion& setPotion) {
    potion = &setPotion;
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
    if(getTotalItemCount() < maxCapacity) {
        if(getItem(setItemValue.itemName)) {
            inventory[setItemValue.itemName].count += setItemValue.count;
        } else {
            inventory[setItemValue.itemName] = setItemValue;
        }
        std::cout << setItemValue.itemName <<" 이(가) " << setItemValue.count << "개가 인벤토리에 추가되었습니다.\n";
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
            if(inventory[itemName].count == 0) inventory.erase(itemName);
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
    while (true) {
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
        std::cout << "0. 돌아가기\n";
        std::cout << "*** 총 보유 수량 (" << itemTotalCount << "/" << maxCapacity << ")***\n";

        std::cout << "사용할 아이템 번호를 입력하세요: ";
        int useItemNumber;
        if (!readInput(useItemNumber)) continue;

        if(useItemNumber == 0) {
            break;
        } else if(useItemNumber > 0 && useItemNumber <= 3) {
            while (true) {
                auto it = inventory.begin();
                std::advance(it, useItemNumber - 1);

                int useCount;
                std::cout << "사용할 아이템 개수를 입력하세요: ";
                if (!readInput(useCount)) break;

                int isUse;
                std::cout << it->first << "을(를) 사용하시겠습니까?\n";
                std::cout << "0. 돌아가기  1. 사용하기  : ";
                if (!readInput(isUse)) break;

                if(isUse == 1) {
                    if(it->second.itemCategory == ItemCategory::Potion) {
                        potion->use(it->second.itemName, useCount);
                    } else {
                        std::cout << "사용할 수 없는 아이템입니다.\n";
                    }
                } else if (isUse != 0) {
                    std::cout << "0과 1을 입력해주세요.\n";
                    continue;
                }
                break;
            }
        } else {
            std::cout << "잘못 입력하셨습니다.\n";
        }
    }
}

