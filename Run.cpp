#pragma once
#include "TaskManager.h"
#include "UserFunctionalities.h"
#include <iostream>
#include <regex>


bool logged(int userIndex)
{
	if (userIndex == -1)
	{
		std::cout << "Unvalid username or password!" << std::endl;
		return false;
	}
	return true;
}

void assignTask(TaskManager& taskManager)
{
	MyString collaborationName;
	MyString username;
	MyString taskName;
	MyString dueDate;
	MyString description;
	std::cin >> collaborationName >> username >> taskName >> dueDate;
	char buff[1024];
	std::cin.getline(buff, 1024);
	description =  buff;
	taskManager.assignTaskToCollaboration(collaborationName, username, taskName, dueDate, description);
}

void addUser(TaskManager& taskManager, size_t userIndex)
{
	MyString collaborationName;
	MyString username;
	std::cin >> collaborationName >> username;
	taskManager.addUserInCollaboration(collaborationName, username);
	
}

void listCollaborations(TaskManager& taskManager, size_t userIndex)
{
	taskManager.listCollaborations();
}

void deleteCollaboration(TaskManager& taskManager, size_t userIndex)
{
	MyString collaborationName;
	std::cin >> collaborationName;
	taskManager.deleteCollaboration(userIndex, collaborationName);
}

void addCollaboration(TaskManager& taskManager, size_t userIndex)
{
	MyString collaborationName;
	std::cin >> collaborationName;
	taskManager.addCollaboration(userIndex, collaborationName);
}

void finishTask(TaskManager& taskManager, size_t userIndex)
{
	int id;
	std::cin >> id;
	taskManager.finishTask(userIndex, id);
	std::cout << "Task finished successfully!" << std::endl;
}

void listDashboard(TaskManager& taskManager, size_t userIndex)
{
	taskManager.listDashboard(userIndex);
}

void listComplitedTasks(TaskManager& taskManager, size_t userIndex)
{
	taskManager.listCompletedTasks(userIndex);
}

void listTasks(TaskManager& taskManager, size_t userIndex)
{
	MyString input;
	char buff[1024];
	std::cin.getline(buff,1024);
	input = buff;
	if (input.getSize() == 0)
	{
		taskManager.listTasks(userIndex);
	}
	else
	{
		input.removeFirstChar();
		taskManager.listTasks(userIndex, input);
	}
}

void deleteTask(TaskManager& taskManager, size_t userIndex)
{
	int id;
	std::cin >> id;
	taskManager.deleteTask(userIndex, id);
	std::cout << "Task was successfully deleted!" << std::endl;
}

void addTaskToDashboard(TaskManager& taskManager, size_t userIndex)
{
	int id;
	std::cin >> id;
	taskManager.addTaskToDashboard(userIndex, id);
	std::cout << "Task was successfully added to dashboard!" << std::endl;
}
void removeTaskFromDashboard(TaskManager& taskManager, size_t userIndex)
{
	int id;
	std::cin >> id;
	taskManager.removeTaskFromDashboard(userIndex, id);
	std::cout << "Task was successfully removed from dashboard!" << std::endl;
}
void updateTaskDescription(TaskManager& taskManager, size_t userIndex)
{
	MyString taskDescription;
	int id;
	std::cin >> id >> taskDescription;
	taskManager.updateTaskDescription(userIndex, id, taskDescription);
	std::cout << "Task description updated successfully!" << std::endl;
}

void startTask(TaskManager& taskManager, size_t userIndex)
{
	int id;
	std::cin >> id;
	taskManager.startTask(userIndex, id);
}

void updateTaskName(TaskManager& taskManager, size_t userIndex)
{
	MyString taskName;
	int id;
	std::cin >> id >> taskName;
	taskManager.updateTaskName(userIndex, id, taskName);
}

bool isNumber(const MyString& str) {
	std::regex numberPattern("^-?\\d*\\.?\\d+(e[-+]?\\d+)?$");
	return std::regex_match(str.c_str(), numberPattern);
}

void getTask(TaskManager& taskManager, size_t userIndex)
{
	MyString taskName;
	std::cin >> taskName;
	if (isNumber(taskName))
	{
		std::istringstream iss(taskName.c_str());
		int num;
		iss >> num;
		taskManager.getTask(userIndex, num);
	}
	else
	{
		taskManager.getTask(userIndex, taskName);
	}
}

void addTask(TaskManager& taskManager, size_t userIndex)
{
	MyString name, dueDate, description;
	std::cin >> name >> dueDate;

	char buff[1024];
	std::cin.getline(buff, 1024);
	description = buff;
	taskManager.addTask(userIndex, name, dueDate, description);
	
}

void regist(TaskManager& taskManager)
{
	MyString username;
	MyString password;
	std::cin >> username >> password;
	taskManager.regist(username, password);
}

size_t logIn(TaskManager& taskManager)
{
	MyString username;
	MyString password;
	std::cin >> username >> password;
	int userIndex = taskManager.login(username, password);
	if (userIndex != -1)
	{
		std::cout << "Welcome back, " << username << "!" << std::endl;
		return userIndex;
	}
	else
	{
		std::cout << "Unvalid username or password!" << std::endl;
	}
	
}


