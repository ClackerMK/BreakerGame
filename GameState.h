#pragma once

#include <memory>

#include <SFML/System/Clock.hpp>

namespace brkr {
	class GameState
	{
	public:
		virtual ~GameState()
		{
		}

		virtual GameState * update(sf::Time dt) = 0;
		virtual void draw() = 0;
	};
}