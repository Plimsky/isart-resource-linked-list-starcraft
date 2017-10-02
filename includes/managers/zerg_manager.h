#ifndef TRAINING_ZERG_MANAGER_H
#define TRAINING_ZERG_MANAGER_H

#include <types.h>
#include <stdbool.h>

struct s_zergSwarm
{
	int total;
	t_zerg *head;
	t_zerg *tail;
};

// Constructor / Destructor

t_spaceMarineArmy *constructorZergArmy(int total);
void destructorZergArmy(t_spaceMarineArmy *this);

// Actions

void addZerg(t_zergSwarm *army, t_spaceMarine *spaceMarine, int total);
void removeZerg(t_zergSwarm *army, t_spaceMarine *spaceMarine);
void cleanSwarm(t_zergSwarm *army);
bool isZergExist(t_zergSwarm *army, t_spaceMarine *spaceMarine);

#endif //TRAINING_ZERG_MANAGER_H
