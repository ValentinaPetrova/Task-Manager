#include "PersonalTask.h"

Task* PersonalTask::clone() const
{
	Task* newObj = new  (std::nothrow)PersonalTask(*this); 
	return newObj;
}

taskType PersonalTask::returnType() const
{
	return taskType::PersonalTask;
}

//void PersonalTask::printTask() const
//{
//    std::cout << "Task name: " << getName() << std::endl;
//    std::cout << "Task ID: " << getId() << std::endl;
//    std::cout << "Due date: " << getDate() << std::endl;
//    std::cout << "Task desc: " << getDescription() << std::endl;
//    std::cout << "Status: " << getStatusForPrint() << std::endl;
//}