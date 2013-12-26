#pragma once

#include <vector>
#include <Siv3D.hpp>
#include "Puyo.h"

namespace Py {
	class Pair {
	private:
		std::vector<Puyo> pair;
		int dist;
		static const std::array<Point, 4> d;
	public:
		Pair() :
			dist(0) {}
		Pair(int size) :
			pair(size), dist(0) {}
		Pair(const std::vector<Puyo>& _pair) :
			pair(_pair), dist(0) {}
		Pair(const Pair& _pair) :
			pair(_pair.pair), dist(_pair.dist) {}
		Pair(const Pair& _pair,int _dist) :
			pair(_pair.pair), dist(_dist) {}
		std::vector<Puyo> getPair()const{ return pair; }
		int getDist() const { return dist; }
		Pair& operator+=(const Point& d);
		Pair operator+(const Point& d)const;
		Pair rotate(int u) const;
		/*
		Point minmaxX() {
			const auto& x = std::minmax_element(pair.begin(), pair.end(), [](const Puyo& a, const Puyo& b) {
				if (a.p.x < b.p.x) return true;
				else return false;
			});
			return Point(x.first->p.x, x.second->p.x);
		}
		Point minmaxY() {
			const auto& y = std::minmax_element(pair.begin(), pair.end(), [](const Puyo& a, const Puyo& b) {
				if (a.p.y < b.p.y) return true;
				else return false;
			});
			return Point(y.first->p.y, y.second->p.y);
		}
		std::pair<Point, Point> minmax() {
			return std::make_pair(minmaxX(), minmaxY());
		}
		*/
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
		Pair operator()() {
			return Pair({ Puyo(3, 1, (Puyo::Color)dist(rng)), Puyo(3, 0, (Puyo::Color)dist(rng)) });
		}
	};
};