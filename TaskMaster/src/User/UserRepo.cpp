#include "UserRepo.hpp"

bool UserRepo::EditUser(const User& user){
    return true;
}

bool UserRepo::AddTaskToUser(const User& user, const Task& task){
    return true;
}

bool UserRepo::AddBoardToUser(const User& user, const Board& board){
    return true;
}

std::vector<User> UserRepo::GetUsersForBoard(int boardId){
    return std::vector<User>();
}

std::vector<User> UserRepo::GetUsersForTask(int userId){
    return std::vector<User>();
}

std::vector<User> UserRepo::GetUsersForProject(int projectId){
    return std::vector<User>();
}

std::vector<User> UserRepo::GetUsers(){
    return std::vector<User>();
}