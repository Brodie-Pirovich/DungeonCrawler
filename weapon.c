#include "weapon.h"
#include "stdio.h"

int W_FirePistol()
{
    printf("You fire your pistol at the enemy\n");
    return 30;
}

int W_FireShotgun()
{
    printf("You fire your trusty shotgun at the enemy\n");
    return 50;
}

int W_FireChaingun()
{
    printf("You rain chaingun fire on the enemy\n");
    return 50;
}

int W_FireRocketLauncher()
{
    printf("You fire a rocket at the enemy\n");
    return 100;
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

