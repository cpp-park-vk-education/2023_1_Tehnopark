#include "Task.hpp"

Task::Task(int projectId, int boardId, const std::string &taskName) :
    _projectId(projectId), _boardId(boardId), _taskName(taskName),_status(TaskStatus::Open) {}
