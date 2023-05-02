#pragma once
#include <string>

enum TaskStatus
{
    Open,
    Closed,
    InProgress
};

class Task
{
public:
    Task(int projectId, int boardId, const std::string &taskName, const std::string &text);
    int ProjectId; 
    int BoardId; 
    std::string TaskName;
    std::string Text;
    TaskStatus Status;
};
