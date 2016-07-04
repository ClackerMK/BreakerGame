#pragma once

#include <SFML/Window\Mouse.hpp>

#include "Graphics.h"

namespace brkr {
	class NullGraphics : public Graphics
	{
		private:

			virtual sf::Vector2i	getMousePosition() const {
				return sf::Mouse::getPosition();
			};

			sf::View m_view;

		public:
			virtual void			draw(const sf::Drawable& trgt, sf::RenderStates states) override {};
			virtual void			clear(sf::Color clr) override {};
			virtual void			display() override {};

			virtual const sf::View& getView() const override { return m_view; }
			virtual void			setView(const sf::View& view) override { m_view = view; };

			virtual void			setSize(const sf::Vector2u size) override  {};
			virtual sf::Vector2u	getSize() const override { return sf::Vector2u(0, 0); };

			virtual bool			isOpen() const override { return false; };

			virtual bool			pollEvents(sf::Event& e) const override { return false; }
	};
}
