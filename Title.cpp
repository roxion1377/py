#include "Title.h"
#include "Menu.h"

namespace Py {
	Title::Title() : font(std::make_unique<Font>(30))
	{
	}

	void Title::draw()const
	{
		font->draw(L"ƒ^ƒCƒgƒ‹‚É‚È‚é—\’è");
	}

	Ptr Title::update()
	{
		if (Input::KeyEnter.clicked) {
			return std::make_shared<Menu>();
		}
		return getPtr();
	}
}