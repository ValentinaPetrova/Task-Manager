#pragma once
#include "User.h"
//#include "Task.h"
//#include "MyString.h"
//#include "MyVector.hpp"
#include <fstream>

class UserFunctionalities : public User
{
public:
	UserFunctionalities() {};
	UserFunctionalities(const MyString& username) :  User(username) {};
	UserFunctionalities(const MyString& username, const MyString& password) : User(username, password)
	{ }	
	int findTaskIndex(const int id) const;
	int findTaskIndex(const MyString& name) const;

	void addTask(const MyString& name, const MyString& due_date, const MyString& description);
	void addCollaborationTask(const MyString& name, const MyString& due_date, const MyString& description);
	void addAssignedCollaborationTask(const MyString& assignee, const MyString& name, const MyString& due_date, const MyString& description);
	void updateTaskName(const int id, const MyString& name);
	void startTask(const int id);
	void updateTaskDescription(const int id, const MyString& description);
	void removeTaskFromDashboard(const int id);
	void addTaskToDashboard(const int id);
	bool existingTask(const MyString& name, const MyString& due_date, const MyString& description) const;

	void deleteTask(const int id);
	void getTask(const MyString& name) const;
	void getTask(const int id) const;
	void listTask(const MyString& date) const;
	void listTask() const;
	void listCompletedTasks() const;
	void listDashboard() const;
	void finishTask(const int id);

private:
	
};

