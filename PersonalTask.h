#pragma once
#include "Task.h"

class PersonalTask : public Task
{
public:
	//void printTask() const override;
	taskType returnType() const override;
	Task* clone() const override;
};

