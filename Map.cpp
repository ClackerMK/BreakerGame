#include "Map.h"

#include <assert.h>

namespace brk {
	CellLayer::CellLayer(int x, int y, int size) : cells_(x, std::vector<sharedEntity>(y, nullptr)), x_(x), y_(y), size_(size)
	{

	}

	CellLayer::CellLayer(const CellLayer & r) : cells_(r.cells_), x_(r.x_), y_(r.y_), size_(r.size_)
	{
	}

	void CellLayer::setEntity(sf::Vector2i v, sharedEntity entity)
	{
		assert(0 <= v.x && v.x < x_);
		assert(0 <= v.y && v.y < y_);

		cells_[v.x][v.y] = entity;
	}

	sharedEntity CellLayer::getEntity(sf::Vector2i v) const
	{
		assert(0 <= v.x && v.x < x_);
		assert(0 <= v.y && v.y < y_);

		return cells_[v.x][v.y];
	}

	void CellLayer::move(sf::Vector2i v1, sf::Vector2i v2)
	{
		assert(0 <= v1.x && v1.x < x_);
		assert(0 <= v1.y && v1.y < y_);
		assert(0 <= v2.x && v2.x < x_);
		assert(0 <= v2.y && v2.y < y_);

		auto dummy = cells_[v1.x][v1.y];
		cells_[v1.x][v1.y] = cells_[v2.x][v2.y];
		cells_[v2.x][v2.y] = cells_[v1.x][v1.y];
	}

	std::tuple<int, int> CellLayer::getSize() const
	{
		return std::make_tuple(x_, y_);
	}


	CellGrid::CellGrid(int x, int y, int z, int size) : layers_(z, CellLayer(x, y, size)), x_(x), y_(y), z_(z), size_(size)
	{

	}

	CellGrid::CellGrid(const CellGrid & r) : layers_(r.layers_), x_(r.x_), y_(r.y_), z_(r.z_), size_(r.size_)
	{
	}

	void CellGrid::setEntity(sf::Vector3i v, sharedEntity entity)
	{
		assert(0 <= v.z && v.z < z_);
		layers_[v.z].setEntity(sf::Vector2i(v.x,v.y), entity);
	}

	sharedEntity CellGrid::getEntity(sf::Vector3i v) const
	{
		assert(0 <= v.z && v.z < z_);
		return layers_[v.z].getEntity(sf::Vector2i(v.x, v.y));
	}

	void CellGrid::move(sf::Vector3i v1, sf::Vector3i v2)
	{
		assert(0 <= v1.z && v1.z < z_);
		assert(0 <= v2.z && v2.z < z_);

		auto dummy = layers_[v1.z].getEntity(sf::Vector2i(v1.x, v1.y));
		layers_[v1.z].setEntity(sf::Vector2i(v1.x, v1.y), layers_[v2.z].getEntity(sf::Vector2i(v2.x, v2.y)));
		layers_[v2.z].setEntity(sf::Vector2i(v2.x, v2.y), dummy);
	}

	CellLayer CellGrid::getLayer(int z) const
	{
		assert(0 <= z && z < z_);
		return layers_[z];
	}

	std::tuple<int, int, int> CellGrid::getSize() const
	{
		return std::make_tuple(x_, y_, z_);
	}
}