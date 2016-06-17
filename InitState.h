#pragma once
#include "GameState.h"

#include <memory>

#include <fstream>
#include <sstream>
#include <string>

#include <SFML/Graphics.hpp>

#include "MainMenuState.h"

#include "SFMLGraphics.h"
#include "SFMLInput.h"
#include "Locator.h"

namespace brk {

	class InitState :
		public brk::GameState
	{	
	public:
		InitState();

		std::unique_ptr<GameState> update(sf::Time dt);
		void draw();
	};

}