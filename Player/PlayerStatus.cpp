#include "PlayerStatus.h"
#include "Player.h"
#include "../Utils/Input.h"
#include <variant>
#include <cstdlib>

PlayerStatus::PlayerStatus() {
    inputPlayerStatus();
}

void PlayerStatus::inputPlayerStatus() {
    std::cout << "\n초기 능력치를 세팅해주세요!\n";
    std::cout << "** HP와 MP의 최소치는 50, 최대치는 500입니다.\n";

    readRangedPair("HP와 MP를 입력해주세요: ", stat.hp, stat.mp, 50, 500,
        "HP나 MP가 범위에서 벗어났습니다. 다시 입력해주세요.\n");

    std::cout << "** 공격력과 방어력의 최소치는 20, 최대치는 200입니다.\n";

    readRangedPair("공격력과 방어력를 입력해주세요: ", stat.ap, stat.dp, 20, 200,
        "공격력이나 방어력이 범위에서 벗어났습니다. 다시 입력해주세요.\n");
    std::cout << "\n";
}

void PlayerStatus::plusPlayerStatus(StatusType st, const int& value) {
    StatModifier plusValue{std::plus<int>(), value};
    controlPlayerStatus(st, plusValue);
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
    std::cout << " 현재 " << statusTypeToString(st) << ": " << after << "\n";
}

void PlayerStatus::printPlayerStatus(const Player& player) const {
    std::cout << "===================================\n";
    std::cout << "닉네임: " << player.getPlayerName() << " | 직업: " << jobTypeToString(player.getPlayerJob()) 
    << " | Lv." << player.getPlayerLevel() << " (" << player.getPlayerExp() 
    << "/" << expTable.at(player.getPlayerLevel()) << ")\n";
    std::cout << "HP: " << stat.hp << " | MP: " << stat.mp << " | 공격력: " << stat.ap << " | 방어력: " << stat.dp << '\n';
    std::cout << "===================================\n";
}

Status& PlayerStatus::getStatus() {
    return stat;
}
