#include "GraphicBreaker.h"

using namespace brk;

	GraphicBreaker::GraphicBreaker()
	{
	}

	GraphicBreaker::GraphicBreaker(const GraphicBreaker & r) : window__(r.window__)
	{
	}


	GraphicBreaker::~GraphicBreaker()
	{
	}

	void GraphicBreaker::setRenderWindow(std::shared_ptr<sf::RenderWindow> wndw)
	{
		window__ = wndw;
	}

	void GraphicBreaker::setCamera(const sf::View& view) const
	{
		window__->setView(view);
	}

	sf::View GraphicBreaker::getCamera() const
	{
		return window__->getView();
	}

	void GraphicBreaker::drawMap(std::shared_ptr<CellGrid> grid)
	{

	}
