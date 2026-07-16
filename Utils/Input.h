#pragma once
#include <iostream>
#include <limits>
#include <string>

template<typename T>
bool readInput(T& value, const std::string& errorMsg = "잘못 입력하셨습니다.") {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << errorMsg << "\n";
        return false;
    }
    return true;
}

template<typename T>
void readRangedPair(const std::string& prompt, T& first, T& second, T min, T max, const std::string& errorMsg) {
    while (true) {
        std::cout << prompt;
        std::cin >> first >> second;
        if (first >= min && first <= max && second >= min && second <= max) {
            break;
        }
        std::cout << errorMsg;
    }
}
