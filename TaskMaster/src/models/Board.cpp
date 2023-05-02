#include "Board.hpp"

Board::Board(int projectId, int creatorId, const std::string &name, const std::string &text) : 
    ProjectId(projectId), CreatorId(creatorId), Name(name), Text(text) {}
