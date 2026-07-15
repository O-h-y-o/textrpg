#include "PlayerStatus.h"
#include <variant>
#include <cstdlib>

void PlayerStatus::inputPlayerStatus(std::istream& in) {
    std::cout << "** HP와 MP의 최소치는 50, 최대치는 500입니다.\n";

    while (true) {
        std::cout << "HP와 MP를 입력해주세요: ";
        in >> stat.hp >> stat.mp;
        if(stat.hp >= 50 && stat.hp <= 500 && stat.mp >= 50 && stat.mp <= 500) {
            break;
        } else {
            std::cout << "HP나 MP가 범위에서 벗어났습니다. 다시 입력해주세요.\n";
        }
    }

    std::cout << "** 공격력과 방어력의 최소치는 20, 최대치는 200입니다.\n";

    while (true) {
        std::cout << "공격력과 방어력를 입력해주세요: ";
        in >> stat.ap >> stat.dp;
        if(stat.ap >= 20 && stat.ap <= 200 && stat.dp >= 20 && stat.dp <= 200) {
            break;
        } else {
            std::cout << "공격력이나 방어력이 범위에서 벗어났습니다. 다시 입력해주세요.\n";
        }
    }
    std::cout << "\n";
}

void PlayerStatus::controlPlayerStatus(StatusType st, const StatModifier& modi) {
    int Status::*statusType = statusMap.at(st);
    int before = stat.*statusType;
    int after = std::visit([&](auto&& op) { return op(stat.*statusType, modi.value); }, modi.oper);
    stat.*statusType = after;
    int diff = after - before;
    std::cout << "* " << statusTypeToString(st) << "가 " << std::abs(diff);
    if(diff > 0) {
        std::cout << " 증가했습니다.";
    } else {
        std::cout << " 감소했습니다.";
    }
    std::cout << " 현재 체력: " << after << "\n";
}

void PlayerStatus::printPlayerStatus() {
    std::cout << "===================================\n";
    std::cout << playerName << "의 현재 능력치\n";
    std::cout << "HP: " << stat.hp << "    " << "MP: " << stat.mp << "\n";
    std::cout << "공격력: " << stat.ap << "    " << "방어력: " << stat.dp << "\n";
    std::cout << "===================================\n";
}

std::string PlayerStatus::getPlayerName() {
    return playerName;
}

Status PlayerStatus::getStatus() {
    return stat;
}
