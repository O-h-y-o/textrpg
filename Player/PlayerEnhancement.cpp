#include <iostream>
#include "PlayerEnhancement.h"
#include "Player.h"
#include "../Item/Potion/Potion.h"
#include "../Utils/Input.h"

PlayerEnhancement::PlayerEnhancement()  {};

void PlayerEnhancement::controlEnhancement(Player& player, Potion& potion) {
    while(true) {
        std::cout << "< 캐릭터 강화 >\n";
        std::cout << "1. HP 소형 포션 사용    2. MP 소형 포션 사용     3. 공격력 2배\n";
        std::cout << "4. 방어력 2배   5. 현재 능력치 확인   0. 게임 시작\n";
        std::cout << "===================================\n";

        std::cout << "번호를 선택해주세요: ";
        int selectNum;
        if (!readInput(selectNum)) continue;

        switch (selectNum) {
            case 0:
                break;
            case 1: {
                std::cout << "사용할 HP 소형 포션 개수를 입력해주세요: ";
                int count;
                if (!readInput(count)) continue;
                potion.use(HP_POTION_SMALL.itemName, count);
                break;
            }
            case 2: {
                std::cout << "사용할 MP 소형 포션 개수를 입력해주세요: ";
                int count;
                if (!readInput(count)) continue;
                potion.use(MP_POTION_SMALL.itemName, count);
                break;
            }
            case 3: {
                StatModifier multipliesAP{std::multiplies<int>(), 2};
                player.getPlayerStatus().controlPlayerStatus(StatusType::AP, multipliesAP);
                break;
            }
            case 4: {
                StatModifier multipliesDP{std::multiplies<int>(), 2};
                player.getPlayerStatus().controlPlayerStatus(StatusType::DP, multipliesDP);
                break;
            }
            case 5: {
                player.printPlayerStatus();
                break;
            }
        }

        if(selectNum == 0) {
            break;
        };
    }
}
