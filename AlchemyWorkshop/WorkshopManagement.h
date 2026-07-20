#pragma once
#include <iostream>
#include <string>
#include "PotionRecipe.h"

class PlayerInventory;

class WorkshopManagement {
private:

public:
    WorkshopManagement() {};

    int showWorkshopMenu(PlayerInventory& inventory);
    void ControlWorkshopMenu(int choice, PlayerInventory& inventory);
    void showAllRecipes();
    std::vector<PotionRecipe>::const_iterator 
    searchRecipeByName(std::string target);
    void searchRecipeByIngredient(std::string target);
    void craftPotion(PlayerInventory& inventory, const std::string& potionName);
};
