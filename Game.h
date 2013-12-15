#pragma once

#include "State.h"

namespace Py {
	class Game {
	private:
		Ptr state;
	public:
		Game();
		bool update();
	};
}