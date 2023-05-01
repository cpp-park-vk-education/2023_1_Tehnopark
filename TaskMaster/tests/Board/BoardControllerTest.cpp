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
    MOCK_METHOD(bool, EditTask, (Task task), (override));
    MOCK_METHOD(std::vector<Task>, GetAllTasksForBoard, (int boardId), (override));
    MOCK_METHOD(bool, ChangeTaskStatus, (TaskStatus status, int taskId), (override));
    MOCK_METHOD(bool, CreateTask, (std::string name, User user, std::string description), (override));
    MOCK_METHOD(bool, DeleteTask, (int taskId), (override));
};

class MockBoardRepo : public BoardRepoInterface
{
public:
    MOCK_METHOD(std::vector<Board>, GetAllTasksForCompany, (int companyId), (override));
    MOCK_METHOD(bool, CreateBoard, (int projectId, std::string name), (override));
    MOCK_METHOD(bool, DeleteBoard, (int boardId), (override));
};

TEST(BoardHandlerTest, AddTaskTest)
{
    auto mockBoardRepo = std::make_unique<MockBoardRepo>();
    auto mockBoardRepoAdr = mockBoardRepo.get();
    auto mockTaskRepo = std::make_unique<MockTaskRepo>();
    auto mockTaskRepoAdr = mockTaskRepo.get();
    User user(1, "Ivan");
    BoardController boardController(std::move(mockBoardRepo), std::move(mockTaskRepo));
    EXPECT_CALL(*mockTaskRepoAdr, CreateTask("Task", user, "nice task"));
    boardController.AddTask("Task", "nice task", user);
}

TEST(BoardHandlerTest, ChangeTaskStatusTest)
{
    auto mockBoardRepo = std::make_unique<MockBoardRepo>();
    auto mockBoardRepoAdr = mockBoardRepo.get();
    auto mockTaskRepo = std::make_unique<MockTaskRepo>();
    auto mockTaskRepoAdr = mockTaskRepo.get();
    BoardController boardController(std::move(mockBoardRepo), std::move(mockTaskRepo));
    EXPECT_CALL(*mockTaskRepoAdr, ChangeTaskStatus(TaskStatus::Open, 1));
    boardController.ChangeTaskStatus(1, TaskStatus::Open);
}

TEST(BoardHandlerTest, DeleteTaskTest)
{
    auto mockBoardRepo = std::make_unique<MockBoardRepo>();
    auto mockBoardRepoAdr = mockBoardRepo.get();
    auto mockTaskRepo = std::make_unique<MockTaskRepo>();
    auto mockTaskRepoAdr = mockTaskRepo.get();
    BoardController boardController(std::move(mockBoardRepo), std::move(mockTaskRepo));
    EXPECT_CALL(*mockTaskRepoAdr, DeleteTask(1));
    boardController.DeleteTask(1);
}

TEST(BoardHandlerTest, AddTaskToBoardTest)
{
    auto mockBoardRepo = std::make_unique<MockBoardRepo>();
    auto mockBoardRepoAdr = mockBoardRepo.get();
    auto mockTaskRepo = std::make_unique<MockTaskRepo>();
    auto mockTaskRepoAdr = mockTaskRepo.get();
    BoardController boardController(std::move(mockBoardRepo), std::move(mockTaskRepo));
    EXPECT_CALL(*mockTaskRepoAdr, GetAllTasksForBoard(3));
    boardController.GetAllTasksForBoard(3);
}