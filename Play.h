#pragma once

#include "State.h"
#include "Ev.h"
#include "GameMain.h"
#include "Field.h"
#include "PuyoPair.h"
#include "Control.h"
#include <vector>

namespace Py{
	class Play : public State {
	private:
		std::vector<Ev::Gm::Ptr> state;
		std::vector<Ev::Gm::Param> param;
		const std::unique_ptr<Font> font;
		void initialize();
	public:
		Play(const std::vector<Ev::Ptr>& _state) :
			state(_state.size()),
			param(_state.size()),
			font(std::make_unique<Font>())
		{
			const std::array<int, 5> colorNum = {
				3, 3, 4, 4, 5
			};
			for (size_t i = 0; i < _state.size(); i++) {
				param[i] = Ev::Gm::Param(Field(8, 13), 114514, colorNum[_state[i]->getParam().diff]);
				state[i] = std::make_shared<Ev::Gm::Control>(&param[i]);
			}
			for (size_t i = 0; i < _state.size(); i++) {
				for (int x : _state[i]->getParam().enemy) {
					state[i]->getParam()->enemy.push_back(&param[x]);
				}
			}
			//for (Ev::Gm::Ptr& st : state) st = std::make_shared<Ev::GameMain>(st->getParam());
			//for (Ev::Gm::Ptr& st : state) st = std::make_shared<Ev::Gm::Control>(st->getParam());
		}
		void draw() const ;
		Ptr update();
	};
}