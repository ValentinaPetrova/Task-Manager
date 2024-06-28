#include "User.h"
#include <fstream>
#include "taskFactory.h"


void User::serialize(std::ofstream& ofs) const
{	
	size_t usernameLength = username.getSize();
	ofs.write(reinterpret_cast<const char*>(&usernameLength), sizeof(usernameLength));
	ofs.write(username.c_str(), usernameLength);

	size_t passwordLength = password.getSize();
	ofs.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
	ofs.write(password.c_str(), passwordLength);

	size_t tasksCount = tasks.getSize();
	ofs.write(reinterpret_cast<const char*>(&tasksCount), sizeof(tasksCount));

	for (size_t i = 0; i < tasksCount; i++)
	{
		tasks[i]->serialize(ofs);
	}
}

void User::deserialize(std::ifstream& ifs)
{
	size_t usernameLength = 0;
	ifs.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
	char* usernameBuffer = new char[usernameLength + 1];
	ifs.read(usernameBuffer, usernameLength);
	usernameBuffer[usernameLength] = '\0';
	username = usernameBuffer;
	delete[] usernameBuffer;

	size_t passwordLength = 0;
	ifs.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
	char* passwordBuffer = new char[passwordLength + 1];
	ifs.read(passwordBuffer, passwordLength);
	passwordBuffer[passwordLength] = '\0';
	password = passwordBuffer;
	delete[] passwordBuffer;

	size_t tasksCount = 0;
	ifs.read(reinterpret_cast<char*>(&tasksCount), sizeof(tasksCount));
	if (tasksCount > 0)
	{
		for (size_t i = 0; i < tasksCount; i++)
		{
			int typeId = 0;
			ifs.read(reinterpret_cast<char*>(&typeId), sizeof(typeId));
			taskType type = (typeId == 0) ? taskType::CollaboartionTask : taskType::PersonalTask;
			tasks.pushBack(taskFactory(type));
			tasks[i]->deserialize(ifs);
		}
	}
	
}

MyString User::getUsername() const
{
	return username;
}

MyString User::getPassword() const
{
	return password;
}
