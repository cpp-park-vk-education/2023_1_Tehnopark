#include <gtest/gtest.h>
#include <gmock/gmock.h>
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
    DbDriverMock mock;
    EXPECT_CALL(mock, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(mock, Exec("SELECT * FROM users"))
        .WillRepeatedly(testing::Return(users));
    UserRepo repo(&mock);
    repo.GetUsers();
}