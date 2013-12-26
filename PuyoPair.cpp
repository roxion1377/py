#include "PuyoPair.h"

namespace Py {
	const std::array<Point, 4> Pair::d = {
		Point(0, -1),
		Point(1, 0),
		Point(0, 1),
		Point(-1, 0)
	};
	Pair& Pair::operator+=(const Point& d) {
		return *this = *this + d;
	}
	Pair Pair::operator+(const Point& d)const{
		Pair ret(*this);
		std::for_each(ret.pair.begin(), ret.pair.end(), [=](Puyo& a) {
			a.p += d;
		});
		return ret;
	}
	Pair Pair::rotate(int u) const {
		int _dist = (dist + u + d.size()) % d.size();
		auto _pair = pair;
		for (size_t i = 1; i < _pair.size(); ++i) {
			_pair[i].p = _pair[0].p + d[_dist];
		}
		return Pair(_pair, _dist);
	}
}