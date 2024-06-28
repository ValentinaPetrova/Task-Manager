#include "Collaboration.h"


MyString Collaboration::getName() const
{
	return name;
}

MyString Collaboration::getCreatorName() const
{
	return creator.getUsername();
}

void Collaboration::serialize(std::ofstream& file) const {
    size_t workGroupCount = workGroup.getSize();
    file.write(reinterpret_cast<const char*>(&workGroupCount), sizeof(workGroupCount));
    for (int i = 0; i < workGroupCount;i++) {
        workGroup[i].serialize(file);
    }

    size_t tasksCount = tasks.getSize();
    file.write(reinterpret_cast<const char*>(&tasksCount), sizeof(tasksCount));
    for (int i = 0; i < tasksCount; i++) {
        tasks[i].serialize(file);
    }
    size_t nameLength = name.getSize();
    file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    file.write(name.c_str(), nameLength);

    file.write(reinterpret_cast<const char*>(&id), sizeof(id));

    creator.serialize(file);
}

void Collaboration::deserialize(std::ifstream& file) {
    size_t workGroupCount;
    file.read(reinterpret_cast<char*>(&workGroupCount), sizeof(workGroupCount));
    workGroup.clear();
    for (size_t i = 0; i < workGroupCount; ++i) {
        User user;
        user.deserialize(file);
        workGroup.pushBack(user);
    }

    size_t tasksCount;
    file.read(reinterpret_cast<char*>(&tasksCount), sizeof(tasksCount));
    tasks.clear();
    for (size_t i = 0; i < tasksCount; ++i) {
        CollaborationTask task;
        task.setType(taskType::CollaboartionTask);
        taskType type;
        file.read(reinterpret_cast<char*>(&type), sizeof(type));
        task.deserialize(file);
        tasks.pushBack(task);
    }

    size_t nameLength = 0;
    file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    char* nameBuffer = new char[nameLength + 1];
    file.read(nameBuffer, nameLength);
    nameBuffer[nameLength] = '\0';
    name = nameBuffer;
    delete[] nameBuffer;

    file.read(reinterpret_cast<char*>(&id), sizeof(id));

    creator.deserialize(file);
}

//void Collaboration::printCollaboration() const 
//{
//
//}

//void Collaboration::addUser(UserFunctionalities& user)
//{
//	workGroup.pushBack(user);
//	for (size_t i = 0; i < tasks.getSize(); i++)
//	{
//		user.addTask(tasks[i].name, tasks[i].dueDate, tasks[i].description);
//	}
//	
//}