#include "Potion.h"
#include <iostream>

Potion::Potion(PlayerInventory& inventory, PlayerStatus& status) : Item{inventory, status} {};

void Potion::use(const std::string& itemName, const int& count) {
    std::cout << "포션을 사용합니다.\n";
    RemoveItemResult result = inventory.removeItem(itemName, count);
    switch (result) {
        case RemoveItemResult::Success : {
            auto item = inventory.getItem(itemName);
            if(item->status.has_value()) {
                StatModifier p{std::plus<int>(), (item->effect) * count};
                status.controlPlayerStatus(item->status.value(), p);
            }
            break;
        }

        case RemoveItemResult::InsufficientCount :
            std::cout << "입력한 값이 보유 수량보다 큽니다.\n";
            break;

        case RemoveItemResult::NotFound :
            std::cout << "해당 아이템은 인벤토리에 없습니다.\n";
            break;
        
        default:
            break;
    }
}