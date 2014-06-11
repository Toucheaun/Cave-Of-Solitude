#include "StateMachine.h"


StateMachine::StateMachine(void)
{
}


StateMachine::~StateMachine(void)
{
}

void StateMachine::SetNewState(State s)
{
	state = s;
}