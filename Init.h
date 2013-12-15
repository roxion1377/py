#pragma once

#include "State.h"
#include "Ev.h"
#include <vector>
#include <Siv3D.hpp>

namespace Py{
	class Init : public State {
	private:
		std::vector<Ev::Ptr> state;
		const std::unique_ptr<Font> font;
		std::vector<Ev::Ptr>::iterator nowPlayer;
		void initialize();
	public:
		Init();
		void draw() const ;
		Ptr update();
	};
}