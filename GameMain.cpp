#include "GameMain.h"
#include "Control.h"

namespace Py {
	namespace Ev {
		//*
		const std::array<int, 5> GameMain::colorNum = {
			3, 3, 4, 4, 5
		};
		//*/

		GameMain::GameMain(const Param* _param) :
			State(MAIN, *_param),
			param(Field(8, 13), 114514, colorNum[_param->diff]),
			state(std::make_shared<Gm::Control>(&param))
		{
		}

		void GameMain::draw() const
		{
			state->draw();
		}

		Ptr GameMain::update()
		{
			state = state->update();
			return getPtr();
		}
	}
}