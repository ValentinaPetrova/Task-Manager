#pragma once
#include "MyString.h"
//#include "Task.h"
#include "dashboard.h"
#include "MyVector.hpp"

class UserFunctionalities;

class User
{
public:
	User() {}
	User(const MyString& username) : username(username) {}
	User(const MyString& username, const MyString& password) : username(username), password(password)
	{}
	void serialize(std::ofstream& file) const;
	void deserialize(std::ifstream& file);
	MyString getUsername() const;
	MyString getPassword() const;
	friend class UserFunctionalities;

private:

	Vector<Task*> tasks;
	size_t tasksCount = 0;
	Dashboard dashboard;
	MyString username;
	MyString password;
};

