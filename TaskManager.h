#pragma once
#include "MyVector.hpp"
#include "UserFunctionalities.h"
#include "CollaborationFunctionalities.h"

class TaskManager
{
public:
	TaskManager();
	void regist(const MyString& username, const MyString& password);
	int login(const MyString& username, const MyString& password);
	int findUserIndex(const MyString& username) const;

	void saveToFile() const;
	void readFromFile();

	void addTask(size_t userIndex, const MyString& name, const MyString& due_date, const MyString& description);
	void updateTaskName(size_t userIndex, const int id, const MyString& name);
	void startTask(size_t userIndex, const int id);
	void updateTaskDescription(size_t userIndex, const int id, const MyString& description);
	void removeTaskFromDashboard(size_t userIndex, const int id);
	void addTaskToDashboard(size_t userIndex, const int id);
	void deleteTask(size_t userIndex, const int id);
	void getTask(size_t userIndex, const MyString& name) const;
	void getTask(size_t userIndex, const int id) const;
	void listTasks(size_t userIndex, const MyString& date) const;
	void listTasks(size_t userIndex) const;
	void listCompletedTasks(size_t userIndex) const;
	void listDashboard(size_t userIndex) const;
	void finishTask(size_t userIndex, const int id);
	
	void addCollaboration(size_t userIndex, const MyString& name);
	void deleteCollaboration(size_t userIndex, const MyString& collaborationName);
	int findCollaborationIndex(const MyString& collaborationName) const;
	void listCollaborations() const;
	void assignTaskToCollaboration(const MyString& collaborationName, const MyString& username,
		const MyString& taskName, const MyString& dueDate, const MyString& description);
	void listCollaborationTasks(const MyString& collaborationName) const;
	void addUserInCollaboration(const MyString& collaborationName, const MyString& username);

	~TaskManager();

private:
	Vector<UserFunctionalities> users;
	Vector<CollaborationFunctionalities> collaborations;
};

