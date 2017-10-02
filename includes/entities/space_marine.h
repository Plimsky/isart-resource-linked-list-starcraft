#ifndef TRAINING_SPACE_MARINE_H
#define TRAINING_SPACE_MARINE_H

#include <types.h>

struct s_spaceMarine
{
	int id;
	t_entity *entity;
	t_inventory *inventory;
	t_spaceMarine *previous;
	t_spaceMarine *next;
};

// Constructor / Destructor

t_spaceMarine *constructorSpaceMarine(const char *name, int life);
void destructorSpaceMarine(t_spaceMarine *this);

// Setters

void setSpaceMarineId(t_spaceMarine *this, int id);
void setSpaceMarineEntity(t_spaceMarine *this, t_entity *entity);
void setSpaceMarineInventory(t_spaceMarine *this, t_inventory *inventory);

// Getters

int getSpaceMarineId(t_spaceMarine *this);
t_entity *getSpaceMarineEntity(t_spaceMarine *this);
t_inventory *getSpaceMarineInventory(t_spaceMarine *this);

// Actions

void spaceMarineAttackZerg(t_spaceMarine *this, t_zerg *zerg);
void printSpaceMarineInfos(t_spaceMarine *this);

#endif //TRAINING_SPACE_MARINE_H
