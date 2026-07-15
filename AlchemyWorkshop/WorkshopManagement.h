#pragma once
#include <iostream>
#include <string>

class WorkshopManagement {
private:

public:
    WorkshopManagement() {};

    int showWorkshopMenu();
    void ControlWorkshopMenu(int choice);
    void showAllRecipes();
    void searchRecipeByName(std::string target);
    void searchRecipeByIngredient(std::string target);
};
