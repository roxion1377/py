#include "Play.h"

namespace Py {
	void Play::draw() const
	{
		static const std::array<Vec2, 2> trans = { Vec2(10, 10), { 320 + 10, 10 } };

		for (size_t i = 0; i < state.size(); i++) {
			Graphics::Set2DTransform({ 1.0, 1.0 }, trans[i]);
			state[i]->draw();
			font->draw(Format(param[i].chainScore, L"\n", param[i].chainScoreExt, L"\n", param[i].nowOjama));
		}

		Graphics::Reset2DState();
	}

	Ptr Play::update()
	{
		for (Ev::Gm::Ptr& st : state) st = st->update();
		return getPtr();
	}
}