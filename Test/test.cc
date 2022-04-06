#include "gtest/gtest.h"
#include "../Board/include/board.h"

using namespace ChessBoard;

class BoardTest: public ::testing::Test{

    protected:
        Board *b1_ = new Board();
        Board *b2_ = new Board('C', '4');
};

TEST_F(BoardTest, AllCellsCreated){
    EXPECT_EQ(b1_->cells.size(), 64) << "Board Not Created with 64 Cells";
    EXPECT_EQ(b2_->cells.size(), 64) << "Board Not Created with 64 Cells";
}

TEST_F(BoardTest, CornersHandled){
    EXPECT_EQ(b1_->cells["A1"]->_num_of_neighbours, 3) << "Cell A1 does not have 3 neighbours";
    EXPECT_EQ(b1_->cells["A2"]->_num_of_neighbours, 5) << "Cell A2 does not have 5 neighbours";
    EXPECT_EQ(b1_->cells["B2"]->_num_of_neighbours, 8) << "Cell B2 does not have 8 neighbours";
    EXPECT_EQ(b1_->cells["B2"]->_num_of_neighbours, b1_->cells["B2"]->neighbours.size()) << "Cell B2 not linked properly";
    EXPECT_EQ(b1_->cells["H5"]->_num_of_neighbours, b1_->cells["H5"]->neighbours.size()) << "Cell H5  not linked properly";
}

