#include "DropOjama.h"
#include "Wait.h"
#include "Image.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			void DropOjama::draw()const{
				const auto& field = param->field;
				rect->setPos(0, 0).setSize(32 * field.width(), 32 * (field.height()-field.TH)).draw(Palette::Black);
				for (int y = field.TH; y < field.height(); y++) {
					for (int x = 0; x < field.width(); x++) {
						int rx = x;
						int ry = y - field.TH;
						Image::getImage(field.get(x, y).color).draw(rx * 32, ry * 32 - (drop[y][x] ? 32 * r.rate() : 0));
					}
				}
			}
			Ptr DropOjama::update() {
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
						return std::make_shared<Wait>(param);
					}
				}
				r.update();
				return getPtr();
			}
		}
	}
}