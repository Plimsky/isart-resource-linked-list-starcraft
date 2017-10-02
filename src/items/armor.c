#include <stdlib.h>
#include <items/armor.h>
#include <utils/string_length.h>
#include <mem.h>

t_armor *constructorArmor(void)
{
	t_armor *newArmor = (t_armor *) malloc(sizeof(t_armor));

	if (newArmor == NULL)
		return NULL;

	newArmor->name = NULL;
	newArmor->level = 0;

	return newArmor;
}

void destructorArmor(t_armor *this)
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

void setArmorLevel(t_armor *this, int levelArmor)
{
	if (this == NULL)
		return;

	this->level = levelArmor;
}

void setArmorName(t_armor *this, const char *name)
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

int getArmorLevel(t_armor *this)
{
	if (this == NULL)
		return 0;

	return this->level;
}

char *getArmorName(t_armor *this)
{
	if (this == NULL)
		return NULL;

	return this->name;
}