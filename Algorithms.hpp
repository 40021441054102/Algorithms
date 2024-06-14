//-- Check RKACPB Project Builder
# ifndef RKACPB
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
     * @def ALGORITHMS_OMID_SOJOODI
     * @brief Algorithms Header File Macro
     * @details This Header File Contains All Needed Definitions and Classes for Algorithms
     */
    # define ALGORITHMS_OMID_SOJOODI
    /**
     * @enum ENUM_ALGORITHM_ENVIRONMENT
     * @brief Data Generation Methods
     * @details This Enum Contains All Supported Data Generation Methods for Algorithms Class
     * 
     * @param USE_RANDOM_DATA Use Random Data, Generates Random Data for Algorithms
     * @param USE_INPUT_FILE Use Input File, Loads Data from Input File for Algorithms
     */
    enum ENUM_ALGORITHMS_DATA_METHOD {
        USE_RANDOM_DATA,
        USE_INPUT_FILE,
    };
    /**
     * @enum ENUM_RANDOM_DATA_SHAPES
     * @brief Random Data Shapes
     * @details This Enum Contains All Supported Random Data Shapes for Algorithms Class
     * 
     * @param RANDOM_DATA_SHAPE_LEMNISCATE_OF_BERNOULLI Generates Random Data in Lemniscate of Bernoulli Shape
     * @param RANDOM_DATA_SHAPE_LISSAJOUS_CURVE Generates Random Data in Lissajous Curve Shape
     * @param RANDOM_DATA_SHAPE_HYPOTROCHOID Generates Random Data in Hypotrochoid Shape
     * @param RANDOM_DATA_SHAPE_SPIRAL_ROAD Generates Random Data in Spiral Road Shape
     * @param RANDOM_DATA_SHAPE_NAUTILUS Generates Random Data in Nautilus Shape
     * @param RANDOM_DATA_SHAPE_ASTROID Generates Random Data in Astroid Shape
     * @param RANDOM_DATA_SHAPE_DELTOID Generates Random Data in Deltoid Shape
     * @param RANDOM_DATA_SHAPE_CLUSTER Generates Random Data in Cluster Shape
     * @param RANDOM_DATA_SHAPE_ELLIPSE Generates Random Data in Ellipse Shape
     * @param RANDOM_DATA_SHAPE_SATURN Generates Random Data in Saturn Planet Shape
     * @param RANDOM_DATA_SHAPE_ROSE_8 Generates Random Data in Rose 8 Petal Shape
     * @param RANDOM_DATA_SHAPE_ROSE_5 Generates Random Data in Rose 5 Petal Shape
     * @param RANDOM_DATA_SHAPE_ROSE_4 Generates Random Data in Rose 4 Petal Shape
     * @param RANDOM_DATA_SHAPE_ROSE_3 Generates Random Data in Rose 3 Petal Shape
     * @param RANDOM_DATA_SHAPE_STAR_1 Generates Random Data in Star Model 1 Shape
     * @param RANDOM_DATA_SHAPE_STAR_2 Generates Random Data in Star Model 2 Shape
     * @param RANDOM_DATA_SHAPE_SPIRAL Generates Random Data in Spiral Shape
     * @param RANDOM_DATA_SHAPE_LINE Generates Random Data in Line Shape
     * @param RANDOM_DATA_SHAPE_qb Generates Random Data in qb Shape
     */
    enum ENUM_RANDOM_DATA_SHAPES {
        RANDOM_DATA_SHAPE_LEMNISCATE_OF_BERNOULLI,
        RANDOM_DATA_SHAPE_LISSAJOUS_CURVE,
        RANDOM_DATA_SHAPE_HYPOTROCHOID,
        RANDOM_DATA_SHAPE_SPIRAL_ROAD,
        RANDOM_DATA_SHAPE_NAUTILUS,
        RANDOM_DATA_SHAPE_ASTROID,
        RANDOM_DATA_SHAPE_DELTOID,
        RANDOM_DATA_SHAPE_CLUSTER,
        RANDOM_DATA_SHAPE_ELLIPSE,
        RANDOM_DATA_SHAPE_SATURN,
        RANDOM_DATA_SHAPE_ROSE_8,
        RANDOM_DATA_SHAPE_ROSE_5,
        RANDOM_DATA_SHAPE_ROSE_4,
        RANDOM_DATA_SHAPE_ROSE_3,
        RANDOM_DATA_SHAPE_STAR_1,
        RANDOM_DATA_SHAPE_STAR_2,
        RANDOM_DATA_SHAPE_SPIRAL,
        RANDOM_DATA_SHAPE_LINE,
        RANDOM_DATA_SHAPE_qb
    };
    /**
     * @enum ENUM_CALCULATE_DATA_THETA
     * @brief Calculate Data Theta
     * @details This Enum Contains All Supported Theta Calculation Methods for Algorithms Class
     * 
     * @param CALCULATE_DATA_THETA_HIGHEST Calculate Data Theta from Highest Point
     * @param CALCULATE_DATA_THETA_LOWEST Calculate Data Theta from Lowest Point
     * @param CALCULATE_DATA_THETA_CORNER Calculate Data Theta from Corner Point
     * @param CALCULATE_DATA_THETA_MIDDLE Calculate Data Theta from Middle Point
     */
    enum ENUM_CALCULATE_DATA_THETA {
        CALCULATE_DATA_THETA_HIGHEST,
        CALCULATE_DATA_THETA_LOWEST,
        CALCULATE_DATA_THETA_CORNER,
        CALCULATE_DATA_THETA_MIDDLE,
    };
    /**
     * @def MAX_RANDOM_DATA
     * @brief Maximum Amount of Random Data
     * @details This Macro Defines Maximum Amount of Random Data to Generate Input Elements for Algorithms
     * 
     * @warning Maximum Random Data Value is Set According to the Algorithm's Needs and Note that Higher Values May Cause Memory Issues and Performance Degradation
     */
    # define MAX_RANDOM_DATA 3773
    /**
     * @enum ENUM_ALGORIHTMS_PROCESSING_METHODS
     * @brief Algorithms Processing Methods
     * @details This Enum Contains All Supported Processing Methods for Algorithms Class
     * 
     * @param USE_SINGLE_THREAD Use Single Thread, Processes Algorithms with Single Thread
     * @param USE_MULTI_THREADS Use Multi Threads, Processes Algorithms with Multi Threads
     */
    enum ENUM_ALGORIHTMS_PROCESSING_METHODS {
        USE_SINGLE_THREAD,
        USE_MULTI_THREADS
    };
    /**
     * @enum ENUM_SUPPORTED_ALGORITHMS
     * @brief Supported Algorithms
     * @details This Enum Contains All Supported Algorithms for Algorithms Class
     * 
     * @note Each Algorithm Has Its Own Data and Processing Method, So You Must Define Them Before Using the Algorithm
     * 
     * @param ALGORITHM_SEARCH_BINARY Binary Search Algorithm
     * @param ALGORITHM_SORT_INSERTION Insertion Sort Algorithm
     * @param ALGORITHM_SORT_SELECTION Selection Sort Algorithm
     * @param ALGORITHM_SORT_BUBBLE Bubble Sort Algorithm
     * @param ALGORITHM_SORT_QUICK Quick Sort Algorithm
     * @param ALGORITHM_SORT_MERGE Merge Sort Algorithm
     * @param ALGORITHM_SORT_HEAP Heap Sort Algorithm
     * @param ALGORITHM_MIN_MAX_ARRAY Min Max Array Algorithm
     * @param ALGORITHM_LARGE_NUMBERS_MULTIPLICATION Large Numbers Multiplication Algorithm
     * @param ALGORITHM_MATRIX_MULTIPLICATION_STRASSEN Strassen Matrix Multiplication Algorithm
     * @param ALGORITHM_MATRIX_MULTIPLICATION_SIMPLE Simple Matrix Multiplication Algorithm
     * @param ALGORITHM_MATRIX_MULTIPLICATION_BLOCK Block Matrix Multiplication Algorithm
     * @param ALGORITHM_MATRIX_CHAIN_MULTIPLICATION Matrix Chain Multiplication Algorithm
     * @param ALGORITHM_DIJKSTRA Dijkstra Algorithm
     * @param ALGORITHM_FLOYD Floyd Algorithm
     * @param ALGORITHM_KNAPSACK_0_1 0/1 Knapsack Algorithm
     * @param ALGORITHM_KNAPSACK_FRACTIONAL Fractional Knapsack Algorithm
     * @param ALGORITHM_KNAPSACK_BRANCH_BOUNDED Branch and Bounded Knapsack Algorithm
     * @param ALGORITHM_TRAVELLER_SALESMAN Traveller Salesman Algorithm
     * @param ALGORITHM_MOVING_ON_GRID Moving on Grid Algorithm
     * @param ALGORITHM_N_QUEENS N Queens Algorithm
     * @param ALGORITHM_BFS Breadth First Search Algorithm
     * @param ALGORITHM_DFS Depth First Search Algorithm
     * @param ALGORITHM_HUFFMAN_CODING Huffman Coding Algorithm
     * @param ALGORITHM_MINIMUM_SPANNING_TREE_PRIM Minimum Spanning Tree Prim Algorithm
     * @param ALGORITHM_MINIMUM_SPANNING_TREE_KRUSKAL Minimum Spanning Tree Kruskal Algorithm
     */
    enum ENUM_SUPPORTED_ALGORITHMS {
        ALGORITHM_SEARCH_BINARY,
        ALGORITHM_SORT_INSERTION,
        ALGORITHM_SORT_SELECTION,
        ALGORITHM_SORT_BUBBLE,
        ALGORITHM_SORT_QUICK,
        ALGORITHM_SORT_MERGE,
        ALGORITHM_SORT_HEAP,
        ALGORITHM_MIN_MAX_ARRAY,
        ALGORITHM_LARGE_NUMBERS_MULTIPLICATION,
        ALGORITHM_MATRIX_MULTIPLICATION_STRASSEN,
        ALGORITHM_MATRIX_MULTIPLICATION_SIMPLE,
        ALGORITHM_MATRIX_MULTIPLICATION_BLOCK,
        ALGORITHM_MATRIX_CHAIN_MULTIPLICATION,
        ALGORITHM_DIJKSTRA,
        ALGORITHM_FLOYD,
        ALGORITHM_KNAPSACK_0_1,
        ALGORITHM_KNAPSACK_FRACTIONAL,
        ALGORITHM_KNAPSACK_BRANCH_BOUNDED,
        ALGORITHM_TRAVELLER_SALESMAN,
        ALGORITHM_MOVING_ON_GRID,
        ALGORITHM_N_QUEENS,
        ALGORITHM_BFS,
        ALGORITHM_DFS,
        ALGORITHM_HUFFMAN_CODING,
        ALGORITHM_MINIMUM_SPANNING_TREE_PRIM,
        ALGORITHM_MINIMUM_SPANNING_TREE_KRUSKAL
    };
    //-- Include Needed Headers
    # ifndef GRAPHICS_OMID_SOJOODI
        # include "Graphics.hpp"
    # endif // GRAPHICS_OMID_SOJOODI
    //-- Include Sort Algorithms
    # ifndef ALGORITHMS_OMID_SOJOODI_SORTS
        # include "Sorts/Sorts.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_SORTS
    /**
     * @def ALGORITHMS_LABEL
     * @brief Algorithms Log Message
     * @details This Macro Defines Algorithms Log Message Label
     */
    # define ALGORITHMS_LABEL "\033[38;2;177;245;217m[ALGORITHMS]\033[0m "
    //-- Include Needed Libraries
    # include <iostream>
    # include <chrono>
    # include <vector>
    # include <random>
    /**
     * @class Algorithms
     * @brief Algorithms Class
     * @details This Class Contains All Needed Definitions and Methods for Algorithms
     * 
     * @param algorithm_duration Process Time of Algorithm
     * @param begin_time Begin Time of Algorithm
     * @param end_time End Time of Algorithm
     * @param data Data Vector
     * 
     * @see ENUM_ALGORIHTMS_PROCESSING_METHODS      (\ref Algorithms.hpp "Algorithm" Processing Methods)
     * @see ENUM_ALGORITHMS_DATA_METHOD             (\ref Algorithms.hpp "Algorithm" Data Generation Methods)
     * @see ENUM_ALGORITHM_ENVIRONMENT              (\ref Graphics.hpp "Graphics" Environment)
     * @see ENUM_SUPPORTED_ALGORITHMS               (\ref Algorithms.hpp "Algorithm" Supported by the Class)
     * @see MAX_RANDOM_DATA                         (Maximum Random Data Value)
     * @see Algorithms.hpp
     */
    class Algorithms {
        private:
            Graphics graphics;
            /**
             * @brief Represents the 2D Data Vector.
             * @details The Variable is Used to Store the 2D Data for the Algorithm.
             */
            std::vector<env::Point2D> data2D;
            /**
             * @brief Represents the 3D Data Vector.
             * @details The Variable is Used to Store the 3D Data for the Algorithm.
             */
            std::vector<env::Point3D> data3D;
            /**
             * @brief Represents the Starting Time Point.
             * @details The Variable is Initialized in the Constructor and Used to Calculate the Processing Time of the Algorithm.
             */
            std::chrono::high_resolution_clock::time_point begin_time;
            /**
             * @brief Represents the Ending Time Point.
             * @details The Variable is Initialized in the Destructor and Used to Calculate the Processing Time of the Algorithm.
             */
            std::chrono::high_resolution_clock::time_point end_time;
            /**
             * @brief Represents the Duration of the Algorithm.
             * @details The Variable is Calculated in the Destructor and Used to Show the Processing Time of the Algorithm.
             */
            std::chrono::duration<double> algorithm_duration;
            /**
             * @brief Represents the Data Vector.
             * @details The Variable is Used to Store the Input Data for the Algorithm.
             */
            std::vector<int> data;
            /**
             * @brief Represents the Base Index of the Data.
             * @details The Variable is Used to Store the Base Index of the Data for the Algorithm.
             */
            int base_index;
        public:
            /**
             * @brief Algorithms Constructor
             * @details This Constructor Initializes the Algorithm with the Given Parameters.
             * 
             * @param algorithm The Algorithm to Use
             * @param environment The Environment to Use
             * @param dataMethod The Data Method to Use
             * @param processingMethod The Processing Method to Use
             * 
             * @see ENUM_SUPPORTED_ALGORITHMS               (\ref Algorithms.hpp "Algorithm" Supported by the Class)
             * @see ENUM_ALGORITHM_ENVIRONMENT              (\ref Graphics.hpp "Graphics" Environment)
             * @see ENUM_ALGORITHMS_DATA_METHOD             (\ref Algorithms.hpp "Algorithm" Data Generation Methods)
             * @see ENUM_ALGORIHTMS_PROCESSING_METHODS      (\ref Algorithms.hpp "Algorithm" Processing Methods)
             */
            Algorithms(
                ENUM_SUPPORTED_ALGORITHMS algorithm,
                ENUM_ALGORITHM_ENVIRONMENT environment,
                ENUM_ALGORITHMS_DATA_METHOD data_method,
                ENUM_ALGORIHTMS_PROCESSING_METHODS processing_method
            );
            /**
             * @brief Algorithms Destructor
             * @details This Destructor Finalizes the Algorithm and Shows the Processing Time.
             */
            ~Algorithms();
            /**
             * @brief Generate Random 3D Environment Data
             * @details This Method Generates Random 3D Environment Data for the Algorithm.
             * 
             * @param amount The Amount of Data to Generate
             * @param min The Minimum Value of Data
             * @param max The Maximum Value of Data
             * 
             * @see ENUM_ALGORITHM_ENVIRONMENT              (\ref Graphics.hpp "Graphics" Environment)
             */
            void generateRandom3DData(
                int amount,
                int min,
                int max
            );
            /**
             * @brief Generate Random 2D Environment Data
             * @details This Method Generates Random 2D Environment Data for the Algorithm.
             * 
             * @param amount The Amount of Data to Generate
             * @param min The Minimum Value of Data
             * @param max The Maximum Value of Data
             * 
             * @see ENUM_ALGORITHM_ENVIRONMENT              (\ref Graphics.hpp "Graphics" Environment)
             */
            void generateRandom2DData(
                int amount,
                int min,
                int max
            );
            /**
             * @brief Generate Random Data
             * @details This Method Generates Random Data for the Algorithm.
             * 
             * @param amount The Amount of Data to Generate
             * @param min The Minimum Value of Data
             * @param max The Maximum Value of Data
             */
            void generateRandomData(
                int amount,
                int min,
                int max,
                ENUM_ALGORITHM_ENVIRONMENT environment = ENVIRONMENT_2D,
                ENUM_RANDOM_DATA_SHAPES shape = RANDOM_DATA_SHAPE_ELLIPSE,
                ENUM_CALCULATE_DATA_THETA calc_theta = CALCULATE_DATA_THETA_CORNER
            );
            /**
             * @brief Load Data from File
             * @details This Method Loads Data from File for the Algorithm.
             * 
             * @param file_name The File Name to Load Data from
             * 
             * @see ENUM_ALGORITHM_ENVIRONMENT              (\ref Graphics.hpp "Graphics" Environment)
             */
            void loadDataFromFile(
                std::string file_name
            );
            /**
             * @brief Sort Algorithms
             * @details This Method Contains Several Sort Algorithms to Use.
             * 
             * @param ALGORITHM_SORT_INSERTION Insertion Sort Algorithm
             * @param ALGORITHM_SORT_SELECTION Selection Sort Algorithm
             * @param ALGORITHM_SORT_BUBBLE Bubble Sort Algorithm
             * @param ALGORITHM_SORT_QUICK Quick Sort Algorithm
             * @param ALGORITHM_SORT_MERGE Merge Sort Algorithm
             * @param ALGORITHM_SORT_HEAP Heap Sort Algorithm
             */
            Sorts sorts;
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