#ifndef StateMachine_H
#define StateMachine_H

enum State
{
	GUARD = 0,
	CHASE,
};

class StateMachine
{
public:
	StateMachine(State s);
	StateMachine();
	~StateMachine(void);
	void SetNewState(State s);

	State state;
};
#endif