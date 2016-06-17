#pragma once
#include <SFML/Graphics.hpp>

#include <map>
#include <functional>

namespace brk
{
	namespace gui
	{
		enum class GUI_Events
		{
			onLeftClick,
			onLeftRelease,
			onRightClick,
			onRightRelease,
			onMidClick,
			onMidRelease,
			onMouseOver,
			onMouseEnter,
			onMouseLeave
		};

		class sfGUIElement :
			public sf::Drawable
		{
		public:
			virtual void update(sf::Time dt) = 0;

			void bindEvent(GUI_Events e, std::function<void()> f)
			{
				m_boundEvents[e] = f;
			}

		protected:
			std::map < GUI_Events, std::function<void()>>	m_boundEvents;
		};
	}
}