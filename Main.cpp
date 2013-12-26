# include <Siv3D.hpp>
#include "Game.h"

void Main()
{
	Py::Game g;
	while (System::Update()) {
		if (!g.update()) break;
	}
}
