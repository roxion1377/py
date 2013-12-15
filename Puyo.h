#pragma once

#include <array>
#include <Siv3D.hpp>

namespace Py {
	struct Puyo {
		enum Color : int {
			W = -2,
			E, J, R, G, B, Y, P,
		};
		Point p;
		Color color;
		Puyo(){}
		Puyo(int x, int y, Color _color) :
			p(x,y), color(_color) {}
		//static const std::array<Color, 5> puyo;
		Puyo& operator=(const Color& _color) {
			color = _color;
			return *this;
		}
		Puyo& operator=(const int& _color){
			color = (Color)_color;
			return *this;
		}
		bool operator==(const Color& _color)const{
			return color == _color;
		}
	};
};