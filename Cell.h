#pragma once

namespace Py {
	struct Cell {
		enum CellType : int {
			W = -2,
			E,J,R,G,B,Y,P,
		};
		int state;
		Cell() {
			state = E;
		}
		Cell(CellType _state) :
			state(_state) {}
		Cell& operator=(const CellType& _state) {
			state = _state;
			return *this;
		}
	};
};