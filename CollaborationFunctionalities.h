#pragma once
#include "MyVector.hpp"
#include "Collaboration.h"

class CollaborationFunctionalities : public Collaboration
{
public:
	CollaborationFunctionalities() {}
	CollaborationFunctionalities(const MyString& name, const User& user): Collaboration(name,user)
	{}
	void addTask(const UserFunctionalities& user,const MyString& name, const MyString& due_date, const MyString& description);
	bool existingTask(const MyString& name, const MyString& due_date, const MyString& description) const;
	void addUser(UserFunctionalities& user);
	void assignTask(UserFunctionalities& user, const MyString& taskName, const MyString& dueDate, const MyString& description);
	void listTasks() const;

private:
	/*Vector<Collaboration> collaborations;*/
};

