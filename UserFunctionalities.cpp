#include "UserFunctionalities.h"
#include "PersonalTask.h"
#include "CollaborationTask.h"
#include "MyVector.hpp"
#include "taskFactory.h"

void UserFunctionalities::addTask(const MyString& name, const MyString& due_date, const MyString& description)
{
	bool exist = existingTask(name, due_date, description);
	if (!exist)
	{
		tasks.pushBack(taskFactory(taskType::PersonalTask));
		tasks[tasksCount]->setType(taskType::PersonalTask);
		tasks[tasksCount]->setName(name);
		tasks[tasksCount]->setDueDate(due_date);
		tasks[tasksCount]->setDescription(description);
		tasksCount++;
		std::cout << "Task added successfully!" << std::endl;
	}
}

void UserFunctionalities::addCollaborationTask(const MyString& name, const MyString& due_date, const MyString& description)
{
	tasks.pushBack(taskFactory(taskType::CollaboartionTask));
	tasks[tasksCount]->setName(name);
	tasks[tasksCount]->setDueDate(due_date);
	tasks[tasksCount]->setDescription(description);
	tasksCount++;
}

void UserFunctionalities::addAssignedCollaborationTask(const MyString& assignee, const MyString& name, const MyString& due_date, const MyString& description)
{
	tasks.pushBack(taskFactory(taskType::CollaboartionTask));
	tasks[tasksCount]->setName(name);
	tasks[tasksCount]->setDueDate(due_date);
	tasks[tasksCount]->setDescription(description);
	tasks[tasksCount]->setAssignee(assignee);
	tasksCount++;
}

bool UserFunctionalities::existingTask(const MyString& name, const MyString& due_date, const MyString& description) const
{
	for (int i = 0; i < tasks.getSize(); i++)
	{
		if (tasks[i]->getName() == name && tasks[i]->getDateForCompare() == due_date && tasks[i]->getDescription() == description)
		{
			std::cout << "Such a task already exists." << std::endl;
			return true;
		}
	}
	return false;
}

int UserFunctionalities::findTaskIndex(const int id) const
{
	if (tasks.getSize() == 0)
	{
		std::cout << "You dont't have tasks yet." << std::endl;
		return -1;
	}

	for (int i = 0; i < tasks.getSize(); i++) {
		if (tasks[i]->getId() == id) {
			return i;
		}
	}

	std::cout << "Invalid id!" << std::endl;
	return -1;
}

int UserFunctionalities::findTaskIndex(const MyString& name) const
{
	if (tasks.getSize() == 0)
	{
		std::cout << "You dont't have tasks yet." << std::endl;
		return -1;
	}

	for (int i = 0; i < tasksCount; i++) {
		if (tasks[i]->getName() == name) {
			return i;
		}
	}
}

void UserFunctionalities::updateTaskName(const int id, const MyString& name)
{
	int taskIndex = findTaskIndex(id);
	if (taskIndex >= 0 && tasks[taskIndex]->returnType() == taskType::PersonalTask)
	{
		tasks[taskIndex]->setName(name);
		std::cout << "Task name updated successfully!" << std::endl;
	}
	else {
		std::cout << "You don't have the access to change this task." << std::endl;
	}
}

void UserFunctionalities::startTask(const int id)
{
	int taskIndex = findTaskIndex(id);
	if (tasks[taskIndex]->returnType() == taskType::PersonalTask)
	{
		if (tasks[taskIndex]->getStatus() == Status::DONE)
		{
			std::cout << "This task is done already." << std::endl;
		}
		else
		{
			tasks[taskIndex]->setStatus(Status::IN_PROGRESS);
			std::cout << "Task started successfully!" << std::endl;
		}
		
	}
	else {
		std::cout << "You don't have the access to change this task" << std::endl;
	}
	
}

void UserFunctionalities::updateTaskDescription(const int id, const MyString& description)
{
	int taskIndex = findTaskIndex(id);
	if (tasks[taskIndex]->returnType() == taskType::PersonalTask)
	{
		tasks[taskIndex]->setDescription(description);
	}
	else {
		std::cout << "You don't have the access to change this task" << std::endl;
	}
}

void UserFunctionalities::removeTaskFromDashboard(const int id)
{
	int taskIndex = findTaskIndex(id);
	dashboard.tasks.popAt(taskIndex);
}
void UserFunctionalities::addTaskToDashboard(const int id)
{
	int taskIndex = findTaskIndex(id);
	dashboard.tasks.pushBack(tasks[taskIndex]);
}

void UserFunctionalities::deleteTask(const int id)
{
	int taskIndex = findTaskIndex(id);
	if (taskIndex >= 0 && tasks[taskIndex]->returnType() == taskType::PersonalTask)
	{
		for (int i = taskIndex; i < tasksCount; i++)
		{
			if (tasks.getSize() > 1)
			{
				tasks[i] = tasks[i + 1];
			}
			else
			{
				tasks[i] = nullptr;
			}
		}
		tasksCount--;
	}
	else {
		std::cout << "You don't have the access to change this Task" << std::endl;
	}
}

void UserFunctionalities::getTask(const MyString& name) const
{
	int taskIndex = findTaskIndex(name);
	if (taskIndex >= 0)
	{
		tasks[taskIndex]->printTask();
	}
}

void UserFunctionalities::getTask(const int id) const
{
	int taskIndex = findTaskIndex(id);
	if (taskIndex >= 0)
	{
		tasks[taskIndex]->printTask();
	}
}

void UserFunctionalities::listTask(const MyString& date) const
{
	MyString dateForCompare;
	for (size_t i = 0; i < tasks.getSize(); i++)
	{
		dateForCompare = tasks[i]->getDateForCompare();
		if (dateForCompare == date)
		{
			tasks[i]->printTask();
		}
	}
}
void UserFunctionalities::listTask() const
{
	for (size_t i = 0; i < tasks.getSize(); i++)
	{
		tasks[i]->printTask();
	}
}

void UserFunctionalities::listCompletedTasks() const
{
	for (size_t i = 0; i < tasks.getSize(); i++)
	{
		if (tasks[i]->getStatus() == Status::DONE) {
			tasks[i]->printTask();
		}
	}
}
void UserFunctionalities::listDashboard() const
{
	std::cout << "Dashboard:" << std::endl;
	for (size_t i = 0; i < dashboard.tasks.getSize(); i++)
	{
		dashboard.tasks[i]->printTask();
	}
}

void UserFunctionalities::finishTask(const int id)
{
	int taskIndex = findTaskIndex(id);
	if (tasks[taskIndex]->returnType() == taskType::PersonalTask)
	{
		tasks[taskIndex]->setStatus(Status::DONE);
		std::cout << "Congratulations on completing the task!" << std::endl;
	}
	else 
	{
		std::cout << "You don't have the access to change this task" << std::endl;
	}

}
