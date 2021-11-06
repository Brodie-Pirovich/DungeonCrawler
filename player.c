#include "player.h"
#include "stdlib.h"

player_t* CreatePlayer()
{
    player_t* player = calloc(1, sizeof(player_t));
    inventory_t* playerInventory = createInventory();
    player->inventory = playerInventory;

    player->health = 100;
    player->armor = 0;
    player->currentWeapon = 1;
    player->b_hasPistol = 1;
    player->b_hasShotgun = 0;
    player->b_hasChaingun = 0;
    player->b_hasRocketLauncher = 0;

    return player;
}

void FreePlayer(player_t* self)
{
    freeInventory(self->inventory);
    free(self);
}
