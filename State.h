#pragma once

#include <memory>
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
	/*
	template<typename Tkey_, typename Tvalue_>
	using my_map_type = std::map<Tkey_, Tvalue_>;
	*/
	class State : public StateBase<State> {
	};
	typedef std::shared_ptr<State> Ptr;
	namespace Ev {
		class State : public StateBase<State> {
		public:
			enum Type : int {
				DIF, WAIT, MAIN
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
			Param getParam() const { return param; }
		};
		typedef std::shared_ptr<State> Ptr;

		namespace Gm {
			class State : public StateBase<State> {
			public:
				enum Type : int {
					GEN,
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
				Param getParam() const { return param; }
			};
			typedef std::shared_ptr<State> Ptr;
		}
	}
};