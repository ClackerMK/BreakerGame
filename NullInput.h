#pragma once

#include <SFML/Window\Mouse.hpp>

#include "Input.h"

#include "Locator.h"

namespace brkr {
	class NullInput :
		public Input
	{
	public:
		virtual bool			keyWasPressed(sf::Keyboard::Key k) const override { return false; }
		virtual bool			keyWasReleased(sf::Keyboard::Key k) const override { return false; }
		virtual bool			keyIsPressed(sf::Keyboard::Key k) const override { return false; }

		virtual bool			buttonWasPressed(sf::Mouse::Button b) const override { return false; }
		virtual bool			buttonWasReleased(sf::Mouse::Button b) const override { return false; }
		virtual bool			buttonIsPressed(sf::Mouse::Button b) const override { return false; }

		virtual void			clear() override { ; }

		virtual bool			pollEvents(sf::Event& e) override { return false; }
		virtual sf::Vector2i	getMousePositon() const override { return sf::Mouse::getPosition(); }
		virtual int				getMousewheelMovement() const override { return 0; }
	};

}