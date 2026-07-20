#pragma once
#include <string>
#include <map>
#include "../../Types.h"

enum class PotionType {
    HP_POTION_SMALL,
    HP_POTION_MEDIUM,
    MP_POTION_SMALL,
    MP_POTION_MEDIUM
};

extern const InventoryItem HP_POTION_SMALL;
extern const InventoryItem HP_POTION_MEDIUM;
extern const InventoryItem HP_POTION_BIG;
extern const InventoryItem MP_POTION_SMALL;
extern const InventoryItem MP_POTION_MEDIUM;
extern const InventoryItem MP_POTION_BIG;
extern const InventoryItem AP_POTION_SMALL;
extern const InventoryItem DP_POTION_SMALL;

extern const std::map<std::string, InventoryItem> potionNameMap;
