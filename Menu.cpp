#include "Menu.h"
#include "Title.h"
#include "Init.h"

namespace Py {
	Menu::Menu()
	{
		font = std::make_unique<Font>(30);
	}

	void Menu::draw() const
	{
		font->draw(L"ƒƒjƒ…[‚É‚È‚é—\’è");
	}

	Ptr Menu::update()
	{
		if (Input::KeyQ.clicked) {
			return std::make_shared<Title>();
		}
		if (Input::KeyEnter.clicked) {
			return std::make_shared<Init>();
		}
		return getPtr();
	}
}