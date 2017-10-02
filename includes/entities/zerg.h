#ifndef TRAINING_ZERG_H
#define TRAINING_ZERG_H

#include <types.h>

struct s_zerg
{
	int id;
	int attack;
	t_entity *entity;
	t_armor *armor;
	t_zerg *previous;
	t_zerg *next;
};

// Constructor / Destructor

t_zerg *constructorZerg(const char* name, int life, int attack);
void destructorZerg(t_zerg *this);

// Setters

void setZergId(t_zerg *this, int id);
void setZergAttack(t_zerg *this, int attack);
void setZergEntity(t_zerg *this, t_entity *entity);
void setZergArmor(t_zerg *this, t_armor *armor);

// Getters

int getZergId(t_zerg *this);
int getZergAttack(t_zerg *this);
t_entity *getZergEntity(t_zerg *this);
t_armor *getZergArmor(t_zerg *this);

// Actions

void zergAttackSpaceMarine(t_zerg *this, t_spaceMarine *spaceMarine);
void printZergInfos(t_zerg *this);

#endif //TRAINING_ZERG_H
