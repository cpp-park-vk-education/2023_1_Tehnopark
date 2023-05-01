#pragma once
#include <string>
#include <vector>
#include "UserRepoInterface.hpp"
#include "User.hpp"
#include "Task.hpp"

class UserRepo: public UserRepoInterface
{
public:
    bool EditUser(User user)  override;
    bool AddTaskToUser(User user, Task task)  override;
    bool AddBoardToUser(User user, Board board)  override;
    std::vector<User> GetUsersForBoard(int boardId) override;
    std::vector<User> GetUsersForTask(int userId)  override;
    std::vector<User> GetUsers()  override;
    ~UserRepo();
};