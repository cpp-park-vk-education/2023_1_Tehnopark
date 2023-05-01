#include "gmock/gmock.h"
#include "User.hpp"
#include "Task.hpp"
#include "TaskRepo.hpp"

using namespace testing;

//EditTask tests

TEST(TaskRepoTest, EditTaskCorrect)
{
    TaskRepo taskRepo;
    Task task = Task(1, 1, "Wash dishes");

    auto res = taskRepo.EditTask(task);

    EXPECT_TRUE(res);
}

TEST(TaskRepoTest, EditTaskNoTaskWithsuchId)
{
    TaskRepo taskRepo;
    Task task = Task(100, 1, "Wash dishes");

    EXPECT_ANY_THROW(taskRepo.EditTask(task));
}

TEST(TaskRepoTest, EditTaskNoBoardWithsuchId)
{
    TaskRepo taskRepo;
    Task task = Task(1, 100, "Wash dishes");

    EXPECT_ANY_THROW(taskRepo.EditTask(task));
}

TEST(TaskRepoTest, EditTaskNoTaskName)
{
    TaskRepo taskRepo;
    Task task = Task(1, 1, "");

    EXPECT_ANY_THROW(taskRepo.EditTask(task));
}

//CreateTask Tests

TEST(TaskRepoTest, CreateTaskCorrect)
{
    TaskRepo taskRepo;
    User user = User(1,"Kolya");

    auto res = taskRepo.CreateTask("Wash dishes", user, "everyday task");

    EXPECT_TRUE(res);
}

TEST(TaskRepoTest, CreateTaskNoTaskName)
{
    TaskRepo taskRepo;
    User user = User(1,"Kolya");

    EXPECT_ANY_THROW(taskRepo.CreateTask("", user, "everyday task"));
}

TEST(TaskRepoTest, CreateTaskNoUser)
{
    TaskRepo taskRepo;
    User user;

    EXPECT_ANY_THROW(taskRepo.CreateTask("Wash dishes", user, "everyday task"));
}

TEST(TaskRepoTest, CreateTaskNoTaskDescription)
{
    TaskRepo taskRepo;
    User user = User(1,"Kolya");

    auto res = taskRepo.CreateTask("Wash dishes", user, "");

    EXPECT_TRUE(res);
}


//GetAllTasksForBoard tests

TEST(TaskRepoTest, GetAllTasksForBoardCorrect)
{
    TaskRepo taskRepo;
    int id = 1;
    std::vector<Task> expected = {Task(1,1, "Wash dishes"), Task(2,1, "Wash dog")}

    auto res = taskRepo.GetAllTasksForBoard(id);

    EXPECT_EQ(expected, res);
}

TEST(TaskRepoTest, GetAllTasksForBoardNoBoardWithSuchId)
{
    TaskRepo taskRepo;
    int id = 100;

    EXPECT_ANY_THROW(taskRepo.GetAllTasksForBoard(id));
}

TEST(TaskRepoTest, GetAllTasksForBoardWithNotasks)
{
    TaskRepo taskRepo;
    int id = 2;
    std::vector<Task> expected = {}

    auto res = taskRepo.GetAllTasksForBoard(id);

    EXPECT_EQ(expected, res);
}

//ChangeTaskStatus tests

TEST(TaskRepoTest, ChangeTaskStatusCorrect)
{
    TaskRepo taskRepo;
    int id = 1;
    TaskStatus newTaskStat = TaskStatus.Open;

    auto res = taskRepo.ChangeTaskStatus(newTaskStat, id);

    EXPECT_TRUE(res);
}

TEST(TaskRepoTest, ChangeTaskStatusNoTaskWithSuchId)
{
    TaskRepo taskRepo;
    int id = 100;
    TaskStatus newTaskStat = TaskStatus.Open;

    EXPECT_ANY_THROW(taskRepo.ChangeTaskStatus(newTaskStat, id));
}

//DeleteTask tests

TEST(TaskRepoTest, DeleteTaskCorrect)
{
    TaskRepo taskRepo;
    int id = 1;

    auto res = taskRepo.DeleteTask(id);

    EXPECT_TRUE(res);
}

TEST(TaskRepoTest, DeleteTaskNoTaskWithSuchId)
{
    TaskRepo taskRepo;
    int id = 100;

    EXPECT_ANY_THROW(taskRepo.DeleteTask(id));
}