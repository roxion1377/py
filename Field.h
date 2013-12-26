#pragma once

#include <vector>
#include "Puyo.h"

namespace Py {
	class Field {
	private:
		/*const */int W;
		/*const */int H;
		std::vector<std::vector<Puyo>> puyoState;
	public:
		Field() :
			W(0), H(0), puyoState(0, std::vector<Puyo>(0)) {}
		Field(int _W,int _H) :
			W(_W), H(_H), puyoState(_H, std::vector<Puyo>(_W,Puyo::E)) {
			for ( int y = 0; y < H; y++ ) {
				puyoState[y][0] = puyoState[y][W - 1] = Puyo::W;
			}
			for ( int x = 0; x < W; x++ ) {
				puyoState[H - 1][x] = Puyo::W;
			}
		}
		int width()const{ return W; }
		int height()const{ return H; }
		Puyo get(int x, int y)const{ return puyoState[y][x]; }
		Puyo get(const Point& p)const{ return get(p.x, p.y); }
		Puyo& operator()(int x, int y){ return puyoState[y][x]; }
		Puyo& operator()(const Point& p){ return (*this)(p.x,p.y); }
		/*Puyo*/void set(int x, int y, Puyo::Color color)  { /*return*/ puyoState[y][x] = color; }
		/*Puyo*/void set(const Point& p, Puyo::Color color){ /*return*/ set(p.x, p.y, color); }
	};
};