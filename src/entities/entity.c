#include <entities/entity.h>
#include <utils/my_put_number.h>
#include <utils/my_put_string.h>
#include <mem.h>
#include <stdlib.h>
#include <utils/string_length.h>

t_entity *constructorEntity(void)
{
	t_entity *newEntity = (t_entity *) malloc(sizeof(t_entity));

	if (newEntity == NULL)
		return NULL;

	newEntity->life = 0;
	newEntity->name = NULL;

	return newEntity;
}

void destructorEntity(t_entity *this)
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

void printEntityLife(t_entity *this)
{
	if (this == NULL)
		return;

	my_put_number(this->life);
}

void printEntityName(t_entity *this)
{
	if (this == NULL)
		return;

	my_put_string(this->name);
}

void setEntityLife(t_entity *this, int life)
{
	if (this == NULL)
		return;

	this->life = life;
}

void setEntityName(t_entity *this, const char *name)
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

int getEntityLife(t_entity *this)
{
	if (this == NULL)
		return 0;

	return this->life;
}

char *getEntityName(t_entity *this)
{
	if (this == NULL || this->name == NULL)
		return NULL;

	return this->name;
}

void getDamage(t_entity *entity, int attackValue)
{
	entity->life -= attackValue;

	if (entity->life < 0)
		entity->life = 0;
}