#include "Control.h"
#include "Drop.h"
#include "Image.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		namespace Gm {
			void Control::draw()const
			{
				static const auto getColor = [](const Puyo::Color& color) {
					if (color == Puyo::R) return Palette::Red;
					if (color == Puyo::G) return Palette::Green;
					if (color == Puyo::B) return Palette::Blue;
					if (color == Puyo::Y) return Palette::Yellow;
					if (color == Puyo::P) return Palette::Purple;
					if (color == Puyo::E) return Palette::Black;
					return Palette::Gray;
				};
				const auto& field = param->field;
				rect->setPos(0, 0).setSize(32 * field.width(), 32 * field.height()).draw(Palette::Black);
				for (int y = 0; y < field.height(); y++) {
					for (int x = 0; x < field.width(); x++) {
						Image::getImage(field.get(x, y).color).draw(x * 32, y * 32);
					}
				}
				for (const Puyo& puyo : param->pair.getPair()) {
					Image::getImage(puyo.color).draw(puyo.p.x * 32, puyo.p.y * 32 - 32 * r.rate());
				}
			}
			Ptr Control::update()
			{
				++count;
				auto& pair = param->pair;
				if (Input::KeyR.clicked) pair = param->pairGen();
				const auto check = [=](const Puyo& p) {
					return param->field.get(p.p).color == Puyo::E;
				};
				if (Input::KeyZ.clicked) {
					const auto& nextPair = pair.rotate(-1);
					const auto& next = nextPair.getPair();
					if (std::all_of(next.begin(), next.end(), check)) pair = nextPair;
				}
				if (Input::KeyX.clicked) {
					const auto& nextPair = pair.rotate(1);
					const auto& next = nextPair.getPair();
					if (std::all_of(next.begin(), next.end(), check)) pair = nextPair;
				}
				if (Input::KeyDown.pressed) {
					r += 14;
				}
				if (Input::KeyLeft.pressed) {
					const auto& next = (pair + Point(-1, 0)).getPair();
					if (std::all_of(next.begin(), next.end(), check)) pair += Point(-1, 0);
				}
				if (Input::KeyRight.pressed) {
					const auto& next = (pair + Point(1, 0)).getPair();
					if (std::all_of(next.begin(), next.end(), check)) pair += Point(1, 0);
				}
				if (!r.update()) {
					const auto& next = (pair + Point(0, 1)).getPair();
					if (!std::all_of(next.begin(), next.end(), check)) {
						Field& field = param->field;
						for (const Puyo& p : pair.getPair()) field.set(p.p, p.color);
						pair = param->pairGen();
						//r.start();
						return std::make_shared<Drop>(param)->update();// ->update();
					}
					else {
						pair += Point(0, 1);
						r.reset();
					}
				}
				return getPtr();
			}
		}
	}
}