#ifndef DUNGEONCRAWLER_PLAYER_H
#define DUNGEONCRAWLER_PLAYER_H
#include "LinkedList.h"

#define IT_PISTOL  1
#define IT_SHOTGUN 2
#define IT_CHAINGUN  3
#define IT_ROCKETLAUNCHER 4

typedef struct player
{
    int health;
    int armor;
    inventory_t* inventory;
    int currentWeapon;

    int b_hasPistol;
    int b_hasShotgun;
    int b_hasChaingun;
    int b_hasRocketLauncher;

}player_t;

player_t* CreatePlayer();
void FreePlayer(player_t* self);

#endif
