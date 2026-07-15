#pragma once
#include <string>
#include "../../Types.h"

enum class DropItemType {
    DROP_ITEM_SLIME,
    DROP_ITEM_GOBLIN,
    DROP_ITEM_WOLF,
};

const InventoryItem SLIME_DROP = {"끈적한 젤리", 1, 0, 50, ItemCategory::Material};
const InventoryItem GOBLIN_DROP = {"고블린 가죽", 1, 0, 100, ItemCategory::Material};
const InventoryItem WOLF_DROP = {"늑대 가죽", 1, 0, 50, ItemCategory::Material};

static const std::map<DropItemType, InventoryItem> dropItemMap = {
    { DropItemType::DROP_ITEM_SLIME, SLIME_DROP },
    { DropItemType::DROP_ITEM_GOBLIN, GOBLIN_DROP },
    { DropItemType::DROP_ITEM_WOLF, WOLF_DROP },
};