#pragma once

#include "State.h"
#include <Siv3D.hpp>

namespace Py {
	namespace Ev {
		class GameMain : public State {
		private:
			static const int a = 0;
			static const std::array<int, 5> colorNum;
			Gm::Param param;
			Gm::Ptr state;
			GameMain& operator=(const GameMain&);
			/*
			struct R {
				int time;
				int count;
				bool done;
				R() {}
				R(int _time) :
					time(_time), count(_time), done(true) {}
				void start(const int _time) {
					time = _time;
					count = _time;
					done = false;
				}
				void start() {
					count = time;
					done = false;
				}
				void restart() {
					count += time;
					done = false;
				}
				void addCount(int _count) {
					count -= _count;
				}
				bool update() {
					if (done) return false;
					count -= 1;
					if (count <= 0) {
						done = true;
						return false;
					}
					else {
						return true;
					}
				}
				double rate() const {
					return static_cast<double>(count) / time;
				}
			};

			R fall, wait, drop;
			*/

		public:
			GameMain(const Param* param);
			Ptr update();
			void draw()const;
		};
	}
}