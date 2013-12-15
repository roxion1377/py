#pragma once

#include "State.h"
#include "Ev.h"
#include "GameMain.h"
#include "Field.h"
#include "PuyoPair.h"
#include <vector>

namespace Py{
	class Play : public State {
	private:
		std::vector<Ev::Ptr> state;
		const std::unique_ptr<Font> font;
		void initialize();
	public:
		Play(const std::vector<Ev::Ptr>& _state) :
			state(_state),font(std::make_unique<Font>()){
			for (Ev::Ptr& st : state) st = std::make_shared<Ev::GameMain>(st->getParam());
		}
		void draw() const ;
		Ptr update();
	};
}