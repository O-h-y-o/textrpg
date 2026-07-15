#include "PlayerInventory.h"
#include <iostream>
using namespace std;

PlayerInventory::PlayerInventory() {
    cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다.\n";
    inventory["HP 포션"] = {"HP 포션", 5, 20, 50};
    inventory["MP 포션"] = {"MP 포션", 5, 20, 50};
    cout << "===================================\n";
}

int PlayerInventory::getTotalItemCount() const {
    int total = 0;
    for (const auto& key : inventory) {
        total += key.second.count;
    }
    return total;
};

bool PlayerInventory::canUsePotion(StatusType st) {
    bool canUse = inventory[potionTypeToString(st)].count > 0;
    if(!canUse) cout << "포션이 부족합니다.\n";
    return canUse;
}

// void PlayerInventory::setPotion(StatusType st, int count) {
//     inventory[potionTypeToString(st)].count += count;
//     if(count < 0) {
//         cout << statusTypeToString(st) << " 포션을 사용합니다. ";
//     }  else {
//         cout << statusTypeToString(st) << " 포션을 추가합니다. ";
//     }
//     cout << "현재 보유중인 " << statusTypeToString(st) << " 포션: " <<  inventory[potionTypeToString(st)].count << "개\n";
// }

// void PlayerInventory::usePotion(StatusType st) {
//     setPotion(st, -1);
// }

// int PlayerInventory::getPotionEffect(StatusType st) {
//     return inventory[potionTypeToString(st)].effect;
// }

void PlayerInventory::addInventory(InventoryItem setItemValue) {
    if(getTotalItemCount() < 10) {
        if(inventory.find(setItemValue.itemName) != inventory.end()) {
            inventory[setItemValue.itemName].count += setItemValue.count;
        } else {
            inventory[setItemValue.itemName] = setItemValue;
        }
        cout << "인벤토리에 저장되었습니다.\n";
    } else {
        cout << "인벤토리에 더 이상 보관할 수 없습니다.\n";
    }
}

Inventory PlayerInventory::getInventory() {
    return inventory;
}

void PlayerInventory::showInventory() {
    int itemTotalCount = 0;
    int count = 1;
    cout << "********** 인벤토리 **********\n";
    for(auto& item : inventory) {
        itemTotalCount += item.second.count;
        cout << count << ". " << item.second.itemName;
        cout << " (" << item.second.price << "G) ";
        cout << item.second.count << "개\n";
        count++;
    }
    cout << "*** 총 보유 수량 (" << itemTotalCount << "/10) ***\n\n";
}