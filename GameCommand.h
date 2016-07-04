#pragma once

#include "World.h"

namespace brk
{
	class GameCommand
	{
	public:
		virtual ~GameCommand() {}
		virtual World operator()(World& world);
	};
}