#include "Init.h"
#include "SelectDiff.h"
#include "Play.h"
#include <algorithm>

namespace Py {
	Init::Init() : state(2), nowPlayer(state.begin()), font(std::make_unique<Font>(30))
	{
		for (Ev::Ptr& st : state) {
			st = std::make_shared<Ev::SelectDiff>();
		}
	}

	void Init::initialize()
	{
	}

	void Init::draw() const
	{
		static const std::array<Vec2, 2> trans = { Vec2(10, 10), { 320 + 10, 10 } };

		if (nowPlayer == state.end()) {
			font->drawCenter(L"€”õ‚¨‚Á‚¯`", Vec2(0, 200));
		}

		for (size_t i = 0; i < state.size(); i++) {
			Graphics::Set2DTransform({ 1.0, 1.0 }, trans[i]);
			state[i]->draw();
		}

		Graphics::Reset2DState();
	}

	Ptr Init::update()
	{
		if (nowPlayer == state.end()) {
			return std::make_shared<Play>(state);
		}
		else {
			*nowPlayer = (*nowPlayer)->update();
			if ((*nowPlayer)->getType() == Ev::State::WAIT) ++nowPlayer;
		}
		return getPtr();
	}
}