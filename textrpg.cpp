#include <iostream>
#include "Types.h"
#include "Player/PlayerStatus.h"
#include "Inventory/PlayerInventory.h"
#include "Player/PlayerEnhancement.h"
#include "Player/Player.h"
#include "Player/Job/Warrior.h"
#include "Player/Job/Mage.h"
#include "Player/Job/Thief.h"
#include "Player/Job/Archor.h"
#include "GameManagement/GameManagement.h"
#include <memory>

int main() {
    std::cout << "===================================\n";
    std::cout << "  [던전 탈출 텍스트 RPG]\n";
    std::cout << "===================================\n";
    std::cout << "용사의 이름을 입력해주세요: ";
    std::string inputName;
    std::cin >> inputName;
    
    std::cout << "\n" << inputName << "님, 직업을 선택해주세요!\n";
    std::cout << "1. 전사  2. 마법사  3. 도적  4. 궁수\n";
    std::cout << "선택: ";
    
    std::unique_ptr<Player> player;
    int selectJob;
    while (true) {
        std::cin >> selectJob;

        switch(selectJob) {
            case 1: player = std::make_unique<Warrior>(inputName); break;
            case 2: player = std::make_unique<Mage>(inputName); break;
            case 3: player = std::make_unique<Thief>(inputName); break;
            case 4: player = std::make_unique<Archor>(inputName); break;
            default: std::cout << "직업을 다시 선택해주세요: "; return 0;
        }

        if(selectJob > 0 && selectJob < 5) break;
    }

    player->printPlayerStatus();

    std::unique_ptr<GameManagement> gm = std::make_unique<GameManagement>(*player);

    gm->gameStart();

    gm->showMainMenu();

    return 0;
};
