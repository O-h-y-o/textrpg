#include "WorkshopManagement.h"
#include "PotionRecipe.h"
#include <algorithm>
#include <iterator>

int WorkshopManagement::showWorkshopMenu() {
    int choice;

    while(true) {
        std::cout << "\n***** 포션 제작소 *****\n";
        std::cout << "1. 전체 레시피 보기\n";
        std::cout << "2. 포션 이름으로 검색\n";
        std::cout << "3. 재료로 검색\n";
        std::cout << "0. 돌아가기\n";
        std::cout << "선택: ";

        std::cin >> choice;
        std::cout << "\n";
        if(choice >= 0 && choice <= 3) {
            if(choice == 0) {
                return 0;
            }
            ControlWorkshopMenu(choice);
        } else {
            std::cout << "다시 선택해주세요\n";
        }
    }
}

void WorkshopManagement::ControlWorkshopMenu(int choice) {
    switch (choice) {
        case 1: showAllRecipes(); break;
        case 2: {
            std::string target;
            std::cout << "검색할 레시피를 입력하세요: ";
            std::cin.ignore();
            std::getline(std::cin, target);
            searchRecipeByName(target); break;
        }
        case 3: {
            std::string target;
            std::cout << "검색할 재료를 입력하세요: ";
            std::cin.ignore();
            std::getline(std::cin, target);
            searchRecipeByIngredient(target);
            break;
        };
        default:
            break;
    }
}

void printRecipe(const PotionRecipe &recipe) {
    std::cout << "** " << recipe.name << " 레시피 **\n";
    std::cout << "필요 재료: ";
    for(auto& ingredient : recipe.ingredients) {
        std::cout << ingredient.name << " x" << ingredient.amount << ", ";
    }
    std::cout << "\n";
}

void WorkshopManagement::showAllRecipes() {
    std::cout << "=== 전체 레시피 ===\n";

    for(const auto& recipe : recipes) {
        printRecipe(recipe);
    }
    std::cout << "\n";
}

void WorkshopManagement::searchRecipeByName(std::string target) {
    auto it = std::find_if(recipes.begin(), recipes.end(),
        [&](const PotionRecipe& recipe) { return recipe.name == target; });

    if (it == recipes.end()) {
        std::cout << "해당 레시피를 찾을 수 없습니다.\n";
        return;
    } else {
        printRecipe(*it);
    }
}

void WorkshopManagement::searchRecipeByIngredient(std::string target) {
    std::vector<PotionRecipe> copy;
    std::copy_if(recipes.begin(), recipes.end(), std::back_inserter(copy),
        [&](const PotionRecipe& recipe) {
            for(auto& ingredient : recipe.ingredients) {
                if(ingredient.name == target) return true;
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
