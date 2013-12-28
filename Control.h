#pragma once

#include "State.h"
#include "Param.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			class Control : public State {
			private:
				R r;
				std::unique_ptr<Rect> rect;
				//std::unique_ptr<Circle> circle;
				bool inside(const Pair& pair)const;
				bool canRotate(int d)const;
				void rotate(int d);
			public:
				Control(Param* _param) :
					State(CONTROL,_param),
					r(30),
					rect(std::make_unique<Rect>())
					//circle(std::make_unique<Circle>())
				{
					param->pair = param->pairGen();
					r.start();
				}
				void draw() const;
				Ptr update();
			};
		}
	}
}