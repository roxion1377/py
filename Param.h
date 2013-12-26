#pragma once

#include "Field.h"
#include "PuyoPair.h"
#include "Forward.h"

namespace Py {
	namespace Ev {
		namespace Gm {
			struct Param {
				Field field;
				Pair pair;
				PairGen pairGen;
				int chain;
				int chainScore, chainScoreExt;
				int nowOjama;
				Param(){}
				Param(const Field& _field,const int seed,const int colNum) :
					field(_field),pairGen(seed,colNum),chain(0),chainScore(0),chainScoreExt(0),nowOjama(0) {
					pair = pairGen();
				}
			};
		}
		struct Param {
			int diff, team;
			Param() :
				diff(0) {}
			Param(int _diff) :
				diff(_diff) {}
			Param(const Param& param) :
				diff(param.diff), team(param.team)
			{
			}
			Param setTeam(int _team){
				Param p = *this;
				p.team = _team;
				return p;
			}
		};
	}
}
