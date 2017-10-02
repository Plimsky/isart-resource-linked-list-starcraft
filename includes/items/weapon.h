#ifndef TRAINING_WEAPON_H
#define TRAINING_WEAPON_H

#include <types.h>

struct s_weapon
{
	int damage;
	char *name;
	int ammo;
};

t_weapon *constructorWeapon(void);
void destructorWeapon(t_weapon *this);

void setWeaponDamage(t_weapon *this, int damage);
void setWeaponName(t_weapon *this, const char *name);
void setWeaponAmmo(t_weapon *this, int ammo);

int getWeaponDamage(t_weapon *this);
char *getWeaponName(t_weapon *this);
int getWeaponAmmo(t_weapon *this);

#endif //TRAINING_WEAPON_H
