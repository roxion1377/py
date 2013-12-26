#include "Utils.h"

namespace Utils {
	int bitCount(unsigned u) {
		int res = 0;
		while (u > 0) {
			res += u & 1;
			u >>= 1;
		}
		return res;
	}
}