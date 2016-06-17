#pragma once

#include <map>

#include "Locator.h"

#include "Input.h"

namespace brk {
	class SFMLInput :
		public Input
	{
	public:
		virtual bool			keyWasPressed(sf::Keyboard::Key k) const;
		virtual bool			keyWasReleased(sf::Keyboard::Key k) const;
		virtual bool			keyIsPressed(sf::Keyboard::Key k) const;

		virtual bool			buttonWasPressed(sf::Mouse::Button b) const;
		virtual bool			buttonWasReleased(sf::Mouse::Button b) const;
		virtual bool			buttonIsPressed(sf::Mouse::Button b) const;

		virtual void			clear();

		virtual bool			pollEvents(sf::Event& e);
		virtual sf::Vector2i	getMousePositon() const;
		virtual int				getMousewheelMovement() const;
	private:
		enum class status
		{
			pressed, released
		};

		std::map<sf::Keyboard::Key, status> m_keyStatus;
		std::map<sf::Mouse::Button, status> m_buttonStatus;

		int									m_mouseWheelMovement;

	};

}