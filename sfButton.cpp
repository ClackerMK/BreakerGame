#include "sfButton.h"


namespace brk
{
	namespace gui
	{
		
		sfButton::sfButton()
		{
			m_mouseoverLast = m_mouseoverNow = false;
		}


		sfButton::~sfButton()
		{
		}

		void sfButton::update(sf::Time dt)
		{
			auto input = Locator::getInput();
			auto mousePos = sf::Vector2f(input->getMousePositon());
			
			m_mouseoverLast = m_mouseoverNow;
			m_mouseoverNow = m_Sprite.getGlobalBounds().contains(mousePos);
			
			for each (auto it in m_boundEvents)
			{
				triggerEvent(it);
			}
		}
		void sfButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
		{
			target.draw(m_Sprite, states);
		}

		void sfButton::triggerEvent(const std::pair<GUI_Events, std::function<void()>>& ele)
		{
			auto ok = false;
			auto input = Locator::getInput();
			switch (ele.first)
			{
				case GUI_Events::onLeftClick:
					ok = (m_mouseoverNow && input->buttonWasPressed(sf::Mouse::Button::Left));
					break;
				case GUI_Events::onLeftRelease:
					ok = (m_mouseoverNow && input->buttonWasReleased(sf::Mouse::Button::Left));
					break;
				case GUI_Events::onRightClick:
					ok = (m_mouseoverNow && input->buttonWasPressed(sf::Mouse::Button::Right));
					break;
				case GUI_Events::onRightRelease:
					ok = (m_mouseoverNow && input->buttonWasReleased(sf::Mouse::Button::Right));
					break;
				case GUI_Events::onMidClick:
					ok = (m_mouseoverNow && input->buttonWasPressed(sf::Mouse::Button::Middle));
					break;
				case GUI_Events::onMidRelease:
					ok = (m_mouseoverNow && input->buttonWasReleased(sf::Mouse::Button::Middle));
					break;
				case GUI_Events::onMouseOver:
					ok = (m_mouseoverNow);
					break;
				case GUI_Events::onMouseEnter:
					ok = (m_mouseoverNow && !m_mouseoverLast);
					break;
				case GUI_Events::onMouseLeave:
					ok = (!m_mouseoverNow && m_mouseoverLast);
					break;
			}
		}
	}
}