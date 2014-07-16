#include "StateMachine.h"


StateMachine::StateMachine(State s)
{
	state = s;
}

StateMachine::StateMachine()
{
	state = GUARD;
}


StateMachine::~StateMachine(void)
{
}

void StateMachine::SetNewState(State s)
{
	state = s;
}