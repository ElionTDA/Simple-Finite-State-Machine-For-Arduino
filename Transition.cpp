﻿#include "Transition.h"
#include "State.h"
#include "FSM.h"
#include "SimpleList/SimpleList.h"




Transition::Transition(bool (*Condition)(),void (*Action)())
{
	_Condition = Condition;
	_Action = Action;
	FSM::Instance.add(this);
}

void Transition::now(State* from, State* to)
{
	from->nextState = false;
	to->nextState = true;
}

void Transition::Execute()
{
	if(_Condition != nullptr)
	{
		if(_Condition()) {
			_Action();
		}
	}

}


