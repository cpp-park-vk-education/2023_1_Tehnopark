#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ProjectRepoInterface.hpp"
#include "BoardRepoInterface.hpp"
#include "UserRepoInterface.hpp"
#include "ProjectController.hpp"
#include "User.hpp"
#include "Project.hpp"
#include "Board.hpp"

using namespace testing;

class ProjectControllerTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

class MockProjectRepo : public ProjectRepoInterface
{
public:
    MOCK_METHOD(Project, GetProjectById, (int projectId), (override));
    MOCK_METHOD(void, CreateProject, (int userId, const std::string &projectName), (override));
    MOCK_METHOD(void, RemoveProjectById, (int projectId), (override));
    MOCK_METHOD(void, AddUserToProject, (int projectId, const std::string &userName), (override));
    MOCK_METHOD(void, UpdateProject, (const Project& project), (override));
};

class MockBoardRepo : public BoardRepoInterface
{
public:
    MOCK_METHOD(std::vector<Board>, GetAllBoardsForProject, (int projectId), (override));
    MOCK_METHOD(bool, CreateBoard, (int projectId, int creatorId, const std::string &name), (override));
    MOCK_METHOD(bool, DeleteBoard, (int boardId), (override));
};

class MockUserRepo : public UserRepoInterface
{
public:
    MOCK_METHOD(bool, EditUser, (const User& user), (override));
    MOCK_METHOD(bool, AddTaskToUser, (const User& user, const Task& task), (override));
    MOCK_METHOD(bool, AddBoardToUser, (const User& user, const Board& board), (override));
    MOCK_METHOD(std::vector<User>, GetUsersForBoard, (int boardId), (override));
    MOCK_METHOD(std::vector<User>, GetUsersForTask, (int userId), (override));
    MOCK_METHOD(std::vector<User>, GetUsersForProject, (int projectId), (override));
    MOCK_METHOD(std::vector<User>, GetUsers, (), (override));
};

/* Correct data */

TEST_F(ProjectControllerTest, CreateBoardTest)
{
    int projectId = 1;
    std::string boardName = "TestBoard";
    MockBoardRepo mockBoardRepo;
    EXPECT_CALL(mockBoardRepo, CreateBoard(projectId, _, boardName));
    std::unique_ptr<BoardRepoInterface> boardRepo = std::make_unique<MockBoardRepo>();
    ProjectController projectController(nullptr, std::move(boardRepo), nullptr);

    projectController.CreateBoard(1, projectId, boardName);
}

TEST_F(ProjectControllerTest, AddUserTest)
{
    int projectId = 1;
    std::string userName = "Maxim";
    MockProjectRepo mockProjecRepo;
    EXPECT_CALL(mockProjecRepo, AddUserToProject(projectId, userName));
    std::unique_ptr<ProjectRepoInterface> projectRepo = std::make_unique<MockProjectRepo>();
    ProjectController projectController(std::move(projectRepo), nullptr, nullptr);

    projectController.AddUser(projectId, userName);
}

TEST_F(ProjectControllerTest, GetAllUsersTest)
{
    int projectId = 1;
    MockUserRepo mockUserRepo;
    EXPECT_CALL(mockUserRepo, GetUsersForProject(projectId));
    std::unique_ptr<UserRepoInterface> userRepo = std::make_unique<MockUserRepo>();
    ProjectController projectController(nullptr, nullptr, std::move(userRepo));

    projectController.GetAllUsers(projectId);
}

TEST_F(ProjectControllerTest, GetAllBoardsTest)
{
    int projectId = 1;
    MockBoardRepo mockBoardRepo;
    EXPECT_CALL(mockBoardRepo, GetAllBoardsForProject(projectId));
    std::unique_ptr<BoardRepoInterface> boardRepo = std::make_unique<MockBoardRepo>();
    ProjectController projectController(nullptr, std::move(boardRepo), nullptr);

    projectController.GetAllBoards(projectId);
}

/* Incorrect data*/

TEST_F(ProjectControllerTest, CreateBoardEmptyBoardNameTest)
{
    int userId = 1;
    int projectId = 1;
    std::string boardName = "";
    MockBoardRepo mockBoardRepo;
    EXPECT_CALL(mockBoardRepo, CreateBoard(projectId, userId, boardName));
    std::unique_ptr<BoardRepoInterface> boardRepo = std::make_unique<MockBoardRepo>();
    ProjectController projectController(nullptr, std::move(boardRepo), nullptr);

    ASSERT_THROW(projectController.CreateBoard(userId, projectId, boardName), std::invalid_argument);
}

TEST_F(ProjectControllerTest, CreateBoardNegativeProjectIdTest)
{
    int userId = 1;
    int projectId = -1;
    std::string boardName = "Board Name";
    MockBoardRepo mockBoardRepo;
    EXPECT_CALL(mockBoardRepo, CreateBoard(projectId, userId, boardName));
    std::unique_ptr<BoardRepoInterface> boardRepo = std::make_unique<MockBoardRepo>();
    ProjectController projectController(nullptr, std::move(boardRepo), nullptr);

    ASSERT_THROW(projectController.CreateBoard(userId, projectId, boardName), std::invalid_argument);
}

TEST_F(ProjectControllerTest, AddUserNegativeProjectIdTest)
{
    int projectId = -1;
    std::string userName = "Maxim";
    MockProjectRepo mockProjecRepo;
    EXPECT_CALL(mockProjecRepo, AddUserToProject(projectId, userName));
    std::unique_ptr<ProjectRepoInterface> projectRepo = std::make_unique<MockProjectRepo>();
    ProjectController projectController(std::move(projectRepo), nullptr, nullptr);

    ASSERT_THROW(projectController.AddUser(projectId, userName), std::invalid_argument);
}

TEST_F(ProjectControllerTest, AddUserEmptyUserNameIdTest)
{
    int projectId = 1;
    std::string userName = "";
    MockProjectRepo mockProjecRepo;
    EXPECT_CALL(mockProjecRepo, AddUserToProject(projectId, userName));
    std::unique_ptr<ProjectRepoInterface> projectRepo = std::make_unique<MockProjectRepo>();
    ProjectController projectController(std::move(projectRepo), nullptr, nullptr);

    ASSERT_THROW(projectController.AddUser(projectId, userName), std::invalid_argument);
}

TEST_F(ProjectControllerTest, GetAllUsersNegativeProjectIdTest)
{
    int projectId = -1;
    MockUserRepo mockUserRepo;
    EXPECT_CALL(mockUserRepo, GetUsersForProject(projectId));
    std::unique_ptr<UserRepoInterface> userRepo = std::make_unique<MockUserRepo>();
    ProjectController projectController(nullptr, nullptr, std::move(userRepo));

    ASSERT_THROW(projectController.GetAllUsers(projectId), std::invalid_argument);
}

TEST_F(ProjectControllerTest, GetAllBoardsNegativeProjectIdTest)
{
    int projectId = -1;
    MockBoardRepo mockBoardRepo;
    EXPECT_CALL(mockBoardRepo, GetAllBoardsForProject(projectId));
    std::unique_ptr<BoardRepoInterface> boardRepo = std::make_unique<MockBoardRepo>();
    ProjectController projectController(nullptr, std::move(boardRepo), nullptr);

    ASSERT_THROW(projectController.GetAllBoards(projectId), std::invalid_argument);
}
