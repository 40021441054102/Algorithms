//-- Check RKACPB Project Builder
# ifndef RKACPB
    # define RKACPB 1
    # pragma message \
        "This Project is Part of 40021441054102 Projects. You are Using It as a Standalone Project"
    # pragma message \
        "If You Want to Compile This Project Under Support, You Must Use RKACPB from https://github.com/RamtinKosari/RKACPB"
    # pragma message \
        "Compiling without RKACPB Support."
# else
    # pragma message \
        "40021441054102 Project Configured and Initialized Successfully, Compiling Under RKACPB Support"
# endif // RKACPB
//-- Algorithms
# ifndef ALGORITHMS_OMID_SOJOODI
    /**
     * @file Algorithms.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Algorithms Header File
     * @date 2024-03-21
     */
    # define ALGORITHMS_OMID_SOJOODI
    //-- Data Generation Methods Enum
    enum ENUM_ALGORITHMS_DATA_METHOD {
        USE_RANDOM_DATA,
        USE_INPUT_FILE,
    };
    //-- Maximum Amount of Random Data
    # define MAX_RANDOM_DATA 1000
    //-- Algorithms Processing Methods
    enum ENUM_ALGORIHTMS_PROCESSING_METHODS {
        USE_SINGLE_THREAD,
        USE_MULTI_THREADS
    };
    //-- Include Needed Libraries
    # include <iostream>
    # include <chrono>
    # include <vector>
    # include <random>
    //-- Define Log Messages
    # define WARNING "\033[38;2;255;255;0m[WARNING]\033[0m "
    # define SUCCESS "\033[38;2;0;255;0m[SUCCESS]\033[0m "
    # define ERROR "\033[38;2;255;0;0m[ERROR]\033[0m "
    # define INFO "\033[38;2;0;255;255m[INFO]\033[0m "
    # define LOG "\033[38;2;0;255;0m[LOG]\033[0m "
    # define RESET "\033[0m"
    # define TAB "   "
    //-- Supported Algorithms
    enum ENUM_SUPPORTED_ALGORITHMS {
        SEARCH_BINARY,
        SORT_INSERTION,
        SORT_SELECTION,
        SORT_BUBBLE,
        SORT_QUICK,
        SORT_MERGE,
        SORT_HEAP,
        MIN_MAX_ARRAY,
        LARGE_NUMBERS_MULTIPLICATION,
        MATRIX_MULTIPLICATION_STRASSEN,
        MATRIX_MULTIPLICATION_SIMPLE,
        MATRIX_MULTIPLICATION_BLOCK,
        MATRIX_CHAIN_MULTIPLICATION,
        DIJKSTRA,
        FLOYD,
        KNAPSACK_0_1,
        KNAPSACK_FRACTIONAL,
        KNAPSACK_BRANCH_BOUNDED,
        TRAVELLER_SALESMAN,
        MOVING_ON_GRID,
        N_QUEENS,
        BFS,
        DFS,
        HUFFMAN_CODING,
        MINIMUM_SPANNING_TREE_PRIM,
        MINIMUM_SPANNING_TREE_KRUSKAL
    };
    //-- Class Definition
    class Algorithms {
        private:
            //-- Begin Time of Algorithm
            std::chrono::high_resolution_clock::time_point begin_time;
            //-- End Time of Algorithm
            std::chrono::high_resolution_clock::time_point end_time;
            //-- Process Time of Algorithm
            std::chrono::duration<double> algorithm_duration;
            //-- Data Vector
            std::vector<int> data;
        public:
            //-- Constructor
            Algorithms(
                ENUM_SUPPORTED_ALGORITHMS algorithm,
                ENUM_ALGORITHMS_DATA_METHOD data_method,
                ENUM_ALGORIHTMS_PROCESSING_METHODS processing_method
            );
            //-- Destructor
            ~Algorithms();
            //-- Method to Generate Random Data
            void generateRandomData(
                int amount,
                int min,
                int max
            );
            //-- Method to Load Data from File
            void loadDataFromFile(
                std::string file_name
            );
            // //-- Generate Chess Board
            // void generateChessBoard(
            //     int size,
            //     int graphic_mode
            // );
            // //-- Generate Map Data
            // void generateMapData(
            //     int size,
            //     int graphic_mode,
            //     int data_generation_method
            // );
            //-- Mouse Callback
            // static void onMouseCallback(int event, int x, int y, int flags, void* userdata);
            //-- Mouse Events
            // void onMouse(int event, int x, int y, int flags);
    };
# endif // ALGORITHMS_OMID_SOJOODI