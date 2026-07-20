#include "PotionRecipe.h"

const std::vector<PotionRecipe> recipes = {
    {
        "HP 소형 포션",
        { { MaterialGroup::Dungeon1MonsterDrop, 1 } }
    },
    {
        "MP 소형 포션",
        { { MaterialGroup::Dungeon1MonsterDrop, 1 } }
    },
    {
        "HP 중형 포션",
        { { MaterialGroup::Dungeon1MonsterDrop, 1 }, 
        { MaterialGroup::Dungeon2MonsterDrop, 1 } }
    },
    {
        "MP 중형 포션",
        { { MaterialGroup::Dungeon1MonsterDrop, 1 }, 
        { MaterialGroup::Dungeon2MonsterDrop, 1 } }
    },
    {
        "HP 대형 포션",
        { { MaterialGroup::Dungeon1MonsterDrop, 1 }, 
        { MaterialGroup::Dungeon3MonsterDrop, 1 }, 
        { MaterialGroup::Dungeon3MonsterDrop, 1 } }
    },
    {
        "MP 대형 포션",
        { { MaterialGroup::Dungeon1MonsterDrop, 1 }, 
        { MaterialGroup::Dungeon3MonsterDrop, 1 }, 
        { MaterialGroup::Dungeon3MonsterDrop, 1 } }
    },
};