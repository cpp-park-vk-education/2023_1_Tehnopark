#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <vector>
#include "BoardRepo.hpp"
#include "BoardRepoInterface.hpp"
#include "Board.hpp"

TEST(BoardRepoTest, CreateBoardTest)
{
    BoardRepo boardRepo;
    bool result = boardRepo.CreateBoard(2, "new board");
    EXPECT_TRUE(result);
}

TEST(BoardRepoTest, DeleteBoardTest)
{
    BoardRepo boardRepo;
    bool result = boardRepo.DeleteBoard(2);
    EXPECT_TRUE(result);
}

TEST(BoardRepoTest, GetAllBoardsForProjectTest)
{
    BoardRepo boardRepo;
    boardRepo.GetAllBoardsForProject(3);
    std::vector expected = {Board(3, "new board 1"), Board(3, "new board 2")};
    std::vector result = boardRepo.GetAllBoardsForProject(3);
    EXPECT_EQ(expected, result);
}

TEST(BoardRepoTest, GetAllBoardsForProjectWithIncorrectIdTest)
{
    BoardRepo boardRepo;
    EXPECT_ANY_THROW(boardRepo.GetAllBoardsForProject(10000));
}