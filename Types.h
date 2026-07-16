#pragma once
#include <string>
#include <map>
#include <variant>
#include <functional>
#include <optional>

enum class StatusType {
    HP, MP, AP, DP
};

enum class JobType {
    Warrior, Mage, Thief, Archor
};

using StatOperator = std::variant<std::plus<int>, std::multiplies<int>, std::minus<int>>;

struct Status {
    int hp, mp, ap, dp;
};

enum class ItemCategory {
    Potion,
    Material
};
struct InventoryItem {
    std::string itemName;
    int count;
    int effect;
    int price;
    ItemCategory itemCategory;
    std::optional<StatusType> status;
};

using Inventory = std::map<std::string, InventoryItem>;

struct StatModifier {
    StatOperator oper;
    int value;
};

static const std::map<StatusType, int Status::*> statusMap = {
    {StatusType::HP, &Status::hp},
    {StatusType::MP, &Status::mp},
    {StatusType::AP, &Status::ap},
    {StatusType::DP, &Status::dp},
};

// inline string potionTypeToString(StatusType& st) {
//     switch(st) {
//         case StatusType::HP: return "HP 포션";
//         case StatusType::MP: return "MP 포션";
//     }
//     return "";
// }

inline std::string jobTypeToString(const JobType& jt) {
    switch(jt) {
        case JobType::Warrior: return "전사";
        case JobType::Mage: return "마법사";
        case JobType::Thief: return "도적";
        case JobType::Archor: return "궁수";
    }
    return "무직";
}

inline std::string statusTypeToString(StatusType st) {
    switch(st) {
        case StatusType::HP: return "HP";
        case StatusType::MP: return "MP";
        case StatusType::AP: return "AP";
        case StatusType::DP: return "DP";
    }
    return "Unknown";
}