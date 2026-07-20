cmake_minimum_required(VERSION 3.15)
project(TextRPG LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect sources
set(SOURCES
    textrpg.cpp
    GameManagement/GameManagement.cpp
    Player/Player.cpp
    Player/PlayerStatus.cpp
    Player/PlayerEnhancement.cpp
    Inventory/PlayerInventory.cpp
    Player/Job/Warrior.cpp
    Player/Job/Mage.cpp
    Player/Job/Thief.cpp
    Player/Job/Archor.cpp
    Item/Item.cpp
    Item/Potion/Potion.cpp
    Item/Material/Material.cpp
    Monster/Monster.cpp
    Monster/Goblin.cpp
    Monster/Slime.cpp
    Monster/Wolf.cpp
    AlchemyWorkshop/WorkshopManagement.cpp
)

add_executable(outDebug ${SOURCES})

target_include_directories(outDebug PRIVATE ${CMAKE_SOURCE_DIR})

if(MSVC)
    target_compile_options(outDebug PRIVATE /W4 /permissive-)
endif()
