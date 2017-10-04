#include <managers/zerg_manager.h>
#include <stdlib.h>
#include <entities/zerg.h>

t_zergSwarm *constructorZergSwarm(int total)
{
	t_zergSwarm *newSwarm = (t_zergSwarm *) malloc(sizeof(t_zergSwarm));
	t_zerg *firstNewZerg = constructorZerg("Zerg", 100, 15);

	if (newSwarm == NULL || firstNewZerg == NULL)
		return NULL;

	setZergId(firstNewZerg, 1);
	firstNewZerg->previous = NULL;
	firstNewZerg->next = NULL;
	newSwarm->head = NULL;
	newSwarm->tail = NULL;
	newSwarm->total = 0;

	addZerg(newSwarm, firstNewZerg, total);

	return newSwarm;
}

void destructorZergSwarm(t_zergSwarm *this)
{
	t_zerg *tmpZerg = NULL;

	if (this == NULL)
		return;

	tmpZerg = this->head;

	while (tmpZerg != NULL)
	{
		tmpZerg = tmpZerg->next;
		if (tmpZerg != NULL)
		{
			printZergInfos(tmpZerg);
			destructorZerg(tmpZerg->previous);
			tmpZerg->previous = NULL;
		}
	}

	destructorZerg(this->tail);
	this->tail = NULL;
}

void addZerg(t_zergSwarm *swarm, t_zerg *zerg, int total)
{
	if (swarm == NULL || zerg == NULL || total == 0)
		return;

	t_zerg *newZerg = constructorZerg("Zerg", 100, 15);

	newZerg->next = NULL;
	newZerg->previous = NULL;

	if (swarm->head == NULL && swarm->tail == NULL)
	{
		newZerg->id = zerg->id;
		swarm->total++;

		newZerg->next = zerg;
		zerg->previous = newZerg;

		swarm->head = newZerg;
		swarm->tail = zerg;
	}
	else
	{
		newZerg->id = zerg->id + 1;
		swarm->total++;

		zerg->next = newZerg;
		newZerg->previous = zerg;

		swarm->tail = newZerg;
	}

	addZerg(swarm, newZerg, total - 1);
}

void removeZerg(t_zergSwarm *army, t_zerg *zerg)
{
	// TODO
}

void cleanSwarm(t_zergSwarm *army)
{
	// TODO
}

bool isZergExist(t_zergSwarm *army, t_zerg *zerg)
{
	// TODO
}

