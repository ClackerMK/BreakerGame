#pragma once

#include <SFML/Graphics.hpp>

#include "Input.h"

namespace brk {
	class Graphics
	{
	public:
		friend class Input;
		friend class SFMLInput;

		virtual ~Graphics() {};

		virtual void draw(const sf::Drawable& trgt, sf::RenderStates states) = 0;
		virtual void clear(sf::Color clr) = 0;
		virtual void display() = 0;

		virtual void			setView(const sf::View& view) = 0;
		virtual const sf::View& getView() const = 0;

		virtual void			setSize(const sf::Vector2u size) = 0;
		virtual sf::Vector2u	getSize() const = 0;

		virtual bool			isOpen() const = 0;

	private:
		virtual sf::Vector2i	getMousePosition() const = 0;
		virtual bool			pollEvents(sf::Event& e) const = 0;
	};
}