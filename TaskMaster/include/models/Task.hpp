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
private:
    /* data */
public:
    std::string name;
    std::string description;
    TaskStatus status;

    Task(int projectId, int boardId, const std::string &taskName);
    ~Task();
};


