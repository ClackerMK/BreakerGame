#include "Game.h"

#include "Resources.h"

int main()
{
	brkr::Game game;

	brkr::Resources res;

	res.getTexture("Menu");

	game.run();
}
