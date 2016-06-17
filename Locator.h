#pragma once

#include <memory>

#include "Graphics.h"
#include "NullGraphics.h"

#include "Input.h"
#include "NullInput.h"

namespace brk {
	class Locator
	{
	private:
		static Graphics* m_graphicService;
		static NullGraphics m_nullGraphics;

		static Input* m_inputService;
		static NullInput m_nullService;
	public:
		static Graphics* getGraphics()
		{
			return m_graphicService;
		}
		
		static Input* getInput()
		{
			return m_inputService;
		}

		static void provideGraphics(Graphics* service)
		{
			if (service == nullptr)
				m_graphicService = &m_nullGraphics;
			else
				m_graphicService = service;
		}

		static void provideInput(Input* service)
		{
			if (service == nullptr)
				m_inputService = &m_nullService;
			else
				m_inputService = service;
		}
	};

	
}

