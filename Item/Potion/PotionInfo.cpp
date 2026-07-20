#include "PotionInfo.h"

const InventoryItem HP_POTION_SMALL = {"HP 소형 포션", 1, 20, 50, ItemCategory::Potion, StatusType::HP};
const InventoryItem HP_POTION_MEDIUM = {"HP 중형 포션", 1, 45, 100, ItemCategory::Potion, StatusType::HP};
const InventoryItem HP_POTION_BIG = {"HP 대형 포션", 1, 90, 200, ItemCategory::Potion, StatusType::HP};
const InventoryItem MP_POTION_SMALL = {"MP 소형 포션", 1, 20, 50, ItemCategory::Potion, StatusType::MP};
const InventoryItem MP_POTION_MEDIUM = {"MP 중형 포션", 1, 45, 100, ItemCategory::Potion, StatusType::MP};
const InventoryItem MP_POTION_BIG = {"MP 대형 포션", 1, 90, 100, ItemCategory::Potion, StatusType::MP};
const InventoryItem AP_POTION_SMALL = {"AP 소형 포션", 1, 10, 150, ItemCategory::Potion, StatusType::AP};
const InventoryItem DP_POTION_SMALL = {"DP 소형 포션", 1, 10, 150, ItemCategory::Potion, StatusType::DP};

const std::map<std::string, InventoryItem> potionNameMap = {
    { HP_POTION_SMALL.itemName, HP_POTION_SMALL },
    { HP_POTION_MEDIUM.itemName, HP_POTION_MEDIUM },
    { HP_POTION_BIG.itemName, HP_POTION_BIG },
    { MP_POTION_SMALL.itemName, MP_POTION_SMALL },
    { MP_POTION_MEDIUM.itemName, MP_POTION_MEDIUM },
    { MP_POTION_BIG.itemName, MP_POTION_BIG },
};
