#include "GameMain.h"

namespace Py {
	namespace Ev {
		const std::array<int, 5> GameMain::colorNum = {
			3, 3, 4, 4, 5
		};

		GameMain::GameMain(const Param& param) :
			State(MAIN, param), font(std::make_unique<Font>(30)), rect(std::make_unique<Rect>()), circle(std::make_unique<Circle>()), field(8, 13), pairGen(114514, colorNum[param.diff])
		{
			pair = pairGen.gen();
		}

		void GameMain::draw() const
		{
			Color color;
			font->draw(Format(L"Playing!\nDiff:", param.diff));
			for (int y = 0; y < field.height(); y++) {
				for (int x = 0; x < field.width(); x++) {
					if (field.get(x, y) == Puyo::W) {
						color = Palette::Gray;
					}
					else {
						color = Palette::Black;
					}
					rect->setPos(x * 32, y * 32).setSize(32, 32).draw(color);
				}
			}
			for (const Puyo& puyo : pair.getPair()) {
				if (puyo.color == Puyo::R) color = Palette::Red;
				if (puyo.color == Puyo::G) color = Palette::Green;
				if (puyo.color == Puyo::B) color = Palette::Blue;
				if (puyo.color == Puyo::Y) color = Palette::Yellow;
				if (puyo.color == Puyo::P) color = Palette::Purple;
				circle->setPos(puyo.p.x * 32 + 16, puyo.p.y * 32 + 16).setSize(16).draw(color);
			}
		}

		Ptr GameMain::update()
		{
			if (Input::KeyR.clicked) pair = pairGen.gen();
			if (Input::KeyDown.clicked) {
				pair += Point(0, 1);
			}
			if (Input::KeyLeft.clicked) {
				pair += Point(-1, 0);
			}
			if (Input::KeyRight.clicked) {
				pair += Point(1, 0);
			}
			return getPtr();
		}
	}
}