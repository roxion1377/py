#include "Title.h"
#include "Menu.h"

namespace Py {
	Title::Title() : font(std::make_unique<Font>(30))
	{
	}

	void Title::draw()const
	{
		font->draw(L"タイトルになる予定");
	}

	Ptr Title::update()
	{
		if (Input::KeyEnter.clicked) {
			return std::make_shared<Menu>();
		}
		return getPtr();
	}
}