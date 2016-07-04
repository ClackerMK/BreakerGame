#pragma once

#include "GameState.h"

namespace brkr {
	class EndState :
		public GameState
	{
	public:
		GameState* update(sf::Time dt) override
		{
			return nullptr;
		}
		void draw() override
		{
			;
		}
	};

}