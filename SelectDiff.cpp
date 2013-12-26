#include "SelectDiff.h"
#include "GameWait.h"
#include "SelectTeam.h"

namespace Py {
	namespace Ev {
		SelectDiff::SelectDiff() : State(DIF), font(std::make_unique<Font>(30))
		{
			nowSelectDiff = 2;
		}

		SelectDiff::SelectDiff(const Param& param) : State(DIF,param), font(std::make_unique<Font>(30))
		{
			nowSelectDiff = param.diff;
		}

		void SelectDiff::draw()const
		{
			static const std::array<String, 5> list = { L"åÉä√", L"ä√å˚", L"íÜêh", L"êhå˚", L"åÉêh" };
			Color color;
			for (size_t i = 0; i < list.size(); i++) {
				if (static_cast<int>(i) == nowSelectDiff) {
					color = Palette::Red;
				}
				else {
					color = Palette::Gray;
				}
				font->draw(list[i], 10, 10 + i * 45, color);
			}
		}

		Ptr SelectDiff::update()
		{
			if (Input::KeyUp.clicked) {
				nowSelectDiff = (nowSelectDiff + 4) % 5;
			}
			if (Input::KeyDown.clicked) {
				nowSelectDiff = (nowSelectDiff + 1) % 5;
			}
			if (Input::KeyEnter.clicked) {
				return std::make_shared<SelectTeam>(Param(nowSelectDiff));
			}
			return getPtr();
		}
	}
}