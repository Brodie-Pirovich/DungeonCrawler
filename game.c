#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ai.h"
#include "fileIO.h"
#include "LinkedList.h"

void printWorld(const world_t* world);
void locateFirstItem(const world_t* world, char graphics, int* x, int* y);
void runGame(world_t* world, int playerX, int playerY, inventory_t* inventory);
void movePlayer(player_action_t action, world_t* world, int* playerX, int* playerY, inventory_t* inventory);
void freeMemory(world_t* world, inventory_t* inventory);

int main()
{
    inventory_t* playerInventory = createInventory();

    system("cls");

    //World loaded from file
    world_t* world = loadWorld();

    //find the player item
    int playerX, playerY;
    locateFirstItem(world, 'P', &playerX, &playerY);

    runGame(world, playerX, playerY, playerInventory);

    freeMemory(world, playerInventory);

    return 0;
}

void runGame(world_t* world, int playerX, int playerY, inventory_t* inventory)
{
    player_action_t playerAction;
    do
    {
        printWorld(world);
        printf("Where do you want to go? (N, S, E, W, Q, I)");
        char inputBuffer[128];
        fgets(inputBuffer, 128, stdin);
        //clear the screen
        system("cls");
        //the player's action is the first letter of their input
        playerAction = toupper((player_action_t)inputBuffer[0]);
        movePlayer(playerAction, world, &playerX, &playerY, inventory);


    } while (playerAction != QUIT);
}

void movePlayer(player_action_t playerAction, world_t* world, int* playerX, int* playerY, inventory_t* inventory)
{
    //the direction that the user selects is the offset for the player's x and y coords
    int xMod = 0, yMod = 0;
    switch(playerAction)
    {
        case NORTH:
            printf("Going North\n");
            yMod = -1;
            break;
        case SOUTH:
            printf("Going South\n");
            yMod = 1;
            break;
        case WEST:
            printf("Going West\n");
            xMod = -1;
            break;
        case EAST:
            printf("Going East\n");
            xMod = 1;
            break;
        case INVENTORY:
            printInventory(inventory);
            return;
            break;
        case QUIT:
            printf("Goodbye!\n");
            return;
            break;
        default:
            return;
    }


    movement_result_t result = CAN_MOVE;
    if(*playerY+yMod < 0 ||
       *playerY+yMod > world->height-1 ||
       *playerX+xMod < 0 ||
       *playerX+xMod > world->width-1)
    {
        //block the player if they try to walk off the edge of the map
        result = BLOCKED;
    }
    else
    {
        //figure out where the player wants to go
        item_t* destinationTile = world->map[*playerY + yMod][*playerX + xMod];
        if(destinationTile != NULL)
        {
            //if there's an item here, activate its AI
            result = destinationTile->aiBehaviour(inventory, destinationTile);
        }
        else
        {
            printf("\n\n");
            result = CAN_MOVE;
        }
    }

    if(result == CAN_MOVE)
    {
        //move the player in the correct direction and update their coordinates
        world->map[*playerY + yMod][*playerX + xMod] = world->map[*playerY][*playerX];
        world->map[*playerY][*playerX] = NULL;
        *playerX += xMod;
        *playerY += yMod;
    }
    else if (result == WIN)
    {
        //if they win the game, we can exit here
        exit(EXIT_SUCCESS);
    }
    else if (result == BLOCKED)
    {
        //print a message if they can't move
        printf("You can't go there!\n\n");
    }
}

void printWorld(const world_t* world)
{
    printf("This is the world map:\n");

    int i, j;
    for(i = 0; i < world->height; i++)
    {
        for(j = 0; j < world->width; j++)
        {
            if(world->map[i][j] == NULL)
            {
                printf("| . |");
            }
            else
            {
                printf("| %c |", world->map[i][j]->graphics );
            }
        }
        printf("\n");
    }
}


void locateFirstItem(const world_t* world, char graphics, int* x, int*y)
{
    int i,j;
    //linear search to find first item that has the requested graphics
    for(i = 0; i < world->height; i++)
    {
        for(j = 0; j < world->width; j++)
        {
            if(world->map[i][j] != NULL && world->map[i][j]->graphics == graphics)
            {
                //return found item location
                *y = i;
                *x = j;
                return;
            }
        }
    }
}

void freeMemory(world_t* world, inventory_t* inventory)
{
    //free all the memory we've used.
    int i,j;
    for(i=0; i < world->height; i++)
    {
        for(j=0; j < world->width; j++)
        {
            //free every item
            free(world->map[i][j]);
        }
        //free every row
        free(world->map[i]);
    }
    //free the map
    free(world->map);
    //free the world
    free(world);
    //free the inventory
    freeInventory(inventory);
}

