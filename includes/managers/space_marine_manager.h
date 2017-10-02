#ifndef TRAINING_SPACE_MARINE_MANAGER_H
#define TRAINING_SPACE_MARINE_MANAGER_H

#include <types.h>
#include <stdbool.h>

struct s_spaceMarineArmy
{
	int total;
	t_spaceMarine *head;
	t_spaceMarine *tail;
};

// Constructor / Destructor

t_spaceMarineArmy *constructorSpaceMarineArmy(int total);
void destructorSpaceMarineArmy(t_spaceMarineArmy *this);

// Actions

void addSpaceMarine(t_spaceMarineArmy *army, t_spaceMarine *spaceMarine);
void removeSpaceMarine(t_spaceMarineArmy *army, t_spaceMarine *spaceMarine);
void cleanTroups(t_spaceMarineArmy *army);
bool isSpaceMarineExist(t_spaceMarineArmy *army, t_spaceMarine *spaceMarine);

#endif //TRAINING_SPACE_MARINE_MANAGER_H
