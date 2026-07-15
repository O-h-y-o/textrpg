#pragma once
#include <string>
#include <vector>

struct Ingredients {
    std::string name;
    int amount;
};

struct PotionRecipe {
    std::string name;
    std::vector<Ingredients> ingredients;
};

std::vector<PotionRecipe> recipes = {
    {
        "HP 포션",
        { {"허브", 1}, {"맑은물", 1} }
    },
    {
        "MP 포션",
        { {"허브", 1}, {"베리", 1} }
    },
    {
        "테스트",
        { {"테스트재료1", 2}, {"테스트재료2", 3}, {"테스트재료3", 1} }
    },
};