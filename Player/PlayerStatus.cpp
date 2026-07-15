#include "PlayerStatus.h"
using namespace std;

void PlayerStatus::inputPlayerStatus(istream& in) {
    cout << "** HP와 MP의 최소치는 50, 최대치는 500입니다.\n";

    while (true) {
        cout << "HP와 MP를 입력해주세요: ";
        in >> stat.hp >> stat.mp;
        if(stat.hp >= 50 && stat.hp <= 500 && stat.mp >= 50 && stat.mp <= 500) {
            break;
        } else {
            cout << "HP나 MP가 범위에서 벗어났습니다. 다시 입력해주세요.\n";
        }
    }

    cout << "** 공격력과 방어력의 최소치는 20, 최대치는 200입니다.\n";

    while (true) {
        cout << "공격력과 방어력를 입력해주세요: ";
        in >> stat.ap >> stat.dp;
        if(stat.ap >= 20 && stat.ap <= 200 && stat.dp >= 20 && stat.dp <= 200) {
            break;
        } else {
            cout << "공격력이나 방어력이 범위에서 벗어났습니다. 다시 입력해주세요.\n";
        }
    }
    cout << "\n";
}

void PlayerStatus::controlPlayerStatus(StatusType st, const StatModifier& modi) {
    int Status::*statusType = statusMap.at(st);
    int before = stat.*statusType;
    int after = visit([&](auto&& op) { return op(stat.*statusType, modi.value); }, modi.oper);
    stat.*statusType = after;
    int diff = after - before;
    cout << "* " << statusTypeToString(st) << "가 " << abs(diff);
    if(diff > 0) {
        cout << " 증가했습니다.";
    } else {
        cout << " 감소했습니다.";
    }
    cout << " 현재 체력: " << after << "\n";
}

void PlayerStatus::printHereStatus() {
    cout << "===================================\n";
    cout << heroName << "의 현재 능력치\n";
    cout << "HP: " << stat.hp << "    " << "MP: " << stat.mp << "\n";
    cout << "공격력: " << stat.ap << "    " << "방어력: " << stat.dp << "\n";
    cout << "===================================\n";
}

string PlayerStatus::getHeroName() {
    return heroName;
}

Status PlayerStatus::getStatus() {
    return stat;
}
