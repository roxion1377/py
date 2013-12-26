#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		namespace Gm {
			class Wait : public State {
			private:
				R r;
				std::unique_ptr<Rect> rect;
			public:
				Wait(Param* param) :
					State(WAIT,param),
					r(5),
					rect(std::make_unique<Rect>()) {
					r.start();
					param->chain = 0;
					param->chainScore = 0;
				}
				void draw()const;
				Ptr update();
			};
		}
	}
}