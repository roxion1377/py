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
			W(_W), H(_H), puyoState(_H, std::vector<Puyo>(_W)) {
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
	};
};