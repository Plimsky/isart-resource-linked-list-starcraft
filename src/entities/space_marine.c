#include <entities/space_marine.h>
#include <stdlib.h>
#include <entities/entity.h>
#include <items/inventory.h>
#include <utils/my_put_string.h>
#include <utils/my_put_number.h>

t_spaceMarine *constructorSpaceMarine(const char *name, int life)
{
	t_spaceMarine *newSpaceMarine = (t_spaceMarine *) malloc(sizeof(t_spaceMarine));
	t_entity *newEntity = constructorEntity();

	if (newSpaceMarine == NULL || newEntity == NULL)
		return NULL;

	setEntityLife(newEntity, life);
	setEntityName(newEntity, name);

	setSpaceMarineId(newSpaceMarine, 0);
	setSpaceMarineEntity(newSpaceMarine, newEntity);
	setSpaceMarineInventory(newSpaceMarine, NULL);

	return newSpaceMarine;
}

void destructorSpaceMarine(t_spaceMarine *this)
{
	if (this == NULL)
		return;

	if (this->entity != NULL)
	{
		destructorEntity(this->entity);
		this->entity = NULL;
	}

	if (this->inventory != NULL)
	{
		destructorInventory(this->inventory);
		this->inventory = NULL;
	}

	free(this);
}

void setSpaceMarineId(t_spaceMarine *this, int id)
{
	if (this == NULL)
		return;

	this->id = id;
}

void setSpaceMarineEntity(t_spaceMarine *this, t_entity *entity)
{
	if (this == NULL || entity == NULL)
		return;

	this->entity = entity;
}

void setSpaceMarineInventory(t_spaceMarine *this, t_inventory *inventory)
{
	if (this == NULL || inventory == NULL)
		return;

	this->inventory = inventory;
}

int getSpaceMarineId(t_spaceMarine *this)
{
	if (this == NULL)
		return -1;

	return this->id;
}

t_entity *getSpaceMarineEntity(t_spaceMarine *this)
{
	if (this == NULL)
		return NULL;

	return this->entity;
}

t_inventory *getSpaceMarineInventory(t_spaceMarine *this)
{
	if (this == NULL)
		return NULL;

	return this->inventory;
}

void spaceMarineAttackZerg(t_spaceMarine *this, t_zerg *zerg)
{
	if (this == NULL || zerg == NULL || this->inventory == NULL)
		return;

	// TODO do getDamage spaceMarine
}

void printSpaceMarineInfos(t_spaceMarine *this)
{
	if (this == NULL || this->entity == NULL)
		return;

	my_put_string("--- Name : ");

	if (this->entity->name == NULL)
		my_put_string("Unknown");
	else
		my_put_string(this->entity->name);

	my_put_string("\n--- Life : ");
	my_put_number(this->entity->life);
}