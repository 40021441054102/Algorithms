# ifndef ALGORITHMS_OMID_SOJOODI_NQUEENS
    # include "NQueens.hpp"
    /**
     * @brief NQueens Constructor
     * @details This Constructor Initializes NQueens Module
     */
    NQueens::NQueens() {
        std::cout << NQUEENS_LABEL << "N Queens Module Initialized" << std::endl;
    }
    /**
     * @brief Is Safe
     * @details This Method Checks if the Queen is Safe to Place
     * 
     * @param row Row Number
     * @param col Column Number
     * @param graphics Graphics Module
     * @return bool True if Queen is Safe to Place, False Otherwise
     */
    bool NQueens::isSafe(int row, int col, Graphics &graphics) {
        //-- Check if There's a Queen in the Same Column
        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
        for (int i = 0; i < row; ++i) {
            cv::circle(
                graphics.windows.temp2.matrix,
                cv::Point(
                    (col * graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 2),
                    (i * graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE / 2)
                ),
                graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 12,
                cv::Scalar(0, 255, 0),
                -1
            );
            cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
            cv::waitKey(1);
            //-- Check if There's a Queen in the Same Column
            if (board[i] == col) {
                cv::line(
                    graphics.windows.temp1.matrix,
                    cv::Point(
                        (col * graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 2),
                        (i * graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE / 2)
                    ),
                    cv::Point(
                        (col * graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 2),
                        (row * graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE / 2)
                    ),
                    cv::Scalar(0, 150, 255),
                    4
                );
                cv::circle(
                    graphics.windows.temp2.matrix,
                    cv::Point(
                        (col * graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 2),
                        (i * graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE / 2)
                    ),
                    graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 17,
                    cv::Scalar(0, 0, 255),
                    -1
                );
                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                cv::waitKey(1);
                return false;
            }
            //-- Check Diagonals
            if (abs(board[i] - col) == abs(i - row)) {
                cv::line(
                    graphics.windows.temp1.matrix,
                    cv::Point(
                        (board[i] * graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 2),
                        (i * graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE / 2)
                    ),
                    cv::Point(
                        (col * graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 2),
                        (row * graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE / 2)
                    ),
                    cv::Scalar(0, 150, 255),
                    4
                );
                cv::circle(
                    graphics.windows.temp2.matrix,
                    cv::Point(
                        (col * graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 2),
                        (i * graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE) + (graphics.windows.temp2.matrix.rows / CHESS_BOARD_SIZE / 2)
                    ),
                    graphics.windows.temp2.matrix.cols / CHESS_BOARD_SIZE / 17,
                    cv::Scalar(0, 0, 255),
                    -1
                );
                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                cv::waitKey(1);
                return false;
            }
        }
        //-- Return True
        return true;
    }
    /**
     * @brief Solve NQueens Problem
     * @details This Method Solves NQueens Problem
     * 
     * @param col Column Number
     * @param graphics Graphics Module
     * @return bool True if Queen is Safe to Place, False Otherwise
     */
    void NQueens::solveNQueens(int row, Graphics &graphics) {
        if (row == CHESS_BOARD_SIZE) {
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < CHESS_BOARD_SIZE; ++col) {
            if (isSafe(row, col, graphics)) {
                board[row] = col;
                solveNQueens(row + 1, graphics);
                board[row] = -1;
            }
        }
    }
    /**
     * @brief Solve NQueens Problem
     * @details This Method Solves NQueens Problem
     * 
     * @param homes Homes
     * @param graphics Graphics Module
     */
    void NQueens::getSolved(std::vector<std::vector<env::Box2D>> &homes, Graphics &graphics) {
        //-- Initialize Board
        board = std::vector<int>(CHESS_BOARD_SIZE, -1);
        //-- Initialize Graphics
        graphics.windows.main.matrix.copyTo(graphics.windows.temp1.matrix);
        //-- Solve NQueens Problem
        solveNQueens(0, graphics);
        //-- Print Solutions
        int amount = solutions.size();
        std::cout << MODULE NQUEENS_LABEL << "Number of Solutions for " << CHESS_BOARD_SIZE << "-Queens Problem : " << amount << std::endl;
        for (int i = 0; i < solutions.size(); ++i) {
            // printBoard(solutions[i]);
        }
    }
    /**
     * @brief Print Board
     * @details This Method Prints Chess Board
     * 
     * @param board Chess Board
     */
    void NQueens::printBoard(const std::vector<int> &board) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i] == j)
                    std::cout << "Q ";
                else
                    std::cout << ". ";
            }
            std::cout << std::endl;
        }
    }
# endif // ALGORITHMS_OMID_SOJOODI_NQUEENS