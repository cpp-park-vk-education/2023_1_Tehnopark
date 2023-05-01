#pragma once
#include "Task.hpp"

class BoardHandlerInterface
{
public:
    virtual ~BoardHandlerInterface() { }

    virtual bool AddTask(int taskId) = 0;

    virtual void DeleteTask(int taskId) = 0;

    virtual void ChangeTaskStatus(int taskId, TaskStatus status) = 0;
};