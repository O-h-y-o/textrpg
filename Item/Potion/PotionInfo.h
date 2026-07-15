#pragma once
#include <string>
#include "../../Types.h"

enum class PotionType {
    HP_POTION_SMALL,
    HP_POTION_MEDIUM,
    MP_POTION_SMALL,
    MP_POTION_MEDIUM
};

const InventoryItem HP_POTION_SMALL = {"HP 소형 포션", 1, 20, 50, ItemCategory::Potion, StatusType::HP};
const InventoryItem HP_POTION_MEDIUM = {"HP 중형 포션", 1, 45, 100, ItemCategory::Potion, StatusType::HP};
const InventoryItem MP_POTION_SMALL = {"MP 소형 포션", 1, 20, 50, ItemCategory::Potion, StatusType::MP};
const InventoryItem MP_POTION_MEDIUM = {"MP 중형 포션", 1, 45, 100, ItemCategory::Potion, StatusType::MP};
const InventoryItem AP_POTION_SMALL = {"AP 소형 포션", 1, 10, 150, ItemCategory::Potion, StatusType::AP};
const InventoryItem DP_POTION_SMALL = {"DP 소형 포션", 1, 10, 150, ItemCategory::Potion, StatusType::DP};
