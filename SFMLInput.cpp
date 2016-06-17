#include "SFMLInput.h"


namespace brk {
	bool SFMLInput::keyWasPressed(sf::Keyboard::Key k) const
	{
		auto it = m_keyStatus.find(k);
		if ( it != m_keyStatus.end())
		{
			return it->second == status::pressed;
		}
		return false;
	}

	bool SFMLInput::keyWasReleased(sf::Keyboard::Key k) const
	{
		auto it = m_keyStatus.find(k);
		if (it != m_keyStatus.end())
		{
			return it->second == status::released;
		}
		return false;
	}

	bool SFMLInput::keyIsPressed(sf::Keyboard::Key k) const
	{
		return sf::Keyboard::isKeyPressed(k);
	}

	bool SFMLInput::buttonWasPressed(sf::Mouse::Button b) const
	{
		auto it = m_buttonStatus.find(b);
		if (it != m_buttonStatus.end())
		{
			return it->second == status::pressed;
		}
		return false;
	}

	bool SFMLInput::buttonWasReleased(sf::Mouse::Button b) const
	{
		auto it = m_buttonStatus.find(b);
		if (it != m_buttonStatus.end())
		{
			return it->second == status::released;
		}
		return false;
	}

	bool SFMLInput::buttonIsPressed(sf::Mouse::Button b) const
	{
		return sf::Mouse::isButtonPressed(b);
	}

	void SFMLInput::clear()
	{
		m_keyStatus.clear();
		m_buttonStatus.clear();

		m_mouseWheelMovement = 0;
	}

	bool SFMLInput::pollEvents(sf::Event & e)
	{
		if (Locator::getGraphics()->pollEvents(e))
		{
			if (e.type == sf::Event::KeyPressed)
			{
				m_keyStatus[e.key.code] = status::pressed;
			}
			else if (e.type == sf::Event::KeyReleased)
			{
				m_keyStatus[e.key.code] = status::released;
			} 
			else if (e.type == sf::Event::MouseButtonPressed)
			{
				m_buttonStatus[e.mouseButton.button] = status::pressed;
			}
			else if (e.type == sf::Event::MouseButtonReleased)
			{
				m_buttonStatus[e.mouseButton.button] = status::released;
			}
			else if (e.type == sf::Event::MouseWheelMoved)
			{
				m_mouseWheelMovement = e.mouseWheel.delta;
			}

			return true;
		}
		else {
			return false;
		}
	}
	sf::Vector2i SFMLInput::getMousePositon() const
	{
		return sf::Vector2i();
	}
	int SFMLInput::getMousewheelMovement() const
	{
		return m_mouseWheelMovement;
	}
}