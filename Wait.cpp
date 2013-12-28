#include "Wait.h"
#include "Control.h"
#include "Image.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			void Wait::draw()const {
				const auto& field = param->field;
				rect->setPos(0, 0).setSize(32 * field.width(), 32 * (field.height()-field.TH)).draw(Palette::Black);
				for (int y = field.TH; y < field.height(); y++) {
					for (int x = 0; x < field.width(); x++) {
						int rx = x;
						int ry = y - field.TH;
						Image::getImage(field.get(x, y).color).draw(rx * 32, ry * 32);
					}
				}
			}
			Ptr Wait::update() {
				if (!r.update()) {
					return std::make_shared<Control>(param);
				}
				return getPtr();
			}
		}
	}
}