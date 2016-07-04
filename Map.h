#pragma once

#include <vector>
#include <tuple>

#include <SFML/Graphics.hpp>

#include "GameEntity.h"


namespace brkr
{
	class CellLayer
	{
	private:
		std::vector<std::vector<sharedEntity>> cells_;

		const std::size_t		x_;
		const std::size_t		y_;
	public:
		CellLayer(int x, int y);	// Standardconstructor

		void									setEntity(sf::Vector2i v, sharedEntity entity);
		sharedEntity							getEntity(sf::Vector2i v) const;
		void									move(sf::Vector2i v1, sf::Vector2i v2);
		std::tuple<std::size_t, std::size_t>	getSize() const;
	};


	class CellGrid
	{
	private:
		std::vector<CellLayer> layers_;
		const std::size_t		x_;
		const std::size_t		y_;
		const std::size_t		z_;

	public:
		CellGrid(int x, int y, int z);

		void												setEntity(sf::Vector3i v, sharedEntity entity);
		sharedEntity										getEntity(sf::Vector3i v) const;
		void												move(sf::Vector3i v1, sf::Vector3i v2);
		CellLayer											getLayer(int z) const;
		std::tuple<std::size_t, std::size_t, std::size_t>	getSize() const;

	};

	using Map = CellGrid;
};