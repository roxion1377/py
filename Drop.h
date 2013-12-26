#pragma once

#include "State.h"
#include "Param.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			class Drop : public State {
			private:
				R r;
				std::unique_ptr<Rect> rect;
				//std::unique_ptr<Circle> circle;
				std::vector<std::vector<bool>> drop;
				//std::vector<std::vector<>> 
			public:
				Drop(Param* _param) :
					State(DROP, _param),
					r(3),
					rect(std::make_unique<Rect>()),
					//circle(std::make_unique<Circle>()),
					drop(param->field.height(),std::vector<bool>(param->field.width(),false))
				{
					param->pair = param->pairGen();
				}
				void draw() const;
				Ptr update();
			};
		}
	}
}