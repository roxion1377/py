#include "Load.h"
#include <Siv3D.hpp>
#include "Image.h"
#include "Title.h"

namespace Py {
	Ptr Load::update() {
		Font(50).drawCenter(L"now loading...", 50);
		Image::load();
		return std::make_shared<Title>();
	}
}