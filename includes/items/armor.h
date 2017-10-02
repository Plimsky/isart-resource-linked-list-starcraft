#ifndef TRAINING_ARMOR_H
#define TRAINING_ARMOR_H

#include <types.h>

struct s_armor
{
	int level;
	char *name;
};

t_armor *constructorArmor(void);
void destructorArmor(t_armor *this);

void setArmorLevel(t_armor *this, int levelArmor);
void setArmorName(t_armor *this, const char *name);

int getArmorLevel(t_armor *this);
char *getArmorName(t_armor *this);

#endif //TRAINING_ARMOR_H
