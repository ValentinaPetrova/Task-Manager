#include "taskFactory.h"
#include "CollaborationTask.h"
#include "PersonalTask.h"

Task* taskFactory(taskType type)
{
	switch (type)
	{
	case taskType::PersonalTask:
		return new PersonalTask();
	case taskType::CollaboartionTask:
		return new CollaborationTask();
	}
	return nullptr;
}
