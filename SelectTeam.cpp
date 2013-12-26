#include "SelectTeam.h"
#include "SelectDiff.h"

namespace Py {
	namespace Ev {
		SelectTeam::SelectTeam(const Param& param) :
			State(TEAM, param), font(std::make_unique<Font>(30)), nowSelectTeam(0) {}
		void SelectTeam::draw()const {
			static const std::array<String, 2> list = { L"‚ ‚¨", L"‚ ‚©" };
			Color color;
			for (size_t i = 0; i < list.size(); i++) {
				if (static_cast<int>(i) == nowSelectTeam) {
					color = Palette::Red;
				}
				else {
					color = Palette::Gray;
				}
				font->draw(list[i], 10, 10 + i * 45, color);
			}

		}
		Ptr SelectTeam::update() {
			if (Input::KeyEnter.clicked) {
				return std::make_shared<GameWait>(param.setTeam(nowSelectTeam));
			}
			if (Input::KeyUp.clicked) {
				nowSelectTeam = (nowSelectTeam + 1) % 2;
			}
			if (Input::KeyDown.clicked) {
				nowSelectTeam = (nowSelectTeam + 1) % 2;
			}
			if (Input::KeyX.clicked) {
				return std::make_shared<SelectDiff>(param);
			}
			return getPtr();
		}
	}
}