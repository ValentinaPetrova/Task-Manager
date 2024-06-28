#include "CollaborationFunctionalities.h"
#include "UserFunctionalities.h"
#include "taskFactory.h"

void CollaborationFunctionalities::addUser(UserFunctionalities& user)
{
	workGroup.pushBack(user);
	for (size_t i = 0; i < tasks.getSize(); i++)
	{
		user.addCollaborationTask(tasks[i].getName(), tasks[i].getDate(), tasks[i].getDescription());
	}
}

void CollaborationFunctionalities::addTask(const UserFunctionalities& user,const MyString& name, const MyString& due_date, const MyString& description)
{
	int tasksCount = tasks.getSize();
	bool exist = existingTask(name, due_date, description);
	if (!exist)
	{
		CollaborationTask collaboration;
		tasks.pushBack(collaboration);
		tasks[tasksCount].setType(taskType::CollaboartionTask);
		tasks[tasksCount].setName(name);
		tasks[tasksCount].setDueDate(due_date);
		tasks[tasksCount].setDescription(description);
		tasks[tasksCount].setAssignee(user);
	}
}

bool CollaborationFunctionalities::existingTask(const MyString& name, const MyString& due_date, const MyString& description) const
{
	for (int i = 0; i < tasks.getSize(); i++)
	{
		if (tasks[i].getName() == name && tasks[i].getDate() == due_date && tasks[i].getDescription() == description)
		{
			std::cout << "Such a task already exists." << std::endl;
			return true;
		}
	}
	return false;
}

void CollaborationFunctionalities::assignTask(UserFunctionalities& user,
	const MyString& taskName, const MyString& dueDate, const MyString& description)
{
	addTask(user,taskName, dueDate, description);
	user.addCollaborationTask(taskName, dueDate, description);
}
void CollaborationFunctionalities::listTasks() const
{
	for (size_t i = 0; i < tasks.getSize(); i++)
	{
		tasks[i].printTask();
	}

}