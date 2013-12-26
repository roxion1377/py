#include "Drop.h"
#include "Remove.h"
#include "Image.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			void Drop::draw()const{
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
						Image::getImage(field.get(x, y).color).draw(x * 32, y * 32 - (drop[y][x] ? 32 * r.rate() : 0));
						/*
						const Color color = getColor(field.get(x, y).color);
						rect->setPos(x * 32, y * 32).setSize(32, 32).draw(Palette::Black);
						if (field.get(x, y).color >= 0) circle->setPos(x * 32 + 16, y * 32 + 16 - (drop[y][x] ? 32*r.rate() : 0)).setSize(16).draw(color);
						else rect->setPos(x * 32, y * 32).setSize(32, 32).draw(color);
						*/
					}
				}
			}
			Ptr Drop::update() {
				++count;
				if (r.done()) {
					Field& f = param->field;
					for (auto& v : drop) std::fill(v.begin(), v.end(), false);
					for (int j = 1; j < f.width() - 1; j++) {
						for (int i = f.height() - 2; i > 0; i--) {
							if (f(j, i).color == Puyo::E && f(j, i - 1).color != Puyo::E) {
								while (i > 0) {
									drop[i][j] = true;
									std::swap(f(j, i), f(j, i - 1));
									i--;
								}
								r.start();
								break;
							}
						}
					}
					if (r.done()) {
						return std::make_shared<Remove>(param);
					}
				}
				r.update();
				return getPtr();
			}
		}
	}
}