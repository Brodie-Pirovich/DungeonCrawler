#ifndef DUNGEONCRAWLER_LINKEDLIST_H
#define DUNGEONCRAWLER_LINKEDLIST_H

#include "game.h"

typedef struct ItemNode
{
    item_t* data;
    struct ItemNode* next;
}item_node_t;

typedef struct Inventory
{
    item_node_t* head;
    item_node_t* tail;
    int count;
}inventory_t;


inventory_t* createInventory();
void insertToHeadOfList(inventory_t* inventory, item_t* newItem);
void insertToTailOfList(inventory_t* inventory, item_t* newItem);
void freeInventory(inventory_t* inventory);
void printInventory(const inventory_t* inventory);
item_t* search_inventory(inventory_t* inventory, const char* name);

#endif
