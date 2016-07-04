#pragma once
#include "GameState.h"

namespace brkr
{
	class preGameState :
		public brkr::GameState
	{
	public:
		preGameState();
		~preGameState();

		GameState * update(sf::Time dt) override
		{


			return nullptr;
		}
		void draw() override
		{
			;
		}
	};

}