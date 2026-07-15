#pragma once
#include <string>
#include <vector>
using namespace std;

struct Ingredients {
    string name;
    int amount;
};

struct PotionRecipe {
    string name;
    vector<Ingredients> ingredients;
};

vector<PotionRecipe> recipes = {
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