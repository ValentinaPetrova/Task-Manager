#pragma once
#include "MyVector.hpp"
#include "MyString.h"
#include "UserFunctionalities.h"
#include "CollaborationTask.h"


class Collaboration
{
public:
	Collaboration() {}
	Collaboration(const MyString& name, const User& user) : name(name), creator(user) {}
	MyString getName() const;
	MyString getCreatorName() const;
	friend class CollaborationFunctionalities;
	void serialize(std::ofstream& file) const;
	void deserialize(std::ifstream& file);

 private:
	Vector<User> workGroup;
	Vector<CollaborationTask> tasks;
	MyString name;
	int id = 0;
	User creator;
};

