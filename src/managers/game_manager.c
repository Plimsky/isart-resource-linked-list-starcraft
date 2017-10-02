#include <stdlib.h>
#include <managers/game_manager.h>
#include <game_data.h>

int awakeGame(void)
{
	GAME = (t_game *) malloc(sizeof(t_game));

	if (GAME == NULL)
		return EXIT_FAILURE;

	// TODO init armies

	return EXIT_SUCCESS;
}

void loopGame(void)
{
	// TODO start loop
}

void endGame(void)
{
	// TODO destroy everythingx
}