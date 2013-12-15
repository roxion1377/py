#include "GameWait.h"
#include "Param.h"

namespace Py {
	namespace Ev {
		GameWait::GameWait(const Param& param) :
			State(WAIT, param), font(std::make_unique<Font>(30))
		{
		}

		void GameWait::draw() const
		{
			font->draw(Format(L"Waiting... ", param.diff));
		}

		Ptr GameWait::update()
		{
			return getPtr();
		}
	}
}