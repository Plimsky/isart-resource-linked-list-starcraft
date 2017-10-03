#ifndef TRAINING_ENTITY_H
#define TRAINING_ENTITY_H

#include <types.h>

struct s_entity
{
	int life;
	char *name;
};

t_entity *constructorEntity(void);
void destructorEntity(t_entity *this);

void printEntityLife(t_entity *this);
void printEntityName(t_entity *this);

void setEntityLife(t_entity *this, int life);
void setEntityName(t_entity *this, const char *name);

int getEntityLife(t_entity *this);
char *getEntityName(t_entity *this);

void getEntityDamage(t_entity *this, int attackValue);

#endif //TRAINING_ENTITY_H
