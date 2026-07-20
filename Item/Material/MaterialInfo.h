#pragma once
#include <string>
#include <vector>
#include "../../Types.h"

enum class DropItemType {
    DROP_ITEM_SLIME,
    DROP_ITEM_GOBLIN,
    DROP_ITEM_WOLF,
    DROP_ITEM_ORC,
    DROP_ITEM_HOBGOBLIN,
    DROP_ITEM_DIREWOLF,
    DROP_ITEM_OGRE,
    DROP_ITEM_TROLL,
    DROP_ITEM_WYVERN,
};

// 던전 1단계
extern const InventoryItem SLIME_DROP;
extern const InventoryItem GOBLIN_DROP;
extern const InventoryItem WOLF_DROP;

// 던전 2단계
extern const InventoryItem ORC_DROP;
extern const InventoryItem HOBGOBLIN_DROP;
extern const InventoryItem DIREWOLF_DROP;

// 던전 3단계
extern const InventoryItem OGRE_DROP;
extern const InventoryItem TROLL_DROP;
extern const InventoryItem WYVERN_DROP;

extern const std::map<DropItemType, InventoryItem> dropItemMap;

enum class MaterialGroup {
    None,
    Dungeon1MonsterDrop,
    Dungeon2MonsterDrop,
    Dungeon3MonsterDrop,
};

extern inline std::string materialGroupToString(MaterialGroup group);

extern const std::map<MaterialGroup, std::vector<std::string>> materialGroupItems;