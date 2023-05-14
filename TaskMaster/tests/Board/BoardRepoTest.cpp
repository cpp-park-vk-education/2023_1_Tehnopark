#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <vector>
#include "BoardRepo.hpp"
#include "DbDriverMock.hpp"
#include "BoardRepoInterface.hpp"
#include "Board.hpp"

TEST(BoardRepoTest, CreateBoardCallTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    Board board(1, 1, "newBoard", "lorem ipsum");
    EXPECT_CALL(*mockDbDriverAdr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(*mockDbDriverAdr, 
                Exec("INSERT INTO board (ProjectId, CreatorId, Name, Text) VALUES (1), (1), ('newBoard'), ('lorem ipsum');"))
                .Times(testing::AtLeast(1));
    boardRepo.CreateBoard(board);
}

TEST(BoardRepoTest, CreateBoardCorrectTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int projectId = 1, creatorId = 1;
    Board board(projectId, creatorId, "newBoard", "lorem ipsum");
    bool result = boardRepo.CreateBoard(board);
    EXPECT_TRUE(result);
}

TEST(BoardRepoTest, CreateBoardUncorrectProjectTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int projectId = -1, creatorId = 1;
    Board board(projectId, creatorId, "newBoard", "lorem ipsum");
    EXPECT_THROW(boardRepo.CreateBoard(board), std::exception);
}

TEST(BoardRepoTest, CreateBoardUncorrectCreatorTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int projectId = 1, creatorId = -1;
    Board board(projectId, creatorId, "newBoard", "lorem ipsum");
    EXPECT_THROW(boardRepo.CreateBoard(board), std::exception);
}

TEST(BoardRepoTest, CreateBoardUncorrectNameTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int projectId = 1, creatorId = 1;
    Board board(projectId, creatorId, "", "lorem ipsum");
    EXPECT_THROW(boardRepo.CreateBoard(board), std::exception);
}

TEST(BoardRepoTest, CreateBoardUncorrectTextTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int projectId = 1, creatorId = 1;
    Board board(projectId, creatorId, "newBoard", "");
    EXPECT_THROW(boardRepo.CreateBoard(board), std::exception);
}

TEST(BoardRepoTest, DeleteBoardCallTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    EXPECT_CALL(*mockDbDriverAdr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(*mockDbDriverAdr, Exec("DELETE FROM board WHERE id = 1;"))
                .Times(testing::AtLeast(1));
    boardRepo.DeleteBoard(1);
}

TEST(BoardRepoTest, DeleteBoardCorrectTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int boardId = 2;
    bool result = boardRepo.DeleteBoard(boardId);
    EXPECT_TRUE(result);
}

TEST(BoardRepoTest, DeleteBoardUncorrectTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int boardId = -1;
    EXPECT_THROW(boardRepo.DeleteBoard(boardId), std::exception);
}

TEST(BoardRepoTest, GetAllBoardsForProjectCallTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    EXPECT_CALL(*mockDbDriverAdr, Connected())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));
    EXPECT_CALL(*mockDbDriverAdr, Exec("SELECT board.Name, board.Text FROM project INNER JOIN board ON project.id = board.projectId"))
                .Times(testing::AtLeast(1));
    boardRepo.GetAllBoardsForProject(3);
}

TEST(BoardRepoTest, GetAllBoardsForProjectCorrectTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int projectId = 1;
    std::vector expected = {Board(projectId, 1,  "newBoard 1", "lorem inpum 1"), 
                            Board(projectId, 1,  "newBoard 2", "lorem inpum 2")};
    std::vector result = boardRepo.GetAllBoardsForProject(projectId);
    EXPECT_EQ(expected, result);
}

TEST(BoardRepoTest, GetAllBoardsForProjectUncorrectTest)
{
    auto mockDbDriver = std::make_unique<DbDriverMock>();
    auto mockDbDriverAdr = mockDbDriver.get();
    BoardRepo boardRepo(std::move(mockDbDriver));
    int projectId = -1;
    std::vector result = boardRepo.GetAllBoardsForProject(projectId);
    EXPECT_THROW(boardRepo.GetAllBoardsForProject(projectId), std::exception);
}