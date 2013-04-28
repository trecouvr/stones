#pragma once
#include <vector>

enum Action_t { NONE,EMBEDDED, START_BATTLE, END_TURN }; // NONE is added only for debug purpose, please check this parameter value in the definition of the constructor.

// Addition of the class "Action" to avoid bugs at compilation

// Definition has to be revised

class Action
{
protected:
	Action_t t_;
	std::vector <int> data_;
	
public:
	// Constructors
	
	Action ();
	
	// Accessors
	
	Action_t getT() const;
	int getData(int i, int default_value) const;
	void setT(Action_t t);
	
	// General methods
	
	void addData(int i);
	
};