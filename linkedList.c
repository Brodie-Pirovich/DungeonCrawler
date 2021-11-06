#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

inventory_t* createInventory()
{
    return calloc(1, sizeof(inventory_t));
}


void insertToHeadOfList(inventory_t* inventory, item_t* newItem)
{
    item_node_t* newNode = calloc(1, sizeof(item_node_t));
    newNode->next = inventory->head;
    inventory->head = newNode;
    newNode->data = newItem;
    if(inventory->tail == NULL)
    {
        inventory->tail = newNode;
    }
    inventory->count++;
}


void insertToTailOfList(inventory_t* inventory, item_t* newItem)
{
    item_node_t* newNode = calloc(1, sizeof(item_node_t));
    newNode->data = newItem;
    if(inventory->tail == NULL)
    {
        inventory->head = newNode;
        inventory->tail = newNode;
    }
    else
    {
        newNode->next = NULL;
        inventory->tail->next = newNode;
        inventory->tail = newNode;
    }

    inventory->count++;
}


void freeInventory(inventory_t* inventory)
{
    item_node_t* current = inventory->head;
    while(current != NULL)
    {
        //store the next node so that we don't lose it
        //when the current is freed
        item_node_t* next = current->next;
        //free the item within the node
        free(current->data);
        //free the node
        free(current);
        //move to the next node
        current = next;
    }
    //free the list itself
    free(inventory);
}


void printInventory(const inventory_t* inventory)
{
    printf("\nYou have %d items in your bag\n", inventory->count);
    printf("Your current items:\n");
    item_node_t* current = inventory->head;
    while(current != NULL)
    {
        printf("%c - %s\n\t%s\n", current->data->graphics,
               current->data->name,
               current->data->description);
        current = current->next;
    }
}

item_t* search_inventory(inventory_t* inventory, const char* name)
{
    item_node_t* current = inventory->head;
    while(current != NULL)
    {
        if(strcmp(current->data->name, name) == 0)
            return current->data;
        current=current->next;
    }
    return NULL;
}

