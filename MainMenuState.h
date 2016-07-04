
#pragma once
#include "GameState.h"

#include <memory>
#include <array>

#include <SFML/Graphics.hpp>

#include "EndState.h"
#include "preGameState.h"
#include "SettingsState.h"

#include "Locator.h"

namespace brkr {
	/* The Main Menu
	 * where the Player is able to continue to the game, start and quit the game
	 */
	class MainMenuState :
		public brkr::GameState
	{	
	public:
		// Constructor
		MainMenuState();

		// Update
		// @param 
		virtual GameState * update(sf::Time dt);

		// Draw
		virtual void draw();
	private:
		Graphics * const				  Graphics; // Graphics Service	
		Input * const					  Input; // Input Service
	};
}