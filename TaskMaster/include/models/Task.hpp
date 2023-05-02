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
    Task(int projectId, int boardId, const std::string &taskName);
    int ProjectId; 
    int BoardId; 
    std::string TaskName;
    TaskStatus Status;
};
