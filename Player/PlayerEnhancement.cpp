#include "PlayerEnhancement.h"
#include <iostream>
using namespace std;

void PlayerEnhancement::controlEnhancement() {
    while(true) {
        cout << "< 캐릭터 강화 >\n";
        cout << "1. HP UP    2. MP UP     3. 공격력 2배\n";
        cout << "4. 방어력 2배   5. 현재 능력치   0. 게임 시작\n";
        cout << "===================================\n";

        cout << "번호를 선택해주세요: ";
        int selectNum;
        cin >> selectNum;
        cout << "\n";

        switch (selectNum) {
            bool canUse;
            case 0:
                break;
            case 1: {
                StatusType hp = StatusType::HP;
                canUse = playerInventory.canUsePotion(hp);
                if(canUse) {
                    playerInventory.usePotion(hp);
                    StatModifier plusHP{plus<int>(), playerInventory.getPotionEffect(hp)};
                    playerStatus.controlPlayerStatus(hp, plusHP);
                }

                break;
            }
            case 2: {
                StatusType mp = StatusType::MP;
                canUse = playerInventory.canUsePotion(mp);
                if(canUse) {
                    playerInventory.usePotion(mp);
                    StatModifier plusMP{plus<int>(), playerInventory.getPotionEffect(mp)};
                    playerStatus.controlPlayerStatus(mp, plusMP);
                }

                break;
            }
            case 3: {
                StatModifier multipliesAP{multiplies<int>(), 2};
                playerStatus.controlPlayerStatus(StatusType::AP, multipliesAP);
                break;
            }
            case 4: {
                StatModifier multipliesDP{multiplies<int>(), 2};
                playerStatus.controlPlayerStatus(StatusType::DP, multipliesDP);
                break;
            }
            case 5: {
                playerStatus.printHereStatus();
                break;
            }
        }

        if(selectNum == 0) {
            break;
        };
    }
}
