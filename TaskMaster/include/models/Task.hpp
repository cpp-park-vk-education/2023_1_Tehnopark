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
    Task(int boardId, const std::string &taskName, const std::string &text);
    size_t BoardId;
    size_t Id; 
    std::string TaskName;
    std::string Text;
    TaskStatus Status;
};
