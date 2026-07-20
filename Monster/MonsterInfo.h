#pragma once
#include <string>
#include "../Item/Material/MaterialInfo.h"

struct MonsterInfo {
    std::string name;
    int hp, ap, dp, exp;
    DropItemType dropItemType;
    std::string attackMessage;
};

// 던전 1단계
extern const MonsterInfo SLIME_INFO;
extern const MonsterInfo GOBLIN_INFO;
extern const MonsterInfo WOLF_INFO;

// 던전 2단계
extern const MonsterInfo ORC_INFO;
extern const MonsterInfo HOBGOBLIN_INFO;
extern const MonsterInfo DIREWOLF_INFO;

// 던전 3단계
extern const MonsterInfo OGRE_INFO;
extern const MonsterInfo TROLL_INFO;
extern const MonsterInfo WYVERN_INFO;
