#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	class Title : public State {
	private:
		std::unique_ptr<Font> font;
	public:
		Title();
		Ptr update();
		void draw() const ;
	};
}