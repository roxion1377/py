#include "Control.h"
#include "Drop.h"
#include "Image.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		namespace Gm {
			void Control::draw()const
			{
				const auto& field = param->field;
				rect->setPos(0, 0).setSize(32 * field.width(), 32 * (field.height()-field.TH)).draw(Palette::Black);
				for (int y = field.TH; y < field.height(); y++) {
					for (int x = 0; x < field.width(); x++) {
						int rx = x;
						int ry = y - field.TH;
						Image::getImage(field.get(x, y).color).draw(rx * 32, ry * 32);
					}
				}
				for (const Puyo& puyo : param->pair.getPair()) {
					int rx = puyo.p.x;
					int ry = puyo.p.y-field.TH;
					Image::getImage(puyo.color).draw(rx * 32, ry * 32 - 32 * r.rate());
				}
			}
			bool Control::inside(const Pair& pair)const
			{
				const auto& p = pair.getPair();
				return all_of(p.begin(), p.end(), [=](const Puyo& p) {
					return param->field.get(p.p).color == Puyo::E;
				});
			}
			bool Control::canRotate(int d)const
			{
				return inside(param->pair.rotate(d).getPair());
			}
			void Control::rotate(int d)
			{
				if (canRotate(d)) {
					param->pair = param->pair.rotate(d);
				}
				else {
					const auto& nextPair = [=](const Pair& pair) {
						if (pair.getDist() == 1) {
							return pair + Point(-1, 0);
						}
						if (pair.getDist() == 2) {
							return pair + Point(0, -1);
						}
						if (pair.getDist() == 3) {
							return pair + Point(1, 0);
						}
						return pair + Point(0, 0);
					}(param->pair.rotate(d));
					if (inside(nextPair)) {
						param->pair = nextPair;
					}
				}
			}
			Ptr Control::update()
			{
				++count;
				auto& pair = param->pair;
				//if (Input::KeyR.clicked) pair = param->pairGen();
				if (Input::KeyZ.clicked) {
					rotate(-1);
				}
				if (Input::KeyX.clicked) {
					rotate(1);
				}
				if (Input::KeyDown.pressed) {
					if(!r.done()) r += 14;
					else w += 14;
				}
				if (Input::KeyLeft.pressed) {
					if (inside(pair + Point(-1, 0))) pair += Point(-1, 0);
				}
				if (Input::KeyRight.pressed) {
					if (inside(pair + Point(1, 0))) pair += Point(1, 0);
				}
				if (!r.update()) {
					if (!inside(pair + Point(0, 1))) {
						if (!w.update()) {
							Field& field = param->field;
							for (const Puyo& p : pair.getPair()) field.set(p.p, p.color);
							pair = param->pairGen();
							return std::make_shared<Drop>(param);
						}
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