#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ProjectHandlerInterface.hpp"
#include "ProjectRepoInterface.hpp"
#include "BoardRepoInterface.hpp"
#include "ProjectController.hpp"
#include "User.hpp"
#include "Project.hpp"
#include "Board.hpp"

using namespace testing;

class MockProjectRepo : public ProjectRepoInterface
{
public:
    MOCK_METHOD(Project, GetProjectById, (int projectId), (override));
    MOCK_METHOD(void, CreateProject, (int userId), (override));
    MOCK_METHOD(void, RemoveProjectById, (int projectId), (override));
    MOCK_METHOD(void, UpdateProject, (const Project& project), (override));
};

class MockBoardRepo : public BoardRepoInterface
{
public:
    MOCK_METHOD(std::vector<Board>, GetAllBoardsForProject, (int projectId), (override));
    MOCK_METHOD(bool, CreateBoard, (int projectId, std::string name), (override));
    MOCK_METHOD(bool, DeleteBoard, (int boardId), (override));
};

/* Correct data */

TEST(ProjectHandlerTest, CreateBoardTest)
{
    // MockProjectHandler mockProjectHandler;

    // EXPECT_CALL(mockProjectHandler, CreateBoard(1, 2, "Test Board"))
    //     .Times(1);

    // mockProjectHandler.CreateBoard(1, 2, "Test Board");
}

TEST(ProjectHandlerTest, GetInviteLinkTest)
{
    // EXPECT_CALL(mockProjectHandler, GetInviteLink(1, 2))
    //     .WillOnce(Return("https://example.com/invite/1"));

    // std::string link = mockProjectHandler.GetInviteLink(1, 2);
    // ASSERT_EQ(link, "https://example.com/invite/1");
}

TEST(ProjectHandlerTest, GetAllUsersTest)
{
    // MockProjectHandler mockProjectHandler;
    // std::vector<User> users = {
    //     User(1, "Alice"),
    //     User(2, "Bob")};

    // EXPECT_CALL(mockProjectHandler, GetAllUsers(1, 2))
    //     .WillOnce(Return(users));

    // std::vector<User> returnedUsers = mockProjectHandler.GetAllUsers(1, 2);
    // ASSERT_EQ(returnedUsers, users);
}

TEST(ProjectHandlerTest, GetAllBoardsTest)
{
    auto mockProjectRepo = std::make_unique<MockProjectRepo>();
    auto mockProjectRepoAdr = mockProjectRepo.get();
    auto mockBoardRepo = std::make_unique<MockBoardRepo>();
    auto mockBoardRepoAdr = mockBoardRepo.get();
    
    ProjectController projectController(std::move(mockProjectRepo), std::move(mockBoardRepo));
    EXPECT_CALL(*mockBoardRepoAdr, GetAllBoardsForProject(1));
    auto bords = projectController.GetAllBoards(1);
}

/* Incorrect data*/

// TEST(ProjectHandlerTest, CreateBoardEmptyBoardNameTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, CreateBoard(_, _, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.CreateBoard(-1, 2, ""), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, CreateBoardNegativeProjectIdTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, CreateBoard(_, _, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.CreateBoard(-1, 2, "Test Board"), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, CreateBoardNegativeMainUserIdTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, CreateBoard(_, _, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.CreateBoard(1, -2, "Test Board"), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, GetInviteLinkNegativeProjectIdTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetInviteLink(_, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.GetInviteLink(-1, 1), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, GetInviteLinkNegativeUserIdTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetInviteLink(_, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.GetInviteLink(1, -1), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, GetAllUsersNegativeProjectIdTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetAllUsers(_, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.GetAllUsers(-1, 2), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, GetAllUsersNegativeUserIdTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetAllUsers(_, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.GetAllUsers(-1, 2), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, GetAllBoardsNegativeProjectIdTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetAllBoards(_, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.GetAllBoards(-1, 2), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, GetAllBoardsNegativeUserIdTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetAllBoards(_, _))
//         .Times(0);

//     ASSERT_THROW(mockProjectHandler.GetAllBoards(-1, 2), std::invalid_argument);
// }

// /* Incorrect logic*/

// TEST(ProjectHandlerTest, GetInviteLinkNotBelongingUserTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetInviteLink(1, 3))
//         .WillOnce(Throw(std::runtime_error("User does not belong to project")));

//     ASSERT_THROW(mockProjectHandler.GetInviteLink(1, 3), std::invalid_argument);
// }

// TEST(ProjectHandlerTest, CreateBoardNotBelongingUserTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, CreateBoard(1, 2, "New Board"))
//         .WillOnce(Throw(std::runtime_error("User does not belong to project")));

//     EXPECT_THROW(mockProjectHandler.CreateBoard(1, 2, "New Board"), std::runtime_error);
// }

// TEST(ProjectHandlerTest, GetAllUsersNotBelongingUserTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetAllUsers(1, 2))
//         .WillOnce(Throw(std::runtime_error("User does not belong to project")));

//     EXPECT_THROW(mockProjectHandler.GetAllUsers(1, 2), std::runtime_error);
// }

// TEST(ProjectHandlerTest, GetAllBoardsNotBelongingUserTest)
// {
//     MockProjectHandler mockProjectHandler;

//     EXPECT_CALL(mockProjectHandler, GetAllBoards(1, 2))
//         .WillOnce(Throw(std::runtime_error("User does not belong to project")));

//     EXPECT_THROW(mockProjectHandler.GetAllBoards(1, 2), std::runtime_error);
// }