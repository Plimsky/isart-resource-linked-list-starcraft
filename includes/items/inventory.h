#ifndef TRAINING_INVENTORY_H
#define TRAINING_INVENTORY_H

#include <types.h>

struct s_inventory
{
	t_weapon *mainWeapon;
	t_weapon *secondWeapon;
	t_armor *armor;
};

t_inventory *constructorInventory(void);
void destructorInventory(t_inventory *this);

void setMainWeapon(t_inventory *this, t_weapon *weapon);
void setSecondWeapon(t_inventory *this, t_weapon *weapon);
void setArmor(t_inventory *this, t_armor *armor);

t_weapon *getMainWeapon(t_inventory *this);
t_weapon *getSecondWeapon(t_inventory *this);
t_armor *getArmor(t_inventory *this);

#endif //TRAINING_INVENTORY_H
