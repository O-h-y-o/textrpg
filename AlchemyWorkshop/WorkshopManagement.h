#pragma once
#include <iostream>

using namespace std;

class WorkshopManagement {
private:

public:
    WorkshopManagement() {};

    int showWorkshopMenu();
    void ControlWorkshopMenu(int choice);
    void showAllRecipes();
    void searchRecipeByName(string target);
    void searchRecipeByIngredient(string target);
};
