#include "Task.h"
#include <fstream>
#include <random>


Task::Task() : status(ON_HOLD), dueDate{}, name(), description() 
{
    setId();
}

void Task::printTask() const
{
    std::cout << "Task name: " << name << std::endl;
    std::cout << "Task ID: " << id << std::endl;
    std::cout << "Due date: " << getDate() << std::endl;
    std::cout << "Task desc: " << description << std::endl;
    std::cout << "Status: " << getStatusForPrint() << std::endl;
}

void Task::serialize(std::ofstream& file) const
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
    
}

void Task::deserialize(std::ifstream& file)
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
}

void Task::setName(const MyString& name)
{
	this->name = name;
}
void Task::setStatus(const Status& status)
{
	this->status = status;
}
void Task::setDescription(const MyString& description)
{
	this->description = description;
}

void Task::setDueDate(const MyString& dateStr) 
{
    std::istringstream ss(dateStr.c_str());
    ss >> std::get_time(&dueDate, "%Y-%m-%d");
    if (ss.fail()) {
        throw std::invalid_argument("Invalid date format");
    }
}

void Task::setId()
{
    unsigned seed = std::time(0);
    std::mt19937 gen(seed);

    // Define the distribution range (e.g., between 1 and 100)
    std::uniform_int_distribution<> dis(1, 100);

    id = dis(gen);
}

void Task::setType(const taskType taskType)
{
    type = taskType;
}

int Task::getId() const
{
    return id;
}

MyString Task::getName() const
{
    return name;
}

MyString Task::getDate() const
{
    std::ostringstream ss;
    ss << std::put_time(&dueDate, "%Y-%m-%d %H:%M:%S");
    MyString toReturn = ss.str().c_str();
    return toReturn;

    /*char buffer[20];
    if (std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &dueDate)) {
        return MyString(buffer);
    }
    else {
        return MyString("Invalid date");
    }*/
}
MyString Task::getDescription() const
{
    return description;
}
Status Task::getStatus() const
{
    return status;
}

MyString Task::getStatusForPrint() const 
{
    switch (status)
    {
    case ON_HOLD:
        return "ON_HOLD";
        break;
    case IN_PROGRESS:
        return "IN_PROGRESS";
        break;
    case DONE:
        return "DONE";
        break;
    case OVERDUE:
        return "OVERDUE";
        break;
    default:
        return "Undefined";
        break;
    }
}