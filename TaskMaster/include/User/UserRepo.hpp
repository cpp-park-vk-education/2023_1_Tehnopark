#pragma once
#include <string>
#include <vector>
#include <memory>
#include "UserRepoInterface.hpp"
#include "DbDriverInterface.hpp"
#include "User.hpp"
#include "Task.hpp"
#include "Board.hpp"

using DbDriverSPtr = std::shared_ptr<DbDriverInterface>;

class UserRepo : public UserRepoInterface
{
public:
    UserRepo(DbDriverSPtr dr): dr_(dr) {}
    void EditUser(const User& user) override;
    void AddTaskToUser(const User& user, const Task& task) override;
    void AddBoardToUser(const User& user, const Board& board) override;
    void AddProjectToUser(const User& user, const Project& project) override;
    void DeleteTaskFromUser(const User& user, const Task& task) override;
    void DeleteBoardFromUser(const User& user, const Board& board) override;
    void DeleteProjectFromUser(const User& user, const Project& project) override;
    std::vector<User> GetUsersForBoard(const Board& board) override;
    std::vector<User> GetUsersForTask(const Task& task) override;
    std::vector<User> GetUsersForProject(const Project& project) override;
    std::vector<User> GetUsers() override;
    ~UserRepo() {}
private:
    DbDriverSPtr dr_;
};
