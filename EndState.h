#pragma once

#include "GameState.h"

namespace brk {
	class EndState :
		public brk::GameState
	{
	public:
		EndState();
		~EndState();

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