#include "Task.hpp"

Task::Task( int boardId, const std::string &taskName, const std::string &text) :
     BoardId(boardId), TaskName(taskName),Text(text), Status(TaskStatus::Open) {}
