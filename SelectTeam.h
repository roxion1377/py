#pragma once

#include "State.h"
#include "GameWait.h"

namespace Py {
	namespace Ev {
		class SelectTeam : public State {
		private:
			const std::unique_ptr<Font> font;
			int nowSelectTeam;
		public:
			SelectTeam(const Param& param);
			void draw()const;
			Ptr update();
		};
	}
}