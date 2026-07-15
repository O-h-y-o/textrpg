#include "iostream"
#include "Monster.h"

Monster::Monster(MonsterInfo mi) : mi(mi) {};

void Monster::takeDamage(int damage) {
    int takeDamage = damage - mi.dp;
    if(takeDamage < 1) takeDamage = 1;
    mi.hp -= takeDamage;
    cout << mi.name << "이(가) " << takeDamage << "만큼의 데미지를 입었다. 남은 체력: " << mi.hp << "\n";
    if(mi.hp <= 0) {
        cout << mi.name << " 사망, " << mi.dropItemName << " 이(가) 드랍되었습니다.\n";
    }
}

int Monster::getHP() {
    return mi.hp;
}

pair<string, int> Monster::getDropItem() {
    return {mi.dropItemName, mi.dropItemPrice};
}