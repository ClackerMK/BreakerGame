#include "Map.h"

#include <assert.h>
using namespace brkr;

CellLayer::CellLayer(int x, int y) : cells_(x, std::vector<sharedEntity>(y, nullptr)), x_(x), y_(y)
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

std::tuple<std::size_t, std::size_t> CellLayer::getSize() const
{
	return std::make_tuple(x_, y_);
}


CellGrid::CellGrid(int x, int y, int z) : layers_(z, CellLayer(x, y)), x_(x), y_(y), z_(z)
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

std::tuple<std::size_t, std::size_t, std::size_t> CellGrid::getSize() const
{
	return std::make_tuple(x_, y_, z_);
}
