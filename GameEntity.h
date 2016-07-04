#pragma once

#include <memory>

namespace brkr {
	class GameEntity
	{
	private:

	public:
		GameEntity();
		~GameEntity();
	};

	using sharedEntity = std::shared_ptr<GameEntity>;
}