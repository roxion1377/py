#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		class GameMain : public State {
		private:
			static const int a = 0;
			static const std::array<int, 5> colorNum;
			Gm::Param param;
			Gm::Ptr state;
			GameMain& operator=(const GameMain&);

		public:
			GameMain(const Param* param);
			Ptr update();
			void draw()const;
		};
	}
}