#pragma once
#include "GameState.h"

namespace brkr
{
	class SettingsState :
		public brkr::GameState
	{
	public:
		SettingsState();
		~SettingsState();

		GameState* update(sf::Time dt) override
		{
			return this;
		}

		void draw() override
		{
			;
		}
	};
}
