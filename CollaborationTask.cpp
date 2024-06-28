#include "CollaborationTask.h"
#include <fstream>

Task* CollaborationTask::clone() const
{
	Task* newObj = new  (std::nothrow)CollaborationTask(*this);
	return newObj;
}

void CollaborationTask::setAssignee(const User& user)
{
	assignee = user;
}

taskType CollaborationTask::returnType() const
{
	return taskType::CollaboartionTask;
}

void CollaborationTask::printTask() const
{
    std::cout << "Task name: " << getName() << std::endl;
    std::cout << "Task ID: " << getId() << std::endl;
    std::cout << "Due date: " << getDate() << std::endl;
    std::cout << "Task desc: " << getDescription() << std::endl;
    std::cout << "Status: " << getStatusForPrint() << std::endl;
    std::cout << "Asignee: " << assignee.getUsername() << std::endl;
}

//void CollaborationTask::serialize(std::ofstream& file) const
//{
//    int typeId = (type == taskType::CollaboartionTask) ? 0 : 1;
//
//    file.write(reinterpret_cast<const char*>(&typeId), sizeof(typeId));
//    file.write(reinterpret_cast<const char*>(&id), sizeof(id));
//
//    size_t nameLength = name.getSize();
//    file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
//    file.write(name.c_str(), nameLength);
//
//    file.write(reinterpret_cast<const char*>(&status), sizeof(status));
//
//    size_t descriptionLength = description.getSize();
//    file.write(reinterpret_cast<const char*>(&descriptionLength), sizeof(descriptionLength));
//    file.write(description.c_str(), descriptionLength);
//
//    file.write(reinterpret_cast<const char*>(&dueDate), sizeof(dueDate));
//
//    /*MyString assigneeName = assignee.getUsername();
//    size_t assigneeNameLength = assigneeName.getSize();
//    file.write(reinterpret_cast<const char*>(&assigneeNameLength), sizeof(assigneeNameLength));
//    file.write(assigneeName.c_str(), assigneeNameLength);*/
//    assignee.serialize(file);
//}

//void CollaborationTask::deserialize(std::ifstream& file)
//{
//    /*file.read(reinterpret_cast<char*>(&type), sizeof(type));*/
//    file.read(reinterpret_cast<char*>(&id), sizeof(id));
//
//    size_t nameLength = 0;
//    file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
//    char* nameBuffer = new char[nameLength + 1];
//    file.read(nameBuffer, nameLength);
//    nameBuffer[nameLength] = '\0';
//    name = nameBuffer;
//    delete[] nameBuffer;
//
//    file.read(reinterpret_cast<char*>(&status), sizeof(status));
//
//    size_t descriptionLength = 0;
//    file.read(reinterpret_cast<char*>(&descriptionLength), sizeof(descriptionLength));
//    char* descriptionBuffer = new char[descriptionLength + 1];
//    file.read(descriptionBuffer, descriptionLength);
//    descriptionBuffer[descriptionLength] = '\0';
//    description = descriptionBuffer;
//    delete[] descriptionBuffer;
//
//    file.read(reinterpret_cast<char*>(&dueDate), sizeof(dueDate));
//
//    /*size_t assigneeNameLength = 0;
//    file.read(reinterpret_cast<char*>(&assigneeNameLength), sizeof(assigneeNameLength));
//    char* nameBuffer = new char[assigneeNameLength + 1];
//    file.read(nameBuffer, assigneeNameLength);
//    nameBuffer[assigneeNameLength] = '\0';
//    MyString assigneeName = nameBuffer;
//    UserFunctionalities user(assigneeName);
//    delete[] nameBuffer;*/
//    //User newAssignee;
//    //newAssignee.deserialize(file);
//    //assignee = newAssignee;
//
//    assignee.deserialize(file);
//}
