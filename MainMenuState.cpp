#include "MainMenuState.h"

#include <iostream>

using namespace brk;

	MainMenuState::MainMenuState() : Graphics(Locator::getGraphics()), Input(Locator::getInput())
	{
		
	}

	std::unique_ptr<GameState> MainMenuState::update(sf::Time dt)
	{
		sf::Event event;
		
		// Event processing.
		while (Input->pollEvents(event)) {
			
			// If window is about to be closed, leave program.
			if (event.type == sf::Event::Closed) {
				return std::make_unique<EndState>();
			}
		}
		
		return nullptr;
	}

	void MainMenuState::draw()
	{		
		Graphics->clear(sf::Color::Black);
		
		Graphics->display();
	}
