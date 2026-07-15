#include "WorkshopManagement.h"
#include "PotionRecipe.h"
#include <algorithm>

using namespace std;

int WorkshopManagement::showWorkshopMenu() {
    int choice;
    
    while(true) {
        cout << "\n***** 포션 제작소 *****\n";
        cout << "1. 전체 레시피 보기\n";
        cout << "2. 포션 이름으로 검색\n";
        cout << "3. 재료로 검색\n";
        cout << "0. 돌아가기\n";
        cout << "선택: ";
        
        cin >> choice;
        cout << "\n";
        if(choice >= 0 && choice <= 3) {
            if(choice == 0) {
                return 0;
            }
            ControlWorkshopMenu(choice);
        } else {
            cout << "다시 선택해주세요\n";
        }
    }
}

void WorkshopManagement::ControlWorkshopMenu(int choice) {
    switch (choice) {
        case 1: showAllRecipes(); break;
        case 2: {
            string target;
            cout << "검색할 레시피를 입력하세요: ";
            cin.ignore();
            getline(cin, target);
            searchRecipeByName(target); break;
        }
        case 3: {
            string target;
            cout << "검색할 재료를 입력하세요: ";
            cin.ignore();
            getline(cin, target);
            searchRecipeByIngredient(target);
            break;
        };
        default:
            break;
    }
}

void printRecipe(const PotionRecipe &recipe) {
    cout << "** " << recipe.name << " 레시피 **\n";
    cout << "필요 재료: ";
    for(auto& ingredient : recipe.ingredients) {
        cout << ingredient.name << " x" << ingredient.amount << ", ";
    }
    cout << "\n";
}

void WorkshopManagement::showAllRecipes() {
    cout << "=== 전체 레시피 ===\n";

    for(const auto& recipe : recipes) {
        printRecipe(recipe);
    }
    cout << "\n";
}

void WorkshopManagement::searchRecipeByName(string target) {
    auto it = find_if(recipes.begin(), recipes.end(),
        [&](const PotionRecipe& recipe) { return recipe.name == target; });
    
    if (it == recipes.end()) {
        cout << "해당 레시피를 찾을 수 없습니다.\n";
        return;
    } else {
        printRecipe(*it);
    }
}

void WorkshopManagement::searchRecipeByIngredient(string target) {
    vector<PotionRecipe> copy;
    copy_if(recipes.begin(), recipes.end(), back_inserter(copy),
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
        cout << "\n해당 재료를 사용하는 레시피를 찾을 수 없습니다.\n\n";
    }
}
