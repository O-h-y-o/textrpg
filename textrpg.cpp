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
using namespace std;

int main() {
    cout << "===================================\n";
    cout << "  [던전 탈출 텍스트 RPG]\n";
    cout << "===================================\n";
    cout << "용사의 이름을 입력해주세요: ";
    string inputName;
    cin >> inputName;
    PlayerStatus hs(inputName);
    hs.inputPlayerStatus(cin);
    hs.printHereStatus();

    PlayerInventory hi;
    PlayerEnhancement he(hs, hi);
    he.controlEnhancement();

    cout << "< 전직 시스템 >\n";
    cout << inputName << "님, 직업을 선택해주세요!\n";
    cout << "1. 전사  2. 마법사  3. 도적  4. 궁수\n";
    cout << "선택: ";

    int selectJob;

    unique_ptr<Player> player;

    while (true) {
        cin >> selectJob;

        switch(selectJob) {
            case 1: player = make_unique<Warrior>(hs, hi); break;
            case 2: player = make_unique<Mage>(hs, hi); break;
            case 3: player = make_unique<Thief>(hs, hi); break;
            case 4: player = make_unique<Archor>(hs, hi); break;
            default: cout << "직업을 다시 선택해주세요: "; return 0;
        }

        if(selectJob > 0 && selectJob < 5) break;
    }

    player->printPlayerStatus();

    unique_ptr<GameManagement> gm = make_unique<GameManagement>(player.get());

    gm->gameStart();

    gm->showMainMenu();
     
    return 0;
};
