#pragma once

#include <memory>

namespace brk {
	class GameEntity
	{
	private:

	public:
		GameEntity();
		~GameEntity();
	};

	using sharedEntity = std::shared_ptr<GameEntity>;
}