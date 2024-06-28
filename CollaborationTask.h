#pragma once
#include "Task.h"
#include "User.h"
//#include "User.h"

class CollaborationTask : public Task
{
public:
	Task* clone() const override;
	void setAssignee(const MyString& user) override;
	taskType returnType() const override;
	void printTask() const override;
	void serialize(std::ofstream& file) const override;
	void deserialize(std::ifstream& file) override;
private:
	MyString assignee;
};

