#include "Game.h"

#include "Resources.h"

int main()
{
	brk::Game game;

	brk::Resources res;

	res.getTexture("Menu");

	game.run();
}
