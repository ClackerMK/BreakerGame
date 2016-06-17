#include "InitState.h"

using namespace brk;

	InitState::InitState()
	{
		// Default Options
		int width = 800;
		int height = 600;
		bool fullscreen = false;
		int depth = 32;

		// Read Config File
		std::ifstream infile("game.conf");

		if (infile) {
			std::string line;
			while (std::getline(infile, line))
			{
				std::istringstream iss(line);

				std::istringstream is_line(line);
				std::string key;
				if (std::getline(is_line, key, ':'))
				{
					std::string value;
					if (std::getline(is_line, value))
					{
						if (key == "resolution_x")
							width = std::stoi(value);
						else if (key == "resolution_y")
							height = std::stoi(value);
						else if (key == "fullscreen")
							fullscreen = value == "true";
					}
				}
			}

		}
				
		Locator::provideGraphics(new SFMLGraphics(sf::Vector2u(width, height), depth, fullscreen));
		Locator::provideInput(new SFMLInput);
	}
	
	std::unique_ptr<GameState> InitState::update(sf::Time dt)
	{

		return std::make_unique<MainMenuState>();
	}

	void InitState::draw()
	{
	}
