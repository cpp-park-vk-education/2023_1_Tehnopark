#include "BoardRepo.hpp"
#include "Serialization.hpp"
#include <exception>
#include <iostream>

bool BoardRepo::CreateBoard(int projectId, int creatorId, const std::string &name, const std::string &text)
{
    if (!_dbDriver->Connected())
        return false;
    _dbDriver->Exec("INSERT INTO board (project_id, creator_id, name, text) VALUES ("
                     + std::to_string(projectId) + ", " + std::to_string(creatorId) + ", "
                     + name + ", " + text + ");");
    return true;
}

Board BoardRepo::GetBoard(int boardId)
{
    if (!_dbDriver->Connected())
        return false;
    auto answer = _dbDriver->Exec("SELECT * FROM board WHERE id=" + std::to_string(boardId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Board with id=" + std::to_string(projectId) + " not found");
    return serializationBoard(answer[0]);
}

bool BoardRepo::DeleteBoard(int boardId)
{
    if (!_dbDriver->Connected())
        return false;
    _dbDriver->Exec("DELETE FROM board WHERE id=" + std::to_string(boardId) + ";");
    return true;
}

std::vector<Board> BoardRepo::GetAllBoardsForProject(int projectId)
{
    if (!_dbDriver->Connected())
        throw std::runtime_error("Database is unavailable");
    auto answer = _dbDriver->Exec("SELECT * FROM board WHERE project_id=" + std::to_string(projectId) + ";");
    if (answer.size() == 0)
        throw std::runtime_error("Boards with project_Id=" + std::to_string(projectId) + " not found");
    std::vector<Board> res;
    for (const auto &data : answer)
    {
        res.push_back(serializationBoard(data));
    }
    return res;
}
