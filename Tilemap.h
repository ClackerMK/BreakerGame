#pragma once

#include <memory>

#include <SFML/Graphics.hpp>


namespace brkr {
	class Tilemap
	{
	public:
		Tilemap(sf::Texture& tex, sf::Vector2i size) : tex_(tex), size_(size)
		{

		}

		std::unique_ptr<sf::Sprite> getSprite(sf::Vector2i cord) const
		{
			sf::IntRect rec;

			rec.height = size_.y;
			rec.width = size_.x;
			rec.top = cord.y * size_.y;
			rec.left = cord.x = size_.x;

			return std::make_unique<sf::Sprite>(tex_, rec);
		}

		std::unique_ptr<sf::Sprite> getSprite(int x, int y) const
		{
			return getSprite(sf::Vector2i(x, y));
		}

		const sf::Texture& getTexture() const
		{
			return tex_;
		}
	private:
		sf::Texture &tex_;
		sf::Vector2i size_;
	};
}