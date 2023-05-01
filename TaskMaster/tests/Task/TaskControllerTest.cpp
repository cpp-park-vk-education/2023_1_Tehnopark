#include "gmock/gmock.h"
#include "User.hpp"
#include "Task.hpp"
#include "TaskRepoInterface.hpp"
#include "TaskController.hpp"


using namespace testing;

class MockTaskHandler : public TaskRepoInterface
{
public:
    MOCK_METHOD(bool, EditTask, (Task newTask), (override));
    MOCK_METHOD(bool, CreateTask, (std::string name, User user, std::string description), (override));
};


TEST(TaskHandlerTest, EditTaskCorrect)
{
    auto mockTaskHandler = std::make_unique<MockTaskHandler>();
    auto mockTaskHandlerAdr = mockTaskHandler.get();
    TaskController taskContr;
    Task task = Task(1, 1, "Wash dishes");

    EXPECT_CALL(*mockTaskHandlerAdr, EditTask(task))
        .Times(1);

    taskContr.EditTask(task);
}

TEST(TaskHandlerTest, EditTaskNoTaskWithSuchId)
{
    auto mockTaskHandler = std::make_unique<MockTaskHandler>();
    auto mockTaskHandlerAdr = mockTaskHandler.get();
    TaskController taskContr;
    Task task = Task(100, 1, "Wash dishes");

    EXPECT_CALL(*mockTaskHandlerAdr, EditTask(task))
        .Times(1);

    taskContr.EditTask(task);
}


TEST(TaskHandlerTest, CreateTaskCorrect)
{
    auto mockTaskHandler = std::make_unique<MockTaskHandler>();
    auto mockTaskHandlerAdr = mockTaskHandler.get();
    TaskController taskContr;
    User user = User(1, "Kolya");

    EXPECT_CALL(*mockTaskHandlerAdr, CreateTask("task1", user, "description1"))
        .Times(1);

    taskContr.CreateTask("task1", user, "description1");
}
