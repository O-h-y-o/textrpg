#include "WorkshopManagement.h"
#include "../Inventory/PlayerInventory.h"
#include "../Item/Potion/PotionInfo.h"
#include "../Utils/Input.h"
#include <algorithm>
#include <iterator>

int WorkshopManagement::showWorkshopMenu(PlayerInventory& inventory) {
    int choice;

    while(true) {
        std::cout << "\n***** 포션 제작소 *****\n";
        std::cout << "1. 전체 레시피 보기\n";
        std::cout << "2. 포션 이름으로 검색\n";
        std::cout << "3. 재료로 검색\n";
        std::cout << "4. 포션 제작\n";
        std::cout << "0. 돌아가기\n";
        std::cout << "선택: ";

        if (!readInput(choice)) continue;
        std::cout << "\n";
        if(choice >= 0 && choice <= 4) {
            if(choice == 0) {
                return 0;
            }
            ControlWorkshopMenu(choice, inventory);
        } else {
            std::cout << "다시 선택해주세요\n";
        }
    }
}

void printRecipe(const PotionRecipe& recipe) {
    std::cout << "** " << recipe.name << " 레시피 **\n";
    std::cout << "필요 재료: ";
    for(auto& ingredient : recipe.ingredients) {
        if(ingredient.group != MaterialGroup::None) {
            std::cout << "[" << materialGroupToString(ingredient.group) << " 중 1종";
        }
        //  else {
        //     std::cout << ingredient.name;
        // }
        std::cout << " x" << ingredient.amount << "]  ";
    }
    std::cout << "\n";
}

void WorkshopManagement::ControlWorkshopMenu(int choice, PlayerInventory& inventory) {
    switch (choice) {
        case 1: showAllRecipes(); break;
        case 2: {
            std::string target;
            std::cout << "검색할 레시피를 입력하세요: ";
            std::cin.ignore();
            std::getline(std::cin, target);
            auto it = searchRecipeByName(target);
            if(it != recipes.end()) {
                printRecipe(*it);
            } else {
                std::cout << "해당 레시피를 찾을 수 없습니다.\n";
            }
            break;
        }
        case 3: {
            std::string target;
            std::cout << "검색할 재료를 입력하세요: ";
            std::cin.ignore();
            std::getline(std::cin, target);
            searchRecipeByIngredient(target);
            break;
        };
        case 4: {
            std::string target;
            std::cout << "제작할 포션 이름을 입력하세요: ";
            std::cin.ignore();
            std::getline(std::cin, target);
            craftPotion(inventory, target);
            break;
        };
        default:
            break;
    }
}



void WorkshopManagement::showAllRecipes() {
    std::cout << "=== 전체 레시피 ===\n";

    for(const auto& recipe : recipes) {
        printRecipe(recipe);
    }
    std::cout << "\n";
}

std::vector<PotionRecipe>::const_iterator 
WorkshopManagement::searchRecipeByName(std::string target) {
    return std::find_if(recipes.begin(), recipes.end(),
        [&](const PotionRecipe& recipe) { return recipe.name == target; });
}

void WorkshopManagement::searchRecipeByIngredient(std::string target) {
    std::vector<PotionRecipe> copy;
    std::copy_if(recipes.begin(), recipes.end(), std::back_inserter(copy),
        [&](const PotionRecipe& recipe) {
            for(auto& ingredient : recipe.ingredients) {
                if(ingredient.group != MaterialGroup::None) {
                    const auto& groupItems = materialGroupItems.at(ingredient.group);
                    if(std::find(groupItems.begin(), groupItems.end(), target) != groupItems.end()) return true;
                } 
                // else if(ingredient.name == target) {
                //     return true;
                // }
            }
            return false;
        }
    );

    if(copy.size() > 0) {
        for(auto& recipe : copy) {
            printRecipe(recipe);
        }
    } else {
        std::cout << "\n해당 재료를 사용하는 레시피를 찾을 수 없습니다.\n\n";
    }
}

void WorkshopManagement::craftPotion(PlayerInventory& inventory, const std::string& potionName) {
    auto it = searchRecipeByName(potionName);
    if(it == recipes.end()) {
        std::cout << "해당 레시피를 찾을 수 없습니다.\n";
        return;
    }

    std::vector<std::pair<std::string, int>> materialsToConsume;
    for(const auto& ingredient : it->ingredients) {
        const auto& groupItems = materialGroupItems.at(ingredient.group);
        auto itemIt = std::find_if(groupItems.begin(), groupItems.end(),
            [&](const std::string& itemName) {
                auto ownedItem = inventory.getItem(itemName);
                return ownedItem && ownedItem->count >= ingredient.amount;
            });

        if(itemIt == groupItems.end()) {
            std::cout << "재료가 부족하여 " << potionName << "을(를) 제작할 수 없습니다.\n";
            return;
        }
        materialsToConsume.emplace_back(*itemIt, ingredient.amount);
    }

    for(const auto& [itemName, amount] : materialsToConsume) {
        inventory.removeItem(itemName, amount);
    }

    inventory.addItem(potionNameMap.at(potionName));
    std::cout << potionName << "을(를) 제작했습니다.\n";
}
