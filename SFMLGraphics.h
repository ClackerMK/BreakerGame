#pragma once

#include "Graphics.h"

#include <memory>

namespace brk {
	class SFMLGraphics : public Graphics
	{
	private:

		sf::Vector2i						getMousePosition() const override;

		bool								pollEvents(sf::Event& e) const override;

		std::unique_ptr<sf::RenderWindow>	m_renderWndw;
	public:
						SFMLGraphics(sf::Vector2u size, unsigned int depth, bool fullscreen);
		
		void			draw(const sf::Drawable& trgt, 
							sf::RenderStates states = sf::RenderStates::Default) override;
		void			clear(sf::Color clr = sf::Color::Black) override;
		void			display() override;

		const sf::View& getView() const override;
		void			setView(const sf::View& view) override;

		sf::Vector2u	getSize() const override;
		void			setSize(const sf::Vector2u size) override;
		
		bool			isOpen() const override;
			
	};
}