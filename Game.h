#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	class Game {
	private:
		Ptr state;
		std::unique_ptr<Font> font;
	public:
		Game();
		bool update();
	};
}