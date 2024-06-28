# Task-Manager
Course project OOP Sem2 SI
To develop a task management software system that allows users to create, edit, view and execute various types of tasks. The system will provide the ability to register and log in users, manage personal and shared tasks, as well as track and change the status of tasks.

1. Task
A task consists of the following attributes:
● id - unique task number;
● name - name of the task;
● due_date (optional) - date by which we must complete the task;
● status - it can be ON_HOLD, IN_PROCESS, DONE, OVERDUE;
● description - description of the task;

*Note: For a specific due_date, we cannot have more than one task with the same name.
*Note: For the project it is allowed to use the library <ctime> for working with time and <iomanip> for parsing from string to date.

2. User
The user of this task management system can be any person or group of people who need an efficient way to organize and manage their tasks. The user can use the system to create, edit and track different types of tasks. They can be personal tasks or part of shared projects that involve collaboration with other users.
Each user of the system is characterized by the following attributes:
● username;
● password;

3. Dashboard
The Dashboard is a board with the tasks we want to complete during the current day (not necessarily due on this particular day). In it, the user will be able to add and remove tasks to be completed. If a given task has a deadline until the specific day on which the user logged in, and it is not completed, it should be automatically added to the user's dashboard when logging in. If a specific task has expired, it should be automatically removed from the user's dashboard when logging in.

4. User Functionalities
● register <username> <password> - user registration with username and password. Registered users are kept in a binary file - it serves as a database. When stopping and restarting, the system should be able to load the already registered users into its memory;
● login <username> <password> - the user enters the system;
● add-task <name> <due_date> <description> - adding a new task. If the task already exists, display an appropriate error message. All tasks are added with ON_HOLD status by default.
● update-task-name <id> <name> - change the name of a task.
● start-task <id> - marks the specific task as started.
● update-task-description <id> <description> - change the description of a task.
● remove-task-from-dashboard <id> - removes the task from the dashboard.
● add-task-to-dashboard <id> - adds the task to the dashboard only if it is NOT in OVERDUE status. Adding a task does not change its due date.
● delete-task <id> - delete a task.
● get-task <name> - provides the information about a given task in human-readable format. For multiple tasks with the same name, the command should be executed on the one with the lowest id.
● get-task <id> - provides the information about a given task in human-readable format.
● list-tasks <date> - provides the information about all tasks of a given user with a deadline of a specific day.
● list-tasks - provides the information about all tasks of a given user.
● list-completed-tasks - provides the information about all tasks of a given user that have been completed.
● list-dashboard - provides the information about all tasks for today.
● finish-task <id> - marks the specific task as finished.
● logout - leaves the user profile.
● exit - stops the program.

*Note: If a given task does not exist when executing any of the commands, display an appropriate error message.

5. Collaborations
A collaboration is a shared project in which tasks can be added that are visible to all participants. The tasks in the collaboration have one more attribute - assignee, i.e. the user who will work on the task. A collaboration is characterized by:
● name - name of the collaboration;
● id - unique collaboration number;
● creator - the user who created the collaboration;
● working group - users who work on the tasks in the collaboration;

6. Functionalities for collaboration:
● add-collaboration <name> - adds a new collaboration.
● delete-collaboration <name> - deletes a collaboration. A collaboration can only be deleted by the user who created it. Deleting the collaboration should also automatically delete all the tasks that are part of it, as well as remove them from the participant lists.
● list-collaborations - provides information on all collaborations of the respective user. This includes ones he created and ones he added to.
● add-user <collaboration name> <username> - adds a user to the collaboration.
● assign-task <collaboration name> <username> <name> <due_date> <description> - sets the assignee for a given task in the collaboration.
● list-tasks <collaboration name> - provides the information about all tasks from the collaboration.
