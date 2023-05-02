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

private:
    int _projectId; 
    int _boardId; 
    std::string _taskName;
    TaskStatus _status;
};
