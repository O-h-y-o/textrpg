#pragma once
#include <iostream>

using namespace std;

class Player;
class WorkshopManagement;

class GameManagement {
private:
    bool isGameStart = false;
    Player* player = nullptr;
    unique_ptr<WorkshopManagement> wm;

public:
    GameManagement(Player* player);
    ~GameManagement();

    void gameStart();
    void gameEnd();
    int getIsGameStart();
    void showMainMenu();
    void ControlMainMenu(int choice);
    void dungeon();
};
