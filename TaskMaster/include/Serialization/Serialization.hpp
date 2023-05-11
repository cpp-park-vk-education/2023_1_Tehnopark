#include <vector>
#include <string>
#include "Project.hpp"
#include "Board.hpp"
#include "User.hpp"
#include "Task.hpp"

std::vector<Project> serializationProject(const std::vector<std::vector<std::string>> &answer);
std::vector<Board> serializationBoard(const std::vector<std::vector<std::string>> &answer);
std::vector<User> serializationUser(const std::vector<std::vector<std::string>> &answer);
std::vector<Task> serializationTask(const std::vector<std::vector<std::string>> &answer);
