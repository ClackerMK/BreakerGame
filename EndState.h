#pragma once

#include "GameState.h"

#include "Game.h"

namespace brk {
	class EndState :
		public brk::GameState
	{
	public:
		EndState();
		~EndState();

		std::unique_ptr<GameState> update(sf::Time dt) override
		{
			Game::stop();

			return nullptr;
		}
		void draw() override
		{
			;
		}
	};

}