#pragma once
#include "GameState.h"

namespace brk
{
	class preGameState :
		public brk::GameState
	{
	public:
		preGameState();
		~preGameState();

		std::unique_ptr<GameState> update(sf::Time dt) override
		{


			return nullptr;
		}
		void draw() override
		{
			;
		}
	};

}