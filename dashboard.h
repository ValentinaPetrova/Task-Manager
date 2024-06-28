#pragma once
#include "Task.h"
#include "MyVector.hpp"
//#include "UserFunctionalities.h"

class UserFunctionalities;

class Dashboard
{
public:
	Dashboard() {}
	friend class UserFunctionalities;
private:
	Vector<Task*> tasks;
};

