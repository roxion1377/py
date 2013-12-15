#pragma once

#include "State.h"
#include "Field.h"
#include "PuyoPair.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		class GameMain : public State {
		private:
			static const std::array<int, 5> colorNum;
			const std::unique_ptr<Font> font;
			std::unique_ptr<Rect> rect;
			std::unique_ptr<Circle> circle;
			Field field;
			Pair pair;
			PairGen pairGen;
			GameMain& operator=(const GameMain&);
		public:
			GameMain(const Param& param);
			Ptr update();
			void draw()const;
		};
	}
}