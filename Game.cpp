#include "Game.h"
#include "Load.h"

namespace Py {

	Game::Game() :
		font(std::make_unique<Font>(16)), state(std::make_shared<Load>())
	{
	}

	bool Game::update()
	{
		if (state == nullptr) return false;
		state->draw();
		state = state->update();
		font->draw(Format(Profiler::FPS(), L"fps"),0,Window::Size().y-32);
		return true;
	}

}