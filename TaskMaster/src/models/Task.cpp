#include "Task.hpp"

Task::Task(int projectId, int boardId, const std::string &taskName, const std::string &text) :
    ProjectId(projectId), BoardId(boardId), TaskName(taskName),Text(text), Status(TaskStatus::Open) {}
