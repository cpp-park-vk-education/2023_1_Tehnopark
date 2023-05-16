#include "BoardRepoInterface.hpp"
#include "DbDriverInterface.hpp"
#include <memory>

using IDbDriverUptr = std::unique_ptr<DbDriverInterface>;

class BoardRepo : public BoardRepoInterface
{
public:
    ~BoardRepo() { }
    BoardRepo(IDbDriverUptr dbBriver) : _dbDriver(std::move(dbBriver)) { }
    std::vector<Board> GetAllBoardsForProject(int projectId) override;
    bool CreateBoard(int projectId, int creatorId, const std::string &name, const std::string &text) override;
    bool DeleteBoard(int boardId) override;
    Board GetBoard(int boardId) override;
private:
    IDbDriverUptr _dbDriver;
};