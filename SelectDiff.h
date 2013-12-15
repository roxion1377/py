#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		class SelectDiff : public State {
		private:
			const std::unique_ptr<Font> font;
			int nowSelectDiff;
			SelectDiff& operator=(const SelectDiff& e);
		public:
			SelectDiff();
			Ptr update();
			void draw()const;
		};
	}
}
