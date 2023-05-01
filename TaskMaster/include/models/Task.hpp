#pragma once
#include <string>

class Task
{
private:
    /* data */
public:
    std::string name;
    std::string description;
    TaskStatus status;
    
    Task(int projectId, int boardId, const std::string &taskName);
    ~Task();
};

enum TaskStatus
{
    Open,
    Closed,
    InProgress
};
