#pragma once
#include <string>

class Board
{
private:

public:
    std::string name;
    std::string description;
    Board(int projectId, const std::string &boardName);
    ~Board();
};

bool operator==(const Board& a, const Board& b){
    return true;
}