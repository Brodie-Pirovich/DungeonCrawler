#include "weapon.h"
#include "stdio.h"

void W_FirePistol()
{
    printf("You fire your pistol at the enemy\n");
}

void W_FireShotgun()
{
    printf("You fire your trusty shotgun at the enemy\n");
}

void W_FireChaingun()
{
    printf("You rain chaingun fire on the enemy\n");
}

void W_FireRocketLauncher()
{
    printf("You fire a rocket at the enemy\n");
}

void W_Attack(player_t* self)
{
    if (self->currentWeapon == IT_PISTOL)
    {
        W_FirePistol();
    }
    else if(self->currentWeapon == IT_SHOTGUN)
    {
        W_FireShotgun();
    }
    else if(self->currentWeapon == IT_CHAINGUN)
    {
        W_FireChaingun();
    }
    else if(self->currentWeapon == IT_ROCKETLAUNCHER)
    {
        W_FireRocketLauncher();
    }
    else
    {
        printf("No weapon selected\n");
    }
}

