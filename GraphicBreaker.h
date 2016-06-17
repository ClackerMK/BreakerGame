#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Map.h"

namespace brk {
	class GraphicBreaker
	{
	private:
		std::shared_ptr<sf::RenderWindow> window__;

	public:
		GraphicBreaker();
		GraphicBreaker(const GraphicBreaker &r);
		~GraphicBreaker();

		void				setRenderWindow(std::shared_ptr<sf::RenderWindow> wndw);
		void				setCamera(const sf::View& view);

		sf::View			getCamera();


		void				drawMap(std::shared_ptr<CellGrid> grid);

	};

}