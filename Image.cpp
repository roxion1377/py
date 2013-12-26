#include "Image.h"

namespace Py {
	/*
	const std::array<Texture, 8> Image::puyo = {
		Texture(L"a/w.png"),
		Texture(L"a/e.png"),
		Texture(L"a/j.png"),
		Texture(L"a/r.png"),
		Texture(L"a/g.png"),
		Texture(L"a/b.png"),
		Texture(L"a/y.png"),
		Texture(L"a/p.png"),
	};
	*/
	bool Image::load() {
		static const std::array<String, 8> files = {
			L"a/w",
			L"a/e",
			L"a/j",
			L"a/r",
			L"a/g",
			L"a/b",
			L"a/y",
			L"a/p",
		};
		for (size_t i = 0; i < files.size(); i++) {
			if (!TextureAsset::Register(Format(L"p", i), Format(files[i],L".png"))) {
			}
		}
		for (size_t i = 0; i < files.size(); i++) {
			//*
			if (!TextureAsset::Register(Format(L"puyor", i), Format(files[i],L"_r",L".tif"))) {
			}
			//*/
		}
		return true;
	}
	/*
	Texture Image::getImage(const Puyo::Color& color) {
		return TextureAsset(Format(L"puyo", color + 2));
		//		return puyo[color + 2];
	}*/
	//*
	Texture Image::getImage_rev(const Puyo::Color& color) {
		return TextureAsset(Format(L"puyor", color + 2));
		//		return puyo[color + 2];
	}
	//*/
}