#pragma once

#include <vector>
#include <tuple>

#include <SFML/Graphics.hpp>

#include "GameEntity.h"


namespace brk
{
	class CellLayer
	{
	private:
		std::vector<std::vector<sharedEntity>> cells_;

		const int		x_;
		const int		y_;

		const int		size_;
	public:
		CellLayer(int x, int y, int size);	// Standardconstructor
		CellLayer(const CellLayer& r);		// Copyconstructor

		void					setEntity(sf::Vector2i v, sharedEntity entity);
		sharedEntity			getEntity(sf::Vector2i v) const;
		void					move(sf::Vector2i v1, sf::Vector2i v2);
		std::tuple<int, int>	getSize() const;
	};


	class CellGrid
	{
	private:
		std::vector<CellLayer> layers_;
		const int		x_;
		const int		y_;
		const int		z_;

		const int		size_;
	public:
		CellGrid(int x, int y, int z, int size);
		CellGrid(const CellGrid& r);

		void						setEntity(sf::Vector3i v, sharedEntity entity);
		sharedEntity				getEntity(sf::Vector3i v) const;
		void						move(sf::Vector3i v1, sf::Vector3i v2);
		CellLayer					getLayer(int z) const;
		std::tuple<int, int, int>	getSize() const;

	};


};