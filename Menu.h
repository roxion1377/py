#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	class Menu : public State {
	private:
		std::unique_ptr<Font> font;
	public:
		Menu();
		void draw() const ;
		Ptr update();
	};
};