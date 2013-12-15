#pragma once

#include <vector>
#include <Siv3D.hpp>
#include "Puyo.h"

namespace Py {
	class Pair {
	private:
		std::vector<Puyo> pair;
	public:
		Pair(){}
		Pair(int size) : pair(size) {
		}
		Pair(std::vector<Puyo>&& _pair) :
			pair(move(_pair)) {}
		const std::vector<Puyo>& getPair()const{
			return pair;
		}
		Point getMax() {

		}
		Pair& operator+=(const Point& d) {
			std::for_each(pair.begin(), pair.end(), [=](Puyo& a){
				a.p += d;
			});
			return *this;
		}
	};
	class PairGen {
	private:
		RNG rng;
		UniformDistribution<int> dist;
	public:
		PairGen() :
			rng(),dist(1,2) {}
		PairGen(int seed,int colorNum) :
			rng(seed),dist(1,colorNum) {}
		Pair gen() {
			return Pair({ Puyo(3, 0, (Puyo::Color)dist(rng)), Puyo(3, 1, (Puyo::Color)dist(rng)) });
		}
	};
};