#pragma once
#include <string>

class Board
{
public:
    Board(int projectId, int creatorId, const std::string &name, const std::string &text);

private:
    int _projectId;
    int _creatorId;
    std::string _name;
    std::string _text;
};
