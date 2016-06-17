#pragma once
#include "GameState.h"

namespace brk
{
	class SettingsState :
		public brk::GameState
	{
	public:
		SettingsState();
		~SettingsState();

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
