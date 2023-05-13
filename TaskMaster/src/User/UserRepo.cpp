#include "UserRepo.hpp"
#include <iostream>

void UserRepo::EditUser(const User& user){
}

void UserRepo::AddTaskToUser(const User& user, const Task& task){
}

void UserRepo::AddBoardToUser(const User& user, const Board& board){
}

void UserRepo::AddProjectToUser(const User& user, const Project& project){
}

void UserRepo::DeleteTaskFromUser(const User& user, const Task& task){
}
void UserRepo::DeleteBoardFromUser(const User& user, const Board& board){

}
void UserRepo::DeleteProjectFromUser(const User& user, const Project& project){

}

std::vector<User> UserRepo::GetUsersForBoard(const Board& board){
    return std::vector<User>();
}

std::vector<User> UserRepo::GetUsersForTask(const Task& task){
    return std::vector<User>();
}

std::vector<User> UserRepo::GetUsersForProject(const Project& project){
    return std::vector<User>();
}

std::vector<User> UserRepo::GetUsers(){
    return std::vector<User>();
}