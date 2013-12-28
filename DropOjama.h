#pragma once

#include "State.h"
#include "Param.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			class DropOjama : public State {
			private:
				R r;
				std::unique_ptr<Rect> rect;
				std::vector<std::vector<bool>> drop;
			public:
				DropOjama(Param* _param) :
					State(DROP, _param),
					r(3),
					rect(std::make_unique<Rect>()),
					drop(param->field.height(), std::vector<bool>(param->field.width(), false))
				{
					param->pair = param->pairGen();
				}
				void draw() const;
				Ptr update();
			};
		}
	}
}