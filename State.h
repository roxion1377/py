#pragma once

#include <memory>
#include "Forward.h"
#include "Param.h"

namespace Py {
	template<class T> struct StateBase : std::enable_shared_from_this<T> {
		typedef std::shared_ptr<T> Ptr;
		virtual Ptr update() = 0;
		virtual void draw() const {}
		Ptr getPtr() {
			return shared_from_this();
		}
	};
	//template<class T> using Ptr = std::shared_ptr<StateBase<T>>;
	//Ptr<State> state;Ç›ÇΩÇ¢Ç…êÈåæ
	class State : public StateBase<State> {
	};
	typedef std::shared_ptr<State> Ptr;
	namespace Ev {
		class State : public StateBase<State> {
		public:
			enum Type : int {
				DIF, WAIT, MAIN,TEAM
			};
		protected:
			Type type;
			State(const Type& _type) :
				type(_type) {}
			State(const Type& _type, const Param& _param) :
				type(_type), param(_param) {}
			Param param;
		public:
			Type getType() const { return type; }
			Param* getParam() { return &param; }
		};
		typedef std::shared_ptr<State> Ptr;

		namespace Gm {
			class State : public StateBase<State> {
			public:
				enum Type : int {
					CONTROL,FALL, WAIT,DROP,REMOVE
				};
			protected:
				Type type;
				int count;
				Param* param;
				State(const Type& _type) :
					type(_type), count(0) {}
				State(const Type& _type, Param* _param) :
					type(_type), count(0), param(_param) {}
				class R {
				private:
					int time, now;
				public:
					R(int _time) :
						time(_time), now(0) {}
					void start() {
						now = time;
					}
					void reset() {
						now += time;
					}
					void add(int count) {
						now -= count;
					}
					bool update() {
						now -= 1;
						return !done();
					}
					double rate() const {
						return static_cast<double>(now) / time;
					}
					bool done() const { return now <= 0; }
					R& operator += (int count) { now -= count; return *this; }
				};
			public:
				int getCount() const { return count; }
				Type getType() const { return type; }
				Param* getParam() { return param; }
			};
			typedef std::shared_ptr<State> Ptr;
		}
	}
};