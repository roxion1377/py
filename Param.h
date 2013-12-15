#pragma once

namespace Py {
	namespace Ev {
		struct Param {
			int diff;
			Param() :
				diff(0) {}
			Param(int _diff) :
				diff(_diff) {}
		};
		namespace Gm {
			struct Param {
				static const std::array<int, 5> colorNum;
				Field field;
				Pair pair;
				PairGen pairGen;
			};
		}
	}
}
