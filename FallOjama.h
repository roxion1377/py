#pragma once

#include "State.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			class FallOjama : public State {
			private:
				R r;
				std::unique_ptr<Rect> rect;
			public:
				FallOjama(Param* param) :
					State(WAIT, param),
					r(1),
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