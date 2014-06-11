#ifndef StateMachine_H
#define StateMachine_H

enum State
{
	GUARD = 0,
	ATTACK
};

class StateMachine
{
public:
	StateMachine(void);
	~StateMachine(void);
	void SetNewState(State s);

	State state;
};
#endif