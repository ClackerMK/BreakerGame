#include "SFMLGraphics.h"

namespace brk
{
	// Constructor
	SFMLGraphics::SFMLGraphics(sf::Vector2u size, unsigned int depth, bool fullscreen)
	{
		m_renderWndw = std::make_unique<sf::RenderWindow>(sf::VideoMode(size.x, size.y, depth), "Breaker", fullscreen ? sf::Style::Fullscreen : sf::Style::None);
		
	}

	// get Mouse Position relative to renderWindow
	sf::Vector2i SFMLGraphics::getMousePosition() const
	{
		return sf::Mouse::getPosition(*m_renderWndw);
	}

	// get Events
	bool SFMLGraphics::pollEvents(sf::Event & e) const
	{
		return m_renderWndw->pollEvent(e);
	}

	// draw a drawable object onto the screen
	void SFMLGraphics::draw(const sf::Drawable& trgt, sf::RenderStates states)
	{
		m_renderWndw->draw(trgt, states);
	}

	// clear the Screen
	void SFMLGraphics::clear(sf::Color clr)
	{
		m_renderWndw->resetGLStates();
		m_renderWndw->clear(clr);
	}

	// Flip buffers
	void SFMLGraphics::display()
	{
		m_renderWndw->display();
	}

	// get Camera
	const sf::View& SFMLGraphics::getView() const
	{
		return m_renderWndw->getView();
	}

	// set Camera
	void SFMLGraphics::setView(const sf::View& view)
	{
		m_renderWndw->setView(view);
	}

	// set Screen Size
	void SFMLGraphics::setSize(const sf::Vector2u size)
	{
		m_renderWndw->setSize(size);
	}

	// get Screen Size
	sf::Vector2u SFMLGraphics::getSize() const
	{
		return m_renderWndw->getSize();
	}

	// is the Window open?
	bool SFMLGraphics::isOpen() const
	{ 
		return m_renderWndw->isOpen();
	}

}