#include "MainMenuState.h"

#include <iostream>

using namespace brkr;

MainMenuState::MainMenuState() : Graphics(Locator::getGraphics()), Input(Locator::getInput())
{
		
}

GameState * MainMenuState::update(sf::Time dt)
{
	sf::Event event;
		
	// Event processing.
	while (Input->pollEvents(event)) {
			
		// If window is about to be closed, leave program.
		if (event.type == sf::Event::Closed) {
			return nullptr;
		}
	}
		
	return this;
}

void MainMenuState::draw()
{		
	Graphics->clear(sf::Color::Black);
		
	Graphics->display();
}
