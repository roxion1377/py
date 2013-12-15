#include "Game.h"
#include "Title.h"

namespace Py {

	Game::Game()
	{
		state = std::make_shared<Title>();
	}

	bool Game::update()
	{
		if (state == nullptr) return false;
		state->draw();
		state = state->update();
		return true;
	}

}