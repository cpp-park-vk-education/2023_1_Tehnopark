#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <string>
#include "BoardHandlerInterface.hpp"
#include "TaskRepoInterface.hpp"
#include "BoardRepoInterface.hpp"
#include "BoardController.hpp"

class MockTaskRepo : public TaskRepoInterface
{
public:
    MOCK_METHOD(bool, EditTask, (const Task& newTask), (override));
    MOCK_METHOD(std::vector<Task>, GetAllTasksForBoard, (int boardId), (override));
    MOCK_METHOD(bool, ChangeTaskStatus, (TaskStatus status, int taskId), (override));
    MOCK_METHOD(bool, CreateTask, (const Task& newTask), (override));
    MOCK_METHOD(bool, DeleteTask, (int taskId), (override));
};

TEST(BoardHandlerTest, AddTaskTest)
{
    auto mockTaskRepo = std::make_unique<MockTaskRepo>();
    auto mockTaskRepoAdr = mockTaskRepo.get();
    Task task(1, 1, "newTask", "lorem ipsum");
    BoardController boardController(std::move(mockTaskRepo));
    EXPECT_CALL(*mockTaskRepoAdr, CreateTask(task))
                .Times(1);
    boardController.AddTask(1, 1, "newTask", "lorem ipsum");
}

TEST(BoardHandlerTest, ChangeTaskStatusTest)
{
    auto mockTaskRepo = std::make_unique<MockTaskRepo>();
    auto mockTaskRepoAdr = mockTaskRepo.get();
    BoardController boardController(std::move(mockTaskRepo));
    EXPECT_CALL(*mockTaskRepoAdr, ChangeTaskStatus(TaskStatus::Open, 1))
                .Times(1);
    boardController.ChangeTaskStatus(1, TaskStatus::Open);
}

TEST(BoardHandlerTest, DeleteTaskTest)
{
    auto mockTaskRepo = std::make_unique<MockTaskRepo>();
    auto mockTaskRepoAdr = mockTaskRepo.get();
    BoardController boardController(std::move(mockTaskRepo));
    EXPECT_CALL(*mockTaskRepoAdr, DeleteTask(1))
                .Times(1);
    boardController.DeleteTask(1);
}

TEST(BoardHandlerTest, GetAllTasksForBoardTest)
{
    auto mockTaskRepo = std::make_unique<MockTaskRepo>();
    auto mockTaskRepoAdr = mockTaskRepo.get();
    BoardController boardController(std::move(mockTaskRepo));
    EXPECT_CALL(*mockTaskRepoAdr, GetAllTasksForBoard(3))
                .Times(1);
    boardController.GetAllTasksForBoard(3);
}