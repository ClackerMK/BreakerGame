#pragma once

#include <SFML/System.hpp>

#include "Graphics.h"

namespace brkr {
	class Input
	{
	public:

		virtual ~Input() {};
		
		virtual bool			keyWasPressed(sf::Keyboard::Key k) const = 0;
		virtual bool			keyWasReleased(sf::Keyboard::Key k) const = 0;
		virtual bool			keyIsPressed(sf::Keyboard::Key k) const = 0;

		virtual bool			buttonWasPressed(sf::Mouse::Button b) const = 0;
		virtual bool			buttonWasReleased(sf::Mouse::Button b) const = 0;
		virtual bool			buttonIsPressed(sf::Mouse::Button b) const = 0;

		virtual void			clear() = 0;

		virtual bool			pollEvents(sf::Event& e) = 0;

		virtual sf::Vector2i	getMousePositon() const = 0;
		virtual int				getMousewheelMovement() const = 0;
	};
}