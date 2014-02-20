#include "FallOjama.h"
#include "DropOjama.h"
#include "Image.h"
#include <numeric>

namespace Py {
	namespace Ev {
		namespace Gm {
			void FallOjama::draw()const {
				const auto& field = param->field;
				rect->setPos(0, 0).setSize(32 * field.width(), 32 * (field.height() - field.TH)).draw(Palette::Black);
				for (int y = field.TH; y < field.height(); y++) {
					for (int x = 0; x < field.width(); x++) {
						int rx = x;
						int ry = y - field.TH;
						Image::getImage(field.get(x, y).color).draw(rx * 32, ry * 32);
					}
				}
			}
			Ptr FallOjama::update() {
				if (!r.update()) {
					int t = std::min(30, param->nowOjama);
					std::array<int, 6> pos;
					std::iota(pos.begin(),pos.end(),1);
					param->nowOjama -= t;
					for (int i = 0; t > 0; i++) {
						std::random_shuffle(pos.begin(), pos.end());
						for (int j = 0; j < std::min(6, t); j++) {
							param->field(pos[j], i).color = Puyo::J;
						}
						t -= 6;
					}
					return std::make_shared<DropOjama>(param);
				}
				return getPtr();
			}
		}
	}
}