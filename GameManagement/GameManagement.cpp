#include <random>
#include "../Player/Player.h"
#include "../GameManagement/GameManagement.h"
#include "../AlchemyWorkshop/WorkshopManagement.h"
#include "../Monster/Slime.h"
#include "../Monster/Goblin.h"
#include "../Monster/Wolf.h"

GameManagement::GameManagement(Player* player)
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
        std::cout << "1. 던전 입장\n";
        std::cout << "2. 인벤토리 확인\n";
        std::cout << "3. 포션 제작소 입장\n";
        std::cout << "0. 게임 종료\n";

        std::cout << "선택: ";
        std::cin >> choice;
        std::cout << "\n";
        if(choice >= 0 && choice <= 3) {
            ControlMainMenu(choice);
        } else {
            std::cout << "다시 선택해주세요\n";
        }
    }
}

void GameManagement::ControlMainMenu(int choice) {
    switch (choice) {
        case 1: dungeon(); break;
        case 2: player->getPlayerInventory().showInventory(); break;
        case 3: wm->showWorkshopMenu(); break;
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
        case 0: {
            monster = std::make_unique<Goblin>(GOBLIN_INFO);
            std::cout << "고블린이 나타났다!";
            break;
        }
        case 1: {
            monster = std::make_unique<Slime>(SLIME_INFO);
            std::cout << "슬라임이 나타났다!";
            break;
        }
        case 2: {
            monster = std::make_unique<Wolf>(WOLF_INFO);
            std::cout << "늑대가 나타났다!";
            break;
        }
        default:
            break;
    }

    while(player->getPlayerStatus().getStatus().hp > 0 && monster->getHP() > 0) {
        std::cout << "\n--- 플레이어 턴 ---\n";
        player->attack(monster.get());

        if(monster->getHP() > 0) {
            std::cout << "\n--- 몬스터 턴 ---\n";
            monster->attack(player);
        }
    }

    if(player->getPlayerStatus().getStatus().hp > 0) {
        player->obtainItem(monster->getDropItem());
    } else {
        gameEnd();
    }
}