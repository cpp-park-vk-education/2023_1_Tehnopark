#pragma once
#include <string>

class Task
{
private:
    /* data */
public:
    Task(int projectId, int boardId, const std::string &taskName);
    ~Task();
};

enum TaskStatus
{
    Open,
    Closed,
    InProgress
};
