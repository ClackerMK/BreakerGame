
#pragma once
#include "GameState.h"

#include <memory>
#include <array>

#include <SFML/Graphics.hpp>

#include "EndState.h"
#include "preGameState.h"
#include "SettingsState.h"

#include "Locator.h"

namespace brk {
	/* The Main Menu
	 * where the Player is able to continue to the game, start and quit the game
	 */
	class MainMenuState :
		public brk::GameState
	{	
	public:
		// Constructor
		MainMenuState();

		// Update
		// @param 
		virtual std::unique_ptr<GameState> update(sf::Time dt);

		// Draw
		virtual void draw();
	private:
		Graphics * const				  Graphics; // Graphics Service	
		Input * const					  Input; // Input Service
	};
}