#include "Task.hpp"

Task::Task(int projectId, int boardId, const std::string &taskName) :
    ProjectId(projectId), BoardId(boardId), TaskName(taskName),Status(TaskStatus::Open) {}
