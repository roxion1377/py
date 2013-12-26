#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		namespace Gm {
			class Remove : public State {
			private:
				R r;
				std::unique_ptr<Rect> rect;
				std::unique_ptr<Font> font;
				//std::unique_ptr<Circle> circle;
				std::vector<std::vector<bool>> remove;
				std::vector<std::vector<bool>> used;
				static const std::array<Point, 4> d;
			private:
				std::vector<Point> vis(const Point& p);
			public:
				Remove(Param* _param) :
					State(REMOVE, _param),
					r(20),
					rect(std::make_unique<Rect>()),
					font(std::make_unique<Font>(40)),
					//circle(std::make_unique<Circle>()),
					remove(param->field.height(), std::vector<bool>(param->field.width(), false)),
					used(param->field.height(), std::vector<bool>(param->field.width(), false)){}
				void draw() const;
				Ptr update();
			};
		}
	}
}