#include <random>
#include "../Player/Player.h"
#include "../Player/PlayerStatus.h"
#include "../Inventory/PlayerInventory.h"
#include "../GameManagement/GameManagement.h"
#include "../AlchemyWorkshop/WorkshopManagement.h"
#include "../Utils/Input.h"
#include "../Monster/Monster.h"

namespace {
    std::unique_ptr<Monster> spawnMonster(const MonsterInfo& info) {
        std::cout << info.name << "이 나타났다!\n";
        return std::make_unique<Monster>(info);
    }
}

GameManagement::GameManagement(Player& player)
    : player(player), wm(std::make_unique<WorkshopManagement>()) {}

GameManagement::~GameManagement() = default;

void GameManagement::gameStart() {
    std::cout << "\n\n게임을 시작합니다!\n\n";
    isGameStart = true;
}

void GameManagement::gameEnd() {
    std::cout << "\n\n게임이 종료됩니다.\n\n";
    isGameStart = false;
}

int GameManagement::getIsGameStart() {
    return isGameStart;
}

void GameManagement::showMainMenu() {
    int choice;
    while(getIsGameStart()) {
        std::cout << "\n***** 메인 메뉴 *****\n";
        std::cout << "1. 던전\n";
        std::cout << "2. 인벤토리\n";
        std::cout << "3. 포션 제작소\n";
        std::cout << "4. 내 정보\n";
        std::cout << "0. 게임 종료\n";

        std::cout << "선택: ";
        if (!readInput(choice)) continue;
        std::cout << "\n";
        if(choice >= 0 && choice <= 4) {
            ControlMainMenu(choice);
        } else {
            std::cout << "다시 선택해주세요\n";
        }
    }
}

void GameManagement::ControlMainMenu(int choice) {
    switch (choice) {
        case 1: dungeon(); break;
        case 2: player.getPlayerInventory().showInventory(); break;
        case 3: wm->showWorkshopMenu(player.getPlayerInventory()); break;
        case 4: player.getPlayerStatus().printPlayerStatus(player); break;
        case 0: gameEnd(); break;
        default:
            break;
    }
}

void GameManagement::dungeon() {
    std::unique_ptr<Monster> monster;
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 2);
    int r = dist(rng);
    switch (r) {
        case 0: monster = spawnMonster(GOBLIN_INFO); break;
        case 1: monster = spawnMonster(SLIME_INFO); break;
        case 2: monster = spawnMonster(WOLF_INFO); break;
        default:
            break;
    }

    int playerChoice;
    while(player.getPlayerStatus().getStatus().hp > 0 && monster->getHP() > 0) {
        std::cout << "\n--- 플레이어 턴 ---\n";

        std::cout << "1. 공격   2. 인벤토리\n 선택: ";
        if(!readInput(playerChoice)) continue; 
        if(playerChoice == 1) {
            player.attack(monster.get());
        } else if (playerChoice == 2) {
            player.getPlayerInventory().showInventory();
        } else {
            continue;
        }

        if(monster->getHP() > 0) {
            std::cout << "\n--- 몬스터 턴 ---\n";
            monster->attack(player);
        }
    }

    if(player.getPlayerStatus().getStatus().hp > 0) {
        player.getPlayerInventory().addItem(monster->getDropItem());
        player.setPlayerExp(monster->getExp());
    } else {
        gameEnd();
    }
}