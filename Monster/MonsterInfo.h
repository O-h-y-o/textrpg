#pragma once
#include <string>
#include "../Item/Material/MaterialInfo.h"

struct MonsterInfo {
    std::string name;
    int hp, ap, dp, exp;
    DropItemType dropItemType;
};

const MonsterInfo SLIME_INFO = {"슬라임", 100, 20, 10, 20, DropItemType::DROP_ITEM_SLIME};
const MonsterInfo GOBLIN_INFO = {"고블린",  80, 20, 20, 20, DropItemType::DROP_ITEM_GOBLIN};
const MonsterInfo WOLF_INFO = {"늑대", 70, 25, 15, 20, DropItemType::DROP_ITEM_WOLF};
