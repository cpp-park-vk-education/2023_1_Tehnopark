#pragma once
#include <string>

class Board
{
public:
    Board(int projectId, int creatorId, const std::string &name, const std::string &text);
    int ProjectId;
    int CreatorId;
    std::string Name;
    std::string Text;
};
