#include "TaskManager.h"

TaskManager::TaskManager()
{

	readFromFile();
}

void TaskManager::readFromFile()
{
	std::ifstream ifs("TaskManager.txt", std::ios::binary); 

	if (!ifs) {
		std::cerr << "Error opening file 'TaskManager.txt'" << std::endl;
		return; 
	}

	size_t usersCount = 0;
	ifs.read(reinterpret_cast<char*>(&usersCount), sizeof(usersCount));
	
	if (usersCount > 0)
	{	
		for (size_t i = 0; i < usersCount; i++) {
			UserFunctionalities user;
			users.pushBack(user);
			users[i].deserialize(ifs); 
		}
	}

	size_t collaborationsCount = 0;
	ifs.read(reinterpret_cast<char*>(&collaborationsCount), sizeof(collaborationsCount));
	
	if (collaborationsCount > 0)
	{
		for (size_t i = 0; i < collaborationsCount; i++) {
			CollaborationFunctionalities collaboration;
			collaborations.pushBack(collaboration);
			collaborations[i].deserialize(ifs);
		}
	}

	ifs.close();
}

void TaskManager::saveToFile() const
{
	std::ofstream ofs("TaskManager.txt", std::ios::out | std::ios::binary);
	size_t usersCount = users.getSize();
	ofs.write(reinterpret_cast<const char*>(&usersCount), sizeof(usersCount));

	for (size_t i = 0; i < users.getSize(); i++)
	{
		users[i].serialize(ofs);
	}

	size_t collaborationsCount = collaborations.getSize();
	ofs.write(reinterpret_cast<const char*>(&collaborationsCount), sizeof(collaborationsCount));
	for (size_t i = 0; i < collaborations.getSize(); i++)
	{
		collaborations[i].serialize(ofs);
	}
}

void TaskManager::regist(const MyString& username, const MyString& password)
{
	bool registered = false;
	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i].getUsername() == username) {
			std::cout << "There is already a user with that name. Sign in to your account or enter another name." << std::endl;
			registered = true;
			break;
		}
	}

	if (!registered)
	{
		UserFunctionalities user(username,password);
		users.pushBack(user);
		std::cout << "Registered successfully!" << std::endl;
	}
	
}

int TaskManager::login(const MyString& username, const MyString& password)
{
	if (users.getSize() > 0)
	{
		int userIndex = findUserIndex(username);
		if (userIndex >= 0 && users[userIndex].getPassword() == password)
		{
			return userIndex;
		}
		else
		{
			return -1;
		}
	}
	
	return -1;
}

int TaskManager::findUserIndex(const MyString& username) const
{
	if (users.getSize() == 0)
	{
		return -1;
		std::cout << "No users yet!" << std::endl;
	}

	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i].getUsername() == username)
		{
			return i;
		}
	}
	std::cout << "There isn't user with this name!" << std::endl;
	return -1;
}

void TaskManager::addTask(size_t userIndex, const MyString& name, const MyString& due_date, const MyString& description)
{
	users[userIndex].addTask(name, due_date, description);
}

void TaskManager::getTask(size_t userIndex, const MyString& taskName) const
{
	users[userIndex].getTask(taskName);
}

void TaskManager::getTask(size_t userIndex, const int id) const
{
	users[userIndex].getTask(id);
}

void TaskManager::updateTaskName(size_t userIndex, const int id, const MyString& name)
{
	users[userIndex].updateTaskName(id, name);
}

void TaskManager::startTask(size_t userIndex, const int id)
{
	users[userIndex].startTask(id);
}

void TaskManager::updateTaskDescription(size_t userIndex, const int id, const MyString& description)
{
	users[userIndex].updateTaskDescription(id,description);
}
void TaskManager::removeTaskFromDashboard(size_t userIndex, const int id)
{
	users[userIndex].removeTaskFromDashboard(id);
}
void TaskManager::addTaskToDashboard(size_t userIndex, const int id)
{
	users[userIndex].addTaskToDashboard(id);
}
void TaskManager::deleteTask(size_t userIndex, const int id)
{
	users[userIndex].deleteTask(id);
}

void TaskManager::listTasks(size_t userIndex, const MyString& date) const
{
	bool listed = false;
	for (size_t i = 0; i < collaborations.getSize(); i++)
	{
		if (date == collaborations[i].getName())
		{
			listCollaborationTasks(date);
			listed = true;
			break;
		}
	}
	if (!listed)
	{
		users[userIndex].listTask(date);
	}
}

void TaskManager::listTasks(size_t userIndex) const
{
	users[userIndex].listTask();
}
void TaskManager::listCompletedTasks(size_t userIndex) const
{
	users[userIndex].listCompletedTasks();
}
void TaskManager::listDashboard(size_t userIndex) const
{
	users[userIndex].listDashboard();
}
void TaskManager::finishTask(size_t userIndex, const int id)
{
	users[userIndex].finishTask(id);
}

void TaskManager::addCollaboration(size_t userIndex, const MyString& collaborationName)
{
	CollaborationFunctionalities collaboration(collaborationName, users[userIndex]);
	collaborations.pushBack(collaboration);
}
void TaskManager::deleteCollaboration(size_t userIndex, const MyString& collaborationName)
{
	size_t collaborationIndex = findCollaborationIndex(collaborationName);
	if (collaborationIndex >= 0 && collaborations[collaborationIndex].getCreatorName() == users[userIndex].getUsername())
	{
		collaborations.popAt(collaborationIndex);
		std::cout << "Collaboration deleted successfully!" << std::endl;
	}
	else
	{
		std::cout << "You don't have the permission to delete this collaboration." << std::endl;
	}
}

int TaskManager::findCollaborationIndex(const MyString& collaborationName) const
{
	if (collaborations.getSize() == 0)
	{
		std::cout << "No collaborations yet!" << std::endl;
		return -1;
	}
	for (int i = 0; i < collaborations.getSize(); i++)
	{
		if (collaborations[i].getName() == collaborationName)
		{
			return i;
		}
	}
	std::cout << "There isn't collaboration with this name!" << std::endl;
	return -1;
}

void TaskManager::assignTaskToCollaboration(const MyString& collaborationName, const MyString& username,
	const MyString& taskName, const MyString& dueDate, const MyString& description)
{
	size_t collaborationIndex = findCollaborationIndex(collaborationName);
	size_t userIndex = findUserIndex(username);
	if (userIndex >= 0 && collaborationIndex >= 0)
	{
		collaborations[collaborationIndex].assignTask(users[userIndex], taskName, dueDate, description);
	}
}

void TaskManager::listCollaborations() const
{
	if (collaborations.getSize()== 0)
	{
		std::cout << "No collaborations yet!" << std::endl;
	}
	for (size_t i = 0; i < collaborations.getSize(); i++)
	{
		std::cout << collaborations[i].getName() << std::endl;
	}
}

void TaskManager::listCollaborationTasks(const MyString& collaborationName) const
{
	int collaborationIndex = findCollaborationIndex(collaborationName);
	if (collaborationIndex >= 0)
	{
		collaborations[collaborationIndex].listTasks();
	}
	else
	{
		std::cout << "There isn't such a collaboration." << std::endl;
	}
}

void TaskManager::addUserInCollaboration(const MyString& collaborationName, const MyString& username)
{
	int collaborationIndex = findCollaborationIndex(collaborationName);
	if (collaborationIndex >= 0)
	{
		int userIndex = findUserIndex(username);
		/*if (userIndex <= 0)
		{
			UserFunctionalities user(username);
			users.pushBack(user);
			userIndex = users.getSize() - 1;
		}*/

		if (userIndex >= 0)
		{
			collaborations[collaborationIndex].addUser(users[userIndex]);
			std::cout << "User added successfully to " << collaborationName << "!" << std::endl;
		}
	}
	
}

TaskManager::~TaskManager()
{
	saveToFile();
}