cmake_minimum_required(VERSION 3.20)
project(DungeonCrawler C)

set(CMAKE_C_STANDARD 99)

add_executable(DungeonCrawler game.h ai.h LinkedList.h fileIO.h fileIO.c LinkedList.c ai.c game.c player.h weapon.h weapon.c player.c)
