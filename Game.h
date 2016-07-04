#pragma once

#include <memory>
#include <SFML/System.hpp>

#include "GameState.h"
#include "InitState.h"

namespace brkr
{
	class Game
	{
	private:
		std::unique_ptr<GameState> m_currentState;

		void update(sf::Time dt);

		const sf::Time TIMESTEP;

		bool m_running;
	public:
		Game();

		void run();

		void stop() { m_running = false; }
	};
};