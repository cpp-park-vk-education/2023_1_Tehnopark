#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "UserRepoInterface.hpp"
#include "UserRepo.hpp"
#include "User.hpp"
#include "Project.hpp"
#include "Board.hpp"
#include "DbDriverMock.hpp"

using std::vector;
using std::string;

namespace{
    vector<vector<string> > users = vector<vector<string> >{
        vector<string>{"1", "Ivan", "Ivanov", "CEO"},
        vector<string>{"2", "Petr", "Petrow", "Team-lead"},
    };
}

class UserRepoTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(UserRepoTest, GetUsersNormal){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(*mocAddr, Exec("SELECT * FROM users"))
        .WillRepeatedly(testing::Return(users));
    UserRepo repo(mock);
    repo.GetUsers();
}

TEST_F(UserRepoTest, GetUsersDisconnect){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(false));
}

TEST_F(UserRepoTest, EditUserNormal){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, EditUserDisconnect){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(false));
}

TEST_F(UserRepoTest, EditUserNoUser){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}


TEST_F(UserRepoTest, AddTaskToUserNormal){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, AddTaskToUserNoTask){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, AddTaskToUserNoUser){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, AddTaskToUserDisconnect){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(false));
}

TEST_F(UserRepoTest, AddBoardToUserNormal){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, AddBoardToUserNoBoard){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, AddTaskToUserNoUser){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, GetUsersForBoardNormal){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, GetUsersForBoardNoBoard){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, GetUsersForTaskNormal){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, GetUsersForTaskNoTask){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, GetUsersForProjectNormal){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}

TEST_F(UserRepoTest, GetUsersForProjectNoProject){
    auto mock = std::make_shared<DbDriverMock>();
    auto mocAddr = mock.get();
    EXPECT_CALL(*mocAddr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
}














