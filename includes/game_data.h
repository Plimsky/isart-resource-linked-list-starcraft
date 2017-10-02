#ifndef TRAINING_GAME_DATA_H
#define TRAINING_GAME_DATA_H

#include "types.h"

#define SPACE_MARINE_ARMY_NUMBER 100
#define ZERG_SWARM_NUMBER 300

enum gameState
{
	PAUSE,
	RUN,
	GAME_OVER,
	EXIT
};

struct s_game
{
	static int countGame;
	enum gameState state;
	t_spaceMarineArmy *spaceMarineArmy;
	t_zergSwarm *zergArmy;
};

t_game *GAME;

#endif //TRAINING_GAME_DATA_H
