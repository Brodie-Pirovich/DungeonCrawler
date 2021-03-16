#ifndef GAME_H
#define GAME_H
#include "ai.h"

typedef struct Item
{
    char name[20];
    char description[256];
    char graphics;
    AiBehaviour aiBehaviour;
}item_t;

typedef struct World
{
    int width;
    int height;
    //2D array of item_t Pointers
    item_t*** map;
}world_t;


typedef enum PlayerAction
{
    //this works because characters are technically integers
    NORTH = 'N', SOUTH = 'S', EAST = 'E', WEST = 'W', QUIT = 'Q', INVENTORY = 'I'
}player_action_t;

typedef enum MovementResult
{
    //this works because characters are technically integers
    CAN_MOVE = 0, BLOCKED = 1, WIN = 2
}movement_result_t;

#endif