#include <stdlib.h>
#include <managers/space_marine_manager.h>
#include <entities/space_marine.h>
#include <stdio.h>

t_spaceMarineArmy *constructorSpaceMarineArmy(int total)
{
	t_spaceMarineArmy *newArmy = (t_spaceMarineArmy *) malloc(sizeof(t_spaceMarineArmy));
	t_spaceMarine *newSpaceMarine = NULL;

	if (newArmy == NULL)
		return NULL;

	newArmy->total = 0;
	newArmy->maxId = 0;
	newArmy->head = NULL;
	newArmy->tail = NULL;

	while (total > 0)
	{
		newSpaceMarine = constructorSpaceMarine("Jean Michel", 100);

		if (newSpaceMarine == NULL)
			continue;

		addSpaceMarine(newArmy, newSpaceMarine);

		if (!isSpaceMarineExist(newArmy, newSpaceMarine, true))
			continue;

		--total;
	}

	newArmy->maxId = getSpaceMarineId(newSpaceMarine);

	return newArmy;
}

void destructorSpaceMarineArmy(t_spaceMarineArmy *this)
{
	t_spaceMarine *tmp = NULL;

	if (this == NULL)
		return;

	tmp = this->head;
	while (tmp != NULL)
	{
		destructorSpaceMarine(tmp);
		tmp = tmp->next;
	}

	this->head = NULL;
	this->tail = NULL;

	free(this);
}

void addSpaceMarine(t_spaceMarineArmy *army, t_spaceMarine *spaceMarine)
{
	if (army == NULL || spaceMarine == NULL)
		return;

	if (army->head == NULL && army->tail == NULL)
	{
		army->head = army->tail = spaceMarine;
		army->total++;
	}
	else
	{
		spaceMarine->previous = army->tail;
		army->tail->next = spaceMarine;
		army->tail = spaceMarine;
		army->total++;
	}
}

void removeSpaceMarine(t_spaceMarineArmy *army, t_spaceMarine *spaceMarine)
{
	t_spaceMarine *node = NULL;

	if (army == NULL ||
		spaceMarine == NULL ||
		army->head == NULL ||
		army->tail == NULL)
		return;

	if (spaceMarine->previous == NULL && spaceMarine->next == NULL)
	{
		army->head = NULL;
		army->tail = NULL;
	}
	else if (army->head == spaceMarine)
	{
		army->head = army->head->next;
		army->head->previous = NULL;
	}
	else if (army->tail == spaceMarine)
	{
		army->tail = army->tail->previous;
		army->tail->next = NULL;
	}
	else
	{
		node = spaceMarine->previous;
		node->next = spaceMarine->next;

		node = spaceMarine->next;
		node->previous = spaceMarine->previous;
	}

	destructorSpaceMarine(spaceMarine);
	--army->total;
}

bool isSpaceMarineExist(t_spaceMarineArmy *army, t_spaceMarine *spaceMarine, bool byPointer)
{
	bool result = false;
	t_spaceMarine *tmp = NULL;

	if (army == NULL ||
		spaceMarine == NULL ||
		army->head == NULL ||
		army->tail == NULL)
		return result;

	tmp = army->head;

	while (tmp != NULL)
	{
		if (byPointer && tmp == spaceMarine)
			result = true;
		else if (!byPointer && getSpaceMarineId(tmp) == getSpaceMarineId(spaceMarine))
			result = true;

		tmp = tmp->next;
	}

	return result;
}