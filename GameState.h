#pragma once

#include <memory>

#include <SFML/System/Clock.hpp>

namespace brk {
	class GameState
	{
	public:
		virtual ~GameState()
		{
		}

		virtual std::unique_ptr<GameState> update(sf::Time dt) = 0;
		virtual void draw() = 0;
	};
}