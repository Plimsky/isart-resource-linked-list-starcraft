#include <items/weapon.h>
#include <stdlib.h>
#include <utils/string_length.h>
#include <mem.h>

t_weapon *constructorWeapon(void)
{
	t_weapon *newWeapon = (t_weapon *) malloc(sizeof(t_weapon));

	if (newWeapon == NULL)
		return NULL;

	newWeapon->damage = 0;
	newWeapon->name = NULL;
	newWeapon->ammo = 0;

	return newWeapon;
}

void destructorWeapon(t_weapon *this)
{
	if (this == NULL)
		return;

	if (this->name != NULL)
	{
		free(this->name);
		this->name = NULL;
	}

	free(this);
}

void setWeaponDamage(t_weapon *this, int damage)
{
	if (this == NULL)
		return;

	this->damage = damage;
}

void setWeaponName(t_weapon *this, const char *name)
{
	size_t nameLength;

	if (this == NULL || name == NULL)
		return;

	nameLength = (size_t) string_length(name);

	if (this->name == NULL)
		this->name = (char *) malloc(sizeof(char) * nameLength);
	else
	{
		free(this->name);
		this->name = NULL;
		this->name = (char *) malloc(sizeof(char) * nameLength);
	}

	if (this->name != NULL)
		strncpy(this->name, name, nameLength);
}

void setWeaponAmmo(t_weapon *this, int ammo)
{
	if (this == NULL)
		return;

	this->ammo = ammo;
}

int getWeaponDamage(t_weapon *this)
{
	if (this == NULL)
		return 0;

	return this->damage;
}

char *getWeaponName(t_weapon *this)
{
	if (this == NULL || this->name == NULL)
		return NULL;

	return this->name;
}

int getWeaponAmmo(t_weapon *this)
{
	if (this == NULL)
		return 0;

	return this->ammo;
}