#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		class GameWait : public State {
		private:
			const std::unique_ptr<Font> font;
			GameWait& operator=(const GameWait&);
		public:
			GameWait(const Param& param);
			Ptr update();
			void draw()const;
		};
	}
}
