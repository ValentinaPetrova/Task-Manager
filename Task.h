#pragma once
#include "MyString.h"
#include <ctime>
#include <iomanip>
#include <sstream>

enum Status
{
	ON_HOLD,
	IN_PROGRESS,
	DONE,
	OVERDUE
};

enum class taskType
{
	CollaboartionTask,
	PersonalTask
};

class Task
{
public:
	/*
	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();*/
	Task();
	void setName(const MyString& name);
	void setStatus(const Status& status);
	void setDescription(const MyString& description);
	void setDueDate(const MyString& dateStr);
	void setId();
	void setType(const taskType tasktype);
	
	virtual taskType returnType() const = 0;
	int getId() const;
	MyString getName() const;
	MyString getDate() const;
	MyString getDateForCompare() const;
	MyString getDescription() const;
	Status getStatus() const;
	MyString getStatusForPrint() const;
	virtual void serialize(std::ofstream& file) const;
	virtual void deserialize(std::ifstream& file);
	virtual void printTask() const;
	virtual void setAssignee(const MyString& name) = 0;

	virtual Task* clone()  const = 0;
	virtual ~Task() = default;
	friend class CollaborationTask;

private:
	int id;
	MyString name = nullptr;
	Status status = ON_HOLD;
	tm dueDate;
	MyString description;
	taskType type;
};