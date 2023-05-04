#pragma once
#include <string>
#include "Board.hpp"
#include "Project.hpp"

enum TaskStatus
{
    Open,
    Closed,
    InProgress
};

class Task
{
public:
    Task(int project, int boardId, const std::string &taskName, const std::string &text);
    int ProjectId; 
    int BoardId; 
    std::string TaskName;
    std::string Text;
    TaskStatus Status;
};
