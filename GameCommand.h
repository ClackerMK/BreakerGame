#pragma once

#include "World.h"

namespace brkr
{
	class GameCommand
	{
	public:
		virtual ~GameCommand() {}
		virtual World operator()(World& world);
	};
}