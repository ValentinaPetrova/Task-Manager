#include "CollaborationTask.h"
#include <fstream>

Task* CollaborationTask::clone() const
{
	Task* newObj = new  (std::nothrow)CollaborationTask(*this);
	return newObj;
}

void CollaborationTask::setAssignee(const MyString& user)
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
    std::cout << "Asignee: " << assignee << std::endl;
}

void CollaborationTask::serialize(std::ofstream& file) const
{
    int typeId = (type == taskType::CollaboartionTask) ? 0 : 1;

    file.write(reinterpret_cast<const char*>(&typeId), sizeof(typeId));
    file.write(reinterpret_cast<const char*>(&id), sizeof(id));

    size_t nameLength = name.getSize();
    file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    file.write(name.c_str(), nameLength);

    file.write(reinterpret_cast<const char*>(&status), sizeof(status));

    size_t descriptionLength = description.getSize();
    file.write(reinterpret_cast<const char*>(&descriptionLength), sizeof(descriptionLength));
    file.write(description.c_str(), descriptionLength);

    file.write(reinterpret_cast<const char*>(&dueDate), sizeof(dueDate));

    size_t assigneeLength = assignee.getSize();
    file.write(reinterpret_cast<const char*>(&assigneeLength), sizeof(assigneeLength));
    file.write(assignee.c_str(), assigneeLength);
}

void CollaborationTask::deserialize(std::ifstream& file)
{
    /*file.read(reinterpret_cast<char*>(&type), sizeof(type));*/
    file.read(reinterpret_cast<char*>(&id), sizeof(id));

    size_t nameLength = 0;
    file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    char* nameBuffer = new char[nameLength + 1];
    file.read(nameBuffer, nameLength);
    nameBuffer[nameLength] = '\0';
    name = nameBuffer;
    delete[] nameBuffer;

    file.read(reinterpret_cast<char*>(&status), sizeof(status));

    size_t descriptionLength = 0;
    file.read(reinterpret_cast<char*>(&descriptionLength), sizeof(descriptionLength));
    char* descriptionBuffer = new char[descriptionLength + 1];
    file.read(descriptionBuffer, descriptionLength);
    descriptionBuffer[descriptionLength] = '\0';
    description = descriptionBuffer;
    delete[] descriptionBuffer;

    file.read(reinterpret_cast<char*>(&dueDate), sizeof(dueDate));

    size_t assigneeLength = 0;
    file.read(reinterpret_cast<char*>(&assigneeLength), sizeof(assigneeLength));
    
    if (assigneeLength > 0 && assigneeLength < 1024)
    {
        char* assigneeBuffer = new char[assigneeLength + 1];
        file.read(assigneeBuffer, assigneeLength);
        assigneeBuffer[assigneeLength] = '\0';
        assignee = assigneeBuffer;
        delete[] assigneeBuffer;
    }
}
