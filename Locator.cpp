#include "Locator.h"

namespace brkr {
	Graphics* Locator::m_graphicService = nullptr;
	NullGraphics Locator::m_nullGraphics;

	Input* Locator::m_inputService = nullptr;
	NullInput Locator::m_nullService;
}