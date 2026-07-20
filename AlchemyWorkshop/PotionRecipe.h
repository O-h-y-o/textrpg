#pragma once
#include <string>
#include <vector>
#include "../Item/Material/MaterialInfo.h"

struct Ingredients {
    MaterialGroup group = MaterialGroup::None; 
    int amount;
};

struct PotionRecipe {
    std::string name;
    std::vector<Ingredients> ingredients;
};

extern const std::vector<PotionRecipe> recipes;