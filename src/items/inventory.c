#include <stdlib.h>
#include <items/weapon.h>
#include <items/armor.h>
#include <items/inventory.h>

t_inventory *constructorInventory(void)
{
	t_inventory *newInventory = (t_inventory *) malloc(sizeof(t_inventory));

	if (newInventory == NULL)
		return NULL;

	newInventory->mainWeapon = NULL;
	newInventory->secondWeapon = NULL;
	newInventory->armor = NULL;

	return newInventory;
}

void destructorInventory(t_inventory *this)
{
	if (this == NULL)
		return;

	if (this->mainWeapon){

		destructorWeapon(this->mainWeapon);
		this->mainWeapon = NULL;
	}

	if (this->secondWeapon){

		destructorWeapon(this->secondWeapon);
		this->secondWeapon = NULL;
	}

	if (this->armor){

		destructorArmor(this->armor);
		this->armor = NULL;
	}

	free(this);
}

void setMainWeapon(t_inventory *this, t_weapon *weapon)
{
	if (this == NULL || weapon == NULL)
		return;

	this->mainWeapon = weapon;
}

void setSecondWeapon(t_inventory *this, t_weapon *weapon)
{
	if (this == NULL || weapon == NULL)
		return;

	this->secondWeapon = weapon;
}

void setArmor(t_inventory *this, t_armor *armor)
{
	if (this == NULL || armor == NULL)
		return;

	this->armor = armor;
}

t_weapon *getMainWeapon(t_inventory *this)
{
	if (this == NULL)
		return NULL;

	return this->mainWeapon;
}

t_weapon *getSecondWeapon(t_inventory *this)
{
	if (this == NULL)
		return NULL;

	return this->secondWeapon;
}

t_armor *getArmor(t_inventory *this)
{
	if (this == NULL)
		return NULL;

	return this->armor;
}

