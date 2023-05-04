#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "ProjectRepoInterface.hpp"
#include "ProjectRepo.hpp"
#include "Project.hpp"
#include "User.hpp"
#include "DbDriverMock.hpp"

class ProjectRepoTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

/* Correct data */

TEST_F(ProjectRepoTest, GetProjectByIdTest){
    int projectId = 1;
    DbDriverMock dbDriverMock;
    EXPECT_CALL(dbDriverMock, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    auto dbDriver = std::make_shared<DbDriverMock>();
    std::string expectedSqlQuery = "SELECT * FROM projects WHERE id = " + std::to_string(projectId) + ";";
    EXPECT_CALL(dbDriverMock, Exec(expectedSqlQuery))
        .WillRepeatedly(testing::Return(std::vector<std::vector<std::string>>{}));
    ProjectRepo projectRepo(dbDriver);
    projectRepo.GetProjectById(projectId);
}

TEST_F(ProjectRepoTest, CreateProjectTest){
    int userId = 1;
    std::string projectName = "Project 1";
    DbDriverMock dbDriverMock;
    EXPECT_CALL(dbDriverMock, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    auto dbDriver = std::make_shared<DbDriverMock>();
    std::string expectedSqlQuery = "INSERT INTO projects VALUES ( " + std::to_string(userId) + ", " + projectName + ");";
    EXPECT_CALL(dbDriverMock, Exec(expectedSqlQuery))
        .WillRepeatedly(testing::Return(std::vector<std::vector<std::string>>{}));
    ProjectRepo projectRepo(dbDriver);
    bool result = projectRepo.CreateProject(userId, projectName);
    EXPECT_TRUE(result);
}

TEST_F(ProjectRepoTest, RemoveProjectByIdTest){
    int projectId = 1;
    DbDriverMock dbDriverMock;
    EXPECT_CALL(dbDriverMock, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    auto dbDriver = std::make_shared<DbDriverMock>();
    std::string expectedSqlQuery = "DELETE * FROM projects WHERE id = " + std::to_string(projectId) + ";";
    EXPECT_CALL(dbDriverMock, Exec(expectedSqlQuery))
        .WillRepeatedly(testing::Return(std::vector<std::vector<std::string>>{}));
    ProjectRepo projectRepo(dbDriver);
    bool result = projectRepo.RemoveProjectById(projectId);
    EXPECT_TRUE(result);
}

TEST_F(ProjectRepoTest, AddUserToProjecTest){
    int projectId = 1;
    std::string userName = "Max";
    DbDriverMock dbDriverMock;
    EXPECT_CALL(dbDriverMock, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    auto dbDriver = std::make_shared<DbDriverMock>();
    std::string expectedSqlQuery = "INSERT INTO projects_users VALUES ( " + std::to_string(projectId) + ", " + userName + ");";
    EXPECT_CALL(dbDriverMock, Exec(expectedSqlQuery))
        .WillRepeatedly(testing::Return(std::vector<std::vector<std::string>>{}));
    ProjectRepo projectRepo(dbDriver);
    bool result = projectRepo.AddUserToProject(projectId, userName);
    EXPECT_TRUE(result);
}

TEST_F(ProjectRepoTest, UpdateProjectTest){
    Project project(1, "Project Name");
    DbDriverMock dbDriverMock;
    EXPECT_CALL(dbDriverMock, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    auto dbDriver = std::make_shared<DbDriverMock>();
    std::string expectedSqlQuery = "UPDATE projects SET name = " + project.ProjectName + "WHERE name = " + project.ProjectName + ";";
    EXPECT_CALL(dbDriverMock, Exec(expectedSqlQuery))
        .WillRepeatedly(testing::Return(std::vector<std::vector<std::string>>{}));
    ProjectRepo projectRepo(dbDriver);
    bool result = projectRepo.UpdateProject(project);
    EXPECT_TRUE(result);
}

