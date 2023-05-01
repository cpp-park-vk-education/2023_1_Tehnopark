#include "gmock/gmock.h"
#include "User.hpp"
#include "Task.hpp"
#include "TaskRepo.hpp"

using namespace testing;

TEST(TaskRepoTest, EditTaskCorrect)
{
    TaskRepo taskContr;
    Task task = Task(1, 1, "Wash dishes");

    auto res = taskContr.EditTask(task);

    EXPECT_TRUE(res);
}

TEST(TaskRepoTest, CreateTaskCorrect)
{
    TaskRepo taskContr;
    Task task = Task(1, 1, "Wash dishes");

    auto res = taskContr.CreateTask(task);

    EXPECT_TRUE(res);
}

TEST(TaskRepoTest, GetAllTasksForBoardCorrect)
{
    TaskRepo taskContr;
    int id = 1;
    std::vector<Task> expected = {Task(1,1, "Wash dishes"), Task(2,1, "Wash dog")}

    auto res = taskContr.GetAllTasksForBoard(id);

    EXPECT_EQ(expected, res);
}

TEST(TaskRepoTest, ChangeTaskStatusCorrect)
{
    TaskRepo taskContr;
    int id = 1;
    TaskStatus newTaskStat = TaskStatus.Open;

    auto res = taskContr.ChangeTaskStatus(newTaskStat, id);

    EXPECT_TRUE(res);
}

TEST(TaskRepoTest, DeleteTaskCorrect)
{
    TaskRepo taskContr;
    int id = 1;

    auto res = taskContr.DeleteTask(id);

    EXPECT_TRUE(res);
}