#ifndef DUNGEONCRAWLER_WEAPON_H
#define DUNGEONCRAWLER_WEAPON_H
#include "player.h"


int W_FirePistol();
int W_FireShotgun();
int W_FireChaingun();
int W_FireRocketLauncher();

void W_Attack(player_t* self);

#endif
