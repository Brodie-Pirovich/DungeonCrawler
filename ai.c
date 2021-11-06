#include "ai.h"
#include "game.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//This is the AI for when you hit an EXIT
movement_result_t exitLogic(inventory_t* inventory, item_t* item)
{
    if(search_inventory(inventory, "Key") != NULL)
    {
        printf("You Win!!\n");
        return WIN;
    }
    else
    {
        printf("You need to find the key first! ");
        return BLOCKED;
    }
}

//This is the AI for when you hit something you can pick up
movement_result_t grabLogic(inventory_t* inventory, item_t* item)
{
    printf("You found %s!\n\t%s\n", item->name, item->description);
    insertToTailOfList(inventory, item);
    return CAN_MOVE;
}

movement_result_t encounterLogic(inventory_t* inventory, item_t* item)
{
    //TODO: Implement combat loop
    printf("You come across a monster.\n It charges towards you but you take it down with one shot of your weapon.");
    printf("The monster dropped a %s!\n\t%s\n", item->name, item->description);
    insertToTailOfList(inventory, item);
    return CAN_MOVE;
}


//this will retrieve an AI function based on a string.
AiBehaviour textToBehaviour(const char* aiText)
{
    AiBehaviour behaviour = NULL;
    if (strcmp(aiText, "EXIT_LOGIC") == 0)
    {
        behaviour = exitLogic;
    }
    else if(strcmp(aiText, "GRAB_LOGIC") == 0)
    {
        behaviour = grabLogic;
    }
    else if(strcmp(aiText, "ENCOUNTER_LOGIC") == 0)
    {
        behaviour = encounterLogic;
    }
    return behaviour;
}
