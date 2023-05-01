#include "gmock/gmock.h"
#include "User.hpp"
#include "Task.hpp"
#include "TaskRepoInterface.hpp"
#include "TaskHandlerInterface.hpp"


using namespace testing;

class MockTaskHandler : public ITaskRepo
{
public:
    MOCK_METHOD(bool, EditTask, (Task newTask), (override));
    MOCK_METHOD(bool, CreateTask, (std::string name, User user, std::string description), (override));
};


TEST(TaskHandlerTest, EditTaskCorrect)
{
    MockTaskHandler mockTaskHandler;
    ITaskHandler taskContr;
    Task task = Task(1, 1, "Wash dishes");

    EXPECT_CALL(mockTaskHandler, EditTask(task))
        .Times(1);

    taskContr.EditTask(task);
}

TEST(TaskHandlerTest, EditTaskNoTaskWithSuchId)
{
    MockTaskHandler mockTaskHandler;
    ITaskHandler taskContr;
    Task task = Task(100, 1, "Wash dishes");

    EXPECT_CALL(mockTaskHandler, EditTask(task))
        .Times(1);

    taskContr.EditTask(task);
}




TEST(TaskHandlerTest, CreateTaskCorrect)
{
    MockTaskHandler mockTaskHandler;
    ITaskHandler taskContr;
    User user = User(1, "Kolya");

    EXPECT_CALL(mockTaskHandler, CreateTask("task1", user, "description1"))
        .Times(1);

    taskContr.CreateTask("task1", user, "description1");
}
