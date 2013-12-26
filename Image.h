#pragma once

#include "Puyo.h"
#include <Siv3D.hpp>

namespace Py {
	class Image {
	private:
		//static const std::array<Texture,8> puyo;
	public:
		static bool load();
		static inline Texture getImage(const Puyo::Color& color) {
			return TextureAsset(Format(L"p", color + 2));
		}
		static Texture getImage_rev(const Puyo::Color& color);
	};
}