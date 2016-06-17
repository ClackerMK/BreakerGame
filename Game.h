#pragma once

#include <memory>
#include <SFML/System.hpp>

#include "GameState.h"
#include "InitState.h"

namespace brk
{
	class Game
	{
	private:
		std::unique_ptr<GameState> m_currentState;

		void update(sf::Time dt);

		const sf::Time TIMESTEP;

		static bool m_running;
	public:
		Game();

		void run();

		static void stop() { m_running = false; }
	};
};