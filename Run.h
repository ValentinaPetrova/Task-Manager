#pragma once
#include "Run.cpp"

void run()
{
	bool running = true;
	MyString command;
	TaskManager taskManager;
	size_t userIndex = 0;
	while (running)
	{
		std::cin >> command;
		if (command == "register")
		{
			regist(taskManager);
		}
		else if (command == "login")
		{
			userIndex = logIn(taskManager);
		}
		else if (command == "add-task")
		{
			if (logged(userIndex))
			{
				addTask(taskManager, userIndex);
			}
		}
		else if (command == "get-task")
		{
			if (logged(userIndex))
			{
				getTask(taskManager, userIndex);
			}
		}
		else if (command == "update-task-name")
		{
			if (logged(userIndex))
			{
				updateTaskName(taskManager, userIndex);
			}
		}
		else if (command == "start-task")
		{
			if (logged(userIndex))
			{
				startTask(taskManager, userIndex);
			}
		}
		else if (command == "update-task-description")
		{
			if (logged(userIndex))
			{
				updateTaskDescription(taskManager, userIndex);
			}
		}
		else if (command == "remove-task-from-dashboard")
		{
			if (logged(userIndex))
			{
				removeTaskFromDashboard(taskManager, userIndex);
			}
		}
		else if (command == "add-task-to-dashboard")
		{
			if (logged(userIndex))
			{
				addTaskToDashboard(taskManager, userIndex);
			}
		}
		else if (command == "delete-task")
		{
			if (logged(userIndex))
			{
				deleteTask(taskManager, userIndex);
			}
		}
		else if (command == "list-tasks")
		{
			if (logged(userIndex))
			{
				listTasks(taskManager, userIndex);
			}
		}
		else if (command == "list-completed-tasks")
		{
			if (logged(userIndex))
			{
				listComplitedTasks(taskManager, userIndex);
			}
		}
		else if (command == "list-dashboard")
		{
			if (logged(userIndex))
			{
				listDashboard(taskManager, userIndex);
			}
		}
		else if (command == "finish-task")
		{
			if (logged(userIndex))
			{
				finishTask(taskManager, userIndex);
			}
		}
		else if (command == "add-collaboration")
		{
			if (logged(userIndex))
			{
				addCollaboration(taskManager, userIndex);
			}
		}
		else if (command == "delete-collaboration")
		{
			if (logged(userIndex))
			{
				deleteCollaboration(taskManager, userIndex);
			}
		}
		else if (command == "list-collaborations")
		{
			if (logged(userIndex))
			{
				listCollaborations(taskManager, userIndex);
			}
		}
		else if (command == "add-user")
		{
			if (logged(userIndex))
			{
				addUser(taskManager, userIndex);
			}
		}
		else if (command == "assign-task")
		{
			if (logged(userIndex))
			{
				assignTask(taskManager);
			}
		}
		else if (command == "logout")
		{
			if (logged(userIndex))
			{
				userIndex = -1;
				std::cout << "Logged out successfully!" << std::endl;
			}
		}
		else if (command == "exit")
		{
			running = false;
			std::cout << "Exited successfully!" << std::endl;
		}
		else
		{
			running = false;
			std::cout << "Invalid command!" << std::endl;
		}
	}
}