# ifndef ALGORITHMS_OMID_SOJOODI_NQUEENS
    /**
     * @file NQueens.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief NQueens Header File
     * @date 2024-06-16
     * @def ALGORITHMS_OMID_SOJOODI_NQUEENS
     * @brief NQueens Header File Macro
     * @details This Header File Contains All the Required Libraries and Classes for NQueens Problem
     */
    # define ALGORITHMS_OMID_SOJOODI_NQUEENS
    //-- Include Configurations
    # ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
        # include "../Configs.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_CONFIGS
    //-- Include Graphics Module
    # ifndef GRAPHICS_OMID_SOJOODI
        # include "../Graphics.hpp"
    # endif // GRAPHICS_OMID_SOJOODI
    /**
     * @def NQUEENS_LABEL
     * @brief N Queens Log Message
     * @details This Macro Defines N Queens Log Message Label
     */
    # define NQUEENS_LABEL "\033[38;2;177;245;217m[N QUEENS]\033[0m "
    /**
     * @def NQUEENS_BOARD_SIZE
     * @brief Chess Board Size
     * @details This Macro Defines Chess Board Size
     */
    # define CHESS_BOARD_SIZE                       5
    /**
     * @def CHESS_BOARD_WHITE_COLOR
     * @brief Chess Board White Color
     * @details This Macro Defines Chess Board White Color
     */
    # define CHESS_BOARD_WHITE_COLOR                cv::Scalar(93, 120, 138)
    /**
     * @def CHESS_BOARD_BLACK_COLOR
     * @brief Chess Board Black Color
     * @details This Macro Defines Chess Board Black Color
     */
    # define CHESS_BOARD_BLACK_COLOR                cv::Scalar(46, 58, 87)
    /**
     * @def TERMINAL_QUEEN
     * @brief Terminal Queen Color
     * @details This Macro Defines Terminal Queen Color
     */
    # define TERMINAL_QUEEN                         "\033[48;2;0;255;255m "
    /**
     * @def TERMINAL_EMPTY
     * @brief Terminal Empty Color
     * @details This Macro Defines Terminal Empty Color
     */
    # define TERMINAL_EMPTY                         "\033[48;2;0;60;110m "
    /**
     * @class NQueens
     * @brief N Queens Class
     * @details This Class Contains N Queens Problem
     */
    class NQueens {
        public:
            /**
             * @brief Chess Board
             * @details This Attribute Contains Chess Board
             */
            std::vector<int> board;
            /**
             * @brief Solutions
             * @details This Attribute Contains Solutions
             */
            std::vector<std::vector<int>> solutions;
            /**
             * @brief Constructor
             * @details This Constructor Initializes NQueens Module
             */
            NQueens();
            /**
             * @brief Chess Board
             * @details This Method Contains Chess Board
             * 
             * @param row Row Number
             * @param col Column Number
             * @param graphics Graphics Module
             * @return true True if Queen is Safe to Place, False Otherwise
             * @return false False if Queen is Not Safe to Place, True Otherwise
             */
            bool isSafe(int row, int col, Graphics &graphics);
            /**
             * @brief Solve NQueens Problem
             * @details This Method Solves NQueens Problem
             * 
             * @param col Column Number
             * @param graphics Graphics Module
             * @return true True if NQueens Problem is Solved, False Otherwise
             * @return false False if NQueens Problem is Not Solved, True Otherwise
             */
            void solveNQueens(int col, Graphics &graphics);
            /**
             * @brief Solve NQueens Problem
             * @details This Method Solves NQueens Problem
             * 
             * @param homes Chess Board
             * @param graphics Graphics Module
             */
            void getSolved(std::vector<std::vector<env::Box2D>> &homes, Graphics &graphics);
            /**
             * @brief Print Board
             * @details This Method Prints Chess Board
             * 
             * @param board Chess Board
             */
            void printBoard(const std::vector<int> &board);
    };
# endif // ALGORITHMS_OMID_SOJOODI_NQUEENS