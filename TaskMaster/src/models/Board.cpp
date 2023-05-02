#include "Board.hpp"

Board::Board(int projectId, int creatorId, const std::string &name, const std::string &text) : 
    _projectId(projectId), _creatorId(creatorId), _name(name), _text(text) {}
