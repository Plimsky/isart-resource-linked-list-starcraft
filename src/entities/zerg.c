#include <entities/zerg.h>
#include <stdlib.h>
#include <entities/entity.h>
#include <items/armor.h>
#include <utils/my_put_string.h>
#include <utils/my_put_number.h>

t_zerg *constructorZerg(const char *name, int life, int attack)
{
	t_zerg *newZerg = (t_zerg *) malloc(sizeof(t_zerg));
	t_entity *newEntity = constructorEntity();

	if (newZerg == NULL || newEntity == NULL)
		return NULL;

	setEntityLife(newEntity, life);
	setEntityName(newEntity, name);

	setZergEntity(newZerg, newEntity);
	setZergId(newZerg, 0);
	setZergAttack(newZerg, attack);
	setZergArmor(newZerg, NULL);

	return newZerg;
}

void destructorZerg(t_zerg *this)
{
	if (this == NULL)
		return;

	if (this->entity != NULL)
	{
		destructorEntity(this->entity);
		this->entity = NULL;
	}

	if (this->armor != NULL)
	{
		destructorArmor(this->armor);
		this->armor = NULL;
	}

	free(this);
}

void setZergId(t_zerg *this, int id)
{
	if (this == NULL)
		return;

	this->id = id;
}

void setZergAttack(t_zerg *this, int attack)
{
	if (this == NULL)
		return;

	this->attack = attack;
}

void setZergEntity(t_zerg *this, t_entity *entity)
{
	if (this == NULL || entity == NULL)
		return;

	this->entity = entity;
}

void setZergArmor(t_zerg *this, t_armor *armor)
{
	if (this == NULL || armor == NULL)
		return;

	this->armor = armor;
}

int getZergId(t_zerg *this)
{
	if (this == NULL)
		return 0;

	return this->id;
}

int getZergAttack(t_zerg *this)
{
	if (this == NULL)
		return 0;

	return this->attack;
}

t_entity *getZergEntity(t_zerg *this)
{
	if (this == NULL)
		return NULL;

	return this->entity;
}

t_armor *getZergArmor(t_zerg *this)
{
	if (this == NULL)
		return NULL;

	return this->armor;
}

void zergAttackSpaceMarine(t_zerg *this, t_spaceMarine *spaceMarine)
{
	if (this == NULL || spaceMarine == NULL)
		return;

	// TODO do getDamage zerg
}

void printZergInfos(t_zerg *this)
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