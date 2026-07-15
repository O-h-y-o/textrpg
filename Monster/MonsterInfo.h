#pragma once
#include <string>
using namespace std;

struct MonsterInfo {
    string name, dropItemName;
    int hp, ap, dp, dropItemPrice;
};

const MonsterInfo SLIME_INFO = {"슬라임", "끈적한 젤리", 100, 20, 10, 50};
const MonsterInfo GOBLIN_INFO = {"고블린", "고블린 가죽", 80, 20, 20, 70};
const MonsterInfo WOLF_INFO = {"늑대", "늑대 가죽", 70, 25, 15, 70};
