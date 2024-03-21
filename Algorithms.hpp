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
# endif // MRL_HSL
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
    //-- Define Log Messages
    # define WARNING "\033[38;2;255;255;0m[WARNING]\033[0m "
    # define SUCCESS "\033[38;2;0;255;0m[SUCCESS]\033[0m "
    # define ERROR "\033[38;2;255;0;0m[ERROR]\033[0m "
    # define INFO "\033[38;2;0;255;255m[INFO]\033[0m "
    # define LOG "\033[38;2;0;255;0m[LOG]\033[0m "
    # define RESET "\033[0m"
    # define TAB "   "
    //-- Class Definition
    class Algorithms {
        private:
            //-- Begin Time of Algorithm
            std::chrono::high_resolution_clock::time_point begin_time;
            //-- End Time of Algorithm
            std::chrono::high_resolution_clock::time_point end_time;
            //-- Process Time of Algorithm
            std::chrono::duration<double> algorithm_duration;
        public:
            // //-- Constructor
            // Algorithms();
            // //-- Generate Random Data
            // void generateRandomData(
            //     int size,
            //     int min,
            //     int max
            // );
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