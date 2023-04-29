#include "gmock/gmock.h"
#include "../models/User.hpp"
#include "../models/Project.hpp"
#include "../models/Board.hpp"
#include "ProjectHandlerInterface.hpp"

using namespace testing;

class MockProjectHandler : public ProjectHandlerInterface
{
public:
    MOCK_METHOD(void, CreateBoard, (int projectId, int mainUserId, const std::string &boardName), (override));
    MOCK_METHOD(std::string, GetInviteLink, (int projectId, int userId), (override));
    MOCK_METHOD(std::vector<User>, GetAllUsers, (int projectId, int userId), (override));
    MOCK_METHOD(std::vector<Board>, GetAllBoards, (int projectId, int userId), (override));
};

/* Correct data */

TEST(ProjectHandlerTest, CreateBoardTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, CreateBoard(1, 2, "Test Board"))
        .Times(1);

    mockProjectHandler.CreateBoard(1, 2, "Test Board");
}

TEST(ProjectHandlerTest, GetInviteLinkTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetInviteLink(1, 2))
        .WillOnce(Return("https://example.com/invite/1"));

    std::string link = mockProjectHandler.GetInviteLink(1, 2);
    ASSERT_EQ(link, "https://example.com/invite/1");
}

TEST(ProjectHandlerTest, GetAllUsersTest)
{
    MockProjectHandler mockProjectHandler;
    std::vector<User> users = {
        User(1, "Alice"),
        User(2, "Bob")};

    EXPECT_CALL(mockProjectHandler, GetAllUsers(1, 2))
        .WillOnce(Return(users));

    std::vector<User> returnedUsers = mockProjectHandler.GetAllUsers(1, 2);
    ASSERT_EQ(returnedUsers, users);
}

TEST(ProjectHandlerTest, GetAllBoardsTest)
{
    MockProjectHandler mockProjectHandler;
    std::vector<Board> boards = {
        Board(1, "Board 1"),
        Board(1, "Board 1")};

    EXPECT_CALL(mockProjectHandler, GetAllBoards(1, 2))
        .WillOnce(Return(boards));

    std::vector<Board> returnedBoards = mockProjectHandler.GetAllBoards(1, 2);
    ASSERT_EQ(returnedBoards, boards);
}

/* Incorrect data*/

TEST(ProjectHandlerTest, CreateBoardEmptyBoardNameTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, CreateBoard(_, _, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.CreateBoard(-1, 2, ""), std::invalid_argument);
}

TEST(ProjectHandlerTest, CreateBoardNegativeProjectIdTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, CreateBoard(_, _, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.CreateBoard(-1, 2, "Test Board"), std::invalid_argument);
}

TEST(ProjectHandlerTest, CreateBoardNegativeMainUserIdTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, CreateBoard(_, _, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.CreateBoard(1, -2, "Test Board"), std::invalid_argument);
}

TEST(ProjectHandlerTest, GetInviteLinkNegativeProjectIdTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetInviteLink(_, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.GetInviteLink(-1, 1), std::invalid_argument);
}

TEST(ProjectHandlerTest, GetInviteLinkNegativeUserIdTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetInviteLink(_, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.GetInviteLink(1, -1), std::invalid_argument);
}

TEST(ProjectHandlerTest, GetAllUsersNegativeProjectIdTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetAllUsers(_, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.GetAllUsers(-1, 2), std::invalid_argument);
}

TEST(ProjectHandlerTest, GetAllUsersNegativeUserIdTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetAllUsers(_, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.GetAllUsers(-1, 2), std::invalid_argument);
}

TEST(ProjectHandlerTest, GetAllBoardsNegativeProjectIdTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetAllBoards(_, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.GetAllBoards(-1, 2), std::invalid_argument);
}

TEST(ProjectHandlerTest, GetAllBoardsNegativeUserIdTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetAllBoards(_, _))
        .Times(0);

    ASSERT_THROW(mockProjectHandler.GetAllBoards(-1, 2), std::invalid_argument);
}

/* Incorrect logic*/

TEST(ProjectHandlerTest, GetInviteLinkNotBelongingUserTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetInviteLink(1, 3))
        .WillOnce(Throw(std::runtime_error("User does not belong to project")));

    ASSERT_THROW(mockProjectHandler.GetInviteLink(1, 3), std::invalid_argument);
}

TEST(ProjectHandlerTest, CreateBoardNotBelongingUserTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, CreateBoard(1, 2, "New Board"))
        .WillOnce(Throw(std::runtime_error("User does not belong to project")));

    EXPECT_THROW(mockProjectHandler.CreateBoard(1, 2, "New Board"), std::runtime_error);
}

TEST(ProjectHandlerTest, GetAllUsersNotBelongingUserTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetAllUsers(1, 2))
        .WillOnce(Throw(std::runtime_error("User does not belong to project")));

    EXPECT_THROW(mockProjectHandler.GetAllUsers(1, 2), std::runtime_error);
}

TEST(ProjectHandlerTest, GetAllBoardsNotBelongingUserTest)
{
    MockProjectHandler mockProjectHandler;

    EXPECT_CALL(mockProjectHandler, GetAllBoards(1, 2))
        .WillOnce(Throw(std::runtime_error("User does not belong to project")));

    EXPECT_THROW(mockProjectHandler.GetAllBoards(1, 2), std::runtime_error);
}