#include "MaterialInfo.h"

const InventoryItem SLIME_DROP = {"끈적한 젤리", 1, 0, 50, ItemCategory::Material};
const InventoryItem GOBLIN_DROP = {"고블린 가죽", 1, 0, 100, ItemCategory::Material};
const InventoryItem WOLF_DROP = {"늑대 가죽", 1, 0, 50, ItemCategory::Material};

const InventoryItem ORC_DROP = {"오크 어금니", 1, 0, 150, ItemCategory::Material};
const InventoryItem HOBGOBLIN_DROP = {"홉고블린의 곤봉 조각", 1, 0, 180, ItemCategory::Material};
const InventoryItem DIREWOLF_DROP = {"다이어울프의 이빨", 1, 0, 160, ItemCategory::Material};

const InventoryItem OGRE_DROP = {"오우거의 뼈", 1, 0, 350, ItemCategory::Material};
const InventoryItem TROLL_DROP = {"트롤의 재생 조직", 1, 0, 400, ItemCategory::Material};
const InventoryItem WYVERN_DROP = {"와이번의 비늘", 1, 0, 450, ItemCategory::Material};

const std::map<DropItemType, InventoryItem> dropItemMap = {
    { DropItemType::DROP_ITEM_SLIME, SLIME_DROP },
    { DropItemType::DROP_ITEM_GOBLIN, GOBLIN_DROP },
    { DropItemType::DROP_ITEM_WOLF, WOLF_DROP },
    { DropItemType::DROP_ITEM_ORC, ORC_DROP },
    { DropItemType::DROP_ITEM_HOBGOBLIN, HOBGOBLIN_DROP },
    { DropItemType::DROP_ITEM_DIREWOLF, DIREWOLF_DROP },
    { DropItemType::DROP_ITEM_OGRE, OGRE_DROP },
    { DropItemType::DROP_ITEM_TROLL, TROLL_DROP },
    { DropItemType::DROP_ITEM_WYVERN, WYVERN_DROP },
};

inline std::string materialGroupToString(MaterialGroup group) {
    switch (group) {
        case MaterialGroup::Dungeon1MonsterDrop: return "1단계 던전 몬스터 아이템";
        case MaterialGroup::Dungeon2MonsterDrop: return "2단계 던전 몬스터 아이템";
        case MaterialGroup::Dungeon3MonsterDrop: return "3단계 던전 몬스터 아이템";
        default: return "";
    }
}

const std::map<MaterialGroup, std::vector<std::string>> materialGroupItems = {
    { MaterialGroup::Dungeon1MonsterDrop, { SLIME_DROP.itemName, GOBLIN_DROP.itemName, WOLF_DROP.itemName } },
    { MaterialGroup::Dungeon2MonsterDrop, { ORC_DROP.itemName, HOBGOBLIN_DROP.itemName, DIREWOLF_DROP.itemName } },
    { MaterialGroup::Dungeon3MonsterDrop, { OGRE_DROP.itemName, TROLL_DROP.itemName, WYVERN_DROP.itemName } },
};