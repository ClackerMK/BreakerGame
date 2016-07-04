#pragma once

#include "sfGUIElement.h"

#include "Locator.h"

namespace brkr
{
	namespace gui
	{
		class sfButton :
			public sfGUIElement
		{
		public:
			sfButton();
			~sfButton();

			void update(sf::Time dt) override;
			void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

			// Setter & Getter
			// Texture
			void setTexture(sf::Texture &tex) 
			{
				m_Sprite.setTexture(tex);
			}
			void setTexture(sf::Texture &tex, sf::IntRect subrect)
			{
				setTexture(tex);
				setSubrect(subrect);
			}
			void setSubrect(sf::IntRect subrect)
			{
				m_Sprite.setTextureRect(subrect);
			}

			// Position
			void setPosition(sf::Vector2f vec)
			{
				m_Sprite.setPosition(vec);
			}
			sf::Vector2f getPosition()
			{
				return m_Sprite.getPosition();
			}

			// Rotation
			void setRotation(float angle)
			{
				m_Sprite.setRotation(angle);
			}
			float getRotation()
			{
				return m_Sprite.getRotation();
			}

			// Scale
			void setScale(sf::Vector2f scale)
			{
				m_Sprite.setScale(scale);
			}
			sf::Vector2f getScale()
			{
				return m_Sprite.getScale();
			}

		private:
			sf::Sprite m_Sprite;

			bool	m_mouseoverLast;
			bool	m_mouseoverNow;

			void	triggerEvent(const std::pair<GUI_Events, std::function<void()>>& element);
		};
	}
}