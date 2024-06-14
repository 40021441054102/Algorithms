//-- Include Necessary Headers
# include "Algorithms.hpp"

/**
 * @def CYAN
 * @brief Cyan Color for Terminal
 * @details Define Light Cyan Color for Terminal
 */
# define CYAN "\033[38;2;0;255;255m"
/**
 * @def CYAN2
 * @brief Dark Cyan Color for Terminal
 * @details Define Dark Cyan Color for Terminal
 */
# define CYAN2 "\033[38;2;0;170;170m"
/**
 * @def yellow
 * @brief Yellow Color for Terminal
 * @details Define Light Yellow Color for Terminal
 */
# define YELLOW "\033[38;2;255;255;0m"
/**
 * @def YELLOW2
 * @brief Dark Yellow Color for Terminal
 * @details Define Dark Yellow Color for Terminal
 */
# define YELLOW2 "\033[38;2;120;120;0m"
/**
 * @def NOT_IMPLEMENTED
 * @brief Not Implemented Color for Terminal
 * @details Define Not Implemented Label for Terminal
 */
# define NOT_IMPLEMENTED "\033[65G\033[38;2;130;53;0m NOT IMPLEMENTED\033[0m"
/**
 * @def IMPLEMENTED
 * @brief Implemented Color for Terminal
 * @details Define Implemented Label for Terminal
 */
# define IMPLEMENTED "\033[65G\033[38;2;0;130;0m IMPLEMENTED\033[0m"
/**
 * @def IMPLEMENTING
 * @brief Implementing Color for Terminal
 * @details Define Implementing Label for Terminal
 */
# define IMPLEMENTING "\033[65G\033[38;2;130;85;0m IMPLEMENTING\033[0m"

/**
 * @brief Method to Clear Terminal
 */
void clearTerminal() {
    std::cout << "\033[2J\x1b[H";
}

/**
 * @brief Main Method
 * @details Main Method to Run the Program and Select the Algorithm
 * 
 * @return int 
 */
int main() {
    while (true) {
        clearTerminal();
        cv::destroyAllWindows();
        std::cout << CYAN "Select Algorithm :" << std::endl;
        //-- Sorts
        std::cout << TAB CYAN "1." CYAN2 " Sorts" << std::endl;
        std::cout << TAB TAB YELLOW "1.1." YELLOW2 " Selection Sort" IMPLEMENTED << std::endl;
        std::cout << TAB TAB YELLOW "1.2." YELLOW2 " Insertion Sort" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "1.3." YELLOW2 " Bubble Sort" IMPLEMENTED << std::endl;
        std::cout << TAB TAB YELLOW "1.4." YELLOW2 " Merge Sort" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "1.5." YELLOW2 " Quick Sort" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "1.6." YELLOW2 " Heap Sort" IMPLEMENTING << std::endl;
        //-- Search
        std::cout << TAB CYAN "2." CYAN2 " Search" << std::endl;
        std::cout << TAB TAB YELLOW "2.1." YELLOW2 " Linear Search" NOT_IMPLEMENTED << std::endl;
        std::cout << TAB TAB YELLOW "2.2." YELLOW2 " Binary Search" IMPLEMENTING << std::endl;
        //-- Min Max
        std::cout << TAB CYAN "3." CYAN2 " Min Max" << std::endl;
        std::cout << TAB TAB YELLOW "3.1." YELLOW2 " Min Max of Array" NOT_IMPLEMENTED << std::endl;
        //-- Large Numbers Operations
        std::cout << TAB CYAN "4." CYAN2 " Large Numbers Operations" << std::endl;
        std::cout << TAB TAB YELLOW "4.1." YELLOW2 " Multiplication of Large Numbers" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "4.2." YELLOW2 " Subtraction of Large Numbers" NOT_IMPLEMENTED << std::endl;
        std::cout << TAB TAB YELLOW "4.3." YELLOW2 " Addition of Large Numbers" NOT_IMPLEMENTED << std::endl;
        std::cout << TAB TAB YELLOW "4.4." YELLOW2 " Division of Large Numbers" NOT_IMPLEMENTED << std::endl;
        //-- Matrix Operations
        std::cout << TAB CYAN "5." CYAN2 " Matrix Operations" << std::endl;
        std::cout << TAB TAB YELLOW "5.1." YELLOW2 " Strassen Matrix Multiplication" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "5.2." YELLOW2 " Matrix Chain Multiplication" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "5.3." YELLOW2 " Block Matrix Multiplication" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "5.4." YELLOW2 " Floyd Warshall Algorithm" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "5.5." YELLOW2 " Inverse of Matrix" NOT_IMPLEMENTED << std::endl;
        //-- TSP
        std::cout << TAB CYAN "6." CYAN2 " Travelling Salesman Problem" << std::endl;
        std::cout << TAB TAB YELLOW "6.1." YELLOW2 " TSP Dynamic Programming" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "6.2." YELLOW2 " TSP Genetic Algorithm" NOT_IMPLEMENTED << std::endl;
        std::cout << TAB TAB YELLOW "6.3." YELLOW2 " TSP Branch and Bound" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "6.4." YELLOW2 " TSP Brute Force" NOT_IMPLEMENTED << std::endl;
        //-- Knapsack
        std::cout << TAB CYAN "7." CYAN2 " Knapsack Problem" << std::endl;
        std::cout << TAB TAB YELLOW "7.1." YELLOW2 " Fractional Knapsack Problem" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "7.2." YELLOW2 " 0/1 Knapsack Problem" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "7.3." YELLOW2 " 0/1 Knapsack Branch and Bound Problem" IMPLEMENTING << std::endl;
        //-- Moving on a Grid
        std::cout << TAB CYAN "8." CYAN2 " Moving on a Grid" << std::endl;
        std::cout << TAB TAB YELLOW "8.1." YELLOW2 " Moving on a Grid" IMPLEMENTING << std::endl;
        //-- Minimum Spanning Tree
        std::cout << TAB CYAN "9." CYAN2 " Minimum Spanning Tree" << std::endl;
        std::cout << TAB TAB YELLOW "9.1." YELLOW2 " Kruskal's Algorithm" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "9.2." YELLOW2 " Prim's Algorithm" IMPLEMENTING << std::endl;
        //-- Shortest Path
        std::cout << TAB CYAN "10." CYAN2 " Shortest Path" << std::endl;
        std::cout << TAB TAB YELLOW "10.1." YELLOW2 " Floyd Warshall Algorithm" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "10.2." YELLOW2 " Bellman Ford Algorithm" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "10.3." YELLOW2 " Dijkstra's Algorithm" IMPLEMENTING << std::endl;
        //-- Huffman Coding
        std::cout << TAB CYAN "11." CYAN2 " Huffman Coding" << std::endl;
        std::cout << TAB TAB YELLOW "11.1." YELLOW2 " Huffman Coding" IMPLEMENTING << std::endl;
        //-- N Queens Problem
        std::cout << TAB CYAN "12." CYAN2 " N Queens Problem" << std::endl;
        std::cout << TAB TAB YELLOW "12.1." YELLOW2 " N Queens Problem" IMPLEMENTING << std::endl;
        //-- Convex Hull
        std::cout << TAB CYAN "13." CYAN2 " Convex Hull" << std::endl;
        std::cout << TAB TAB YELLOW "13.1." YELLOW2 " Jarvis March" IMPLEMENTING << std::endl;
        std::cout << TAB TAB YELLOW "13.2." YELLOW2 " Graham Scan" IMPLEMENTING << std::endl;
        //-- Graph
        std::cout << TAB CYAN "14." CYAN2 " Graph" << std::endl;
        std::cout << TAB TAB YELLOW "14.1." YELLOW2 " Breadth First Search" NOT_IMPLEMENTED << std::endl;
        std::cout << TAB TAB YELLOW "14.2." YELLOW2 " Depth First Search" NOT_IMPLEMENTED << std::endl;
        // {
            // //-- Tree
            // std::cout << TAB CYAN "4." CYAN2 " Tree" << std::endl;
            // std::cout << TAB TAB YELLOW "4.1." YELLOW2 " Binary Search Tree" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "4.2." YELLOW2 " AVL Tree" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "4.3." YELLOW2 " Red Black Tree" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "4.4." YELLOW2 " B Tree" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "4.5." YELLOW2 " B+ Tree" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "4.6." YELLOW2 " B* Tree" NOT_IMPLEMENTED<< std::endl;
            // //-- Hash
            // std::cout << TAB CYAN "5." CYAN2 " Hash" << std::endl;
            // std::cout << TAB TAB YELLOW "5.1." YELLOW2 " Hash Table" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "5.2." YELLOW2 " Hash Map" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "5.3." YELLOW2 " Hash Set" NOT_IMPLEMENTED << std::endl;
            // //-- String
            // std::cout << TAB CYAN "6." CYAN2 " String" << std::endl;
            // std::cout << TAB TAB YELLOW "6.1." YELLOW2 " KMP Algorithm" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "6.2." YELLOW2 " Rabin Karp Algorithm" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "6.3." YELLOW2 " Z Algorithm" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "6.4." YELLOW2 " Boyer Moore Algorithm" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "6.5." YELLOW2 " Aho Corasick Algorithm" NOT_IMPLEMENTED << std::endl;
            // //-- Matrix
            // std::cout << TAB CYAN "7." CYAN2 " Matrix" << std::endl;
            // //-- Dynamic Programming
            // std::cout << TAB CYAN "8." CYAN2 " Dynamic Programming" << std::endl;
            // std::cout << TAB TAB YELLOW "8.1." YELLOW2 " Fibonacci Series" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.2." YELLOW2 " Longest Common Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.3." YELLOW2 " Longest Increasing Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.4." YELLOW2 " 0/1 Knapsack Problem" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.5." YELLOW2 " Matrix Chain Multiplication" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.6." YELLOW2 " Edit Distance" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.7." YELLOW2 " Subset Sum Problem" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.8." YELLOW2 " Coin Change Problem" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.9." YELLOW2 " Rod Cutting Problem" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.10." YELLOW2 " Palindrome Partitioning" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.11." YELLOW2 " Word Break Problem" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.12." YELLOW2 " Maximum Sum Increasing Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.13." YELLOW2 " Maximum Sum of Non-Adjacent Elements" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.14." YELLOW2 " Longest Palindromic Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.15." YELLOW2 " Count of Subsets with Sum Equal to K" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.16." YELLOW2 " Count of Subsets with Given Difference" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.17." YELLOW2 " Shortest Common Supersequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.18." YELLOW2 " Minimum Number of Deletions to Make a String Palindrome" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.19." YELLOW2 " Minimum Number of Insertions to Make a String Palindrome" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.20." YELLOW2 " Longest Repeating Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.21." YELLOW2 " Longest Common Substring" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.22." YELLOW2 " Shortest Common Supersequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.23." YELLOW2 " Maximum Length of Repeated Subarray" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.24." YELLOW2 " Minimum Number of Squares whose Sum is Equal to Given Number" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.25." YELLOW2 " Maximum Sum of 3 Non-Overlapping Subarrays" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.26." YELLOW2 " Maximum Sum of Rectangle No Larger Than K" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.27." YELLOW2 " Maximum Product Subarray" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.28." YELLOW2 " Maximum Length of Pair Chain" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.29." YELLOW2 " Maximum Length of Repeated Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.30." YELLOW2 " Maximum Sum Increasing Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.31." YELLOW2 " Maximum Length of Longest Increasing Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.32." YELLOW2 " Maximum Length of Longest Bitonic Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.33." YELLOW2 " Maximum Length of Longest Alternating Subsequence" NOT_IMPLEMENTED << std::endl;
            // std::cout << TAB TAB YELLOW "8.34." YELLOW2 " Maximum Length of Longest Subsequence with Difference Between Adjacent Elements as Either 0 or 1" NOT_IMPLEMENTED << std::endl;
        // }
        //-- Run
        std::cout << TAB CYAN "0." CYAN2 " Exit" << std::endl;
        int choice;
        std::cout << CYAN "Enter Choice : " CYAN2; std::cin >> choice;
        //-- Handle Choice
        switch (choice) {
            //-- Exit
            case 0: {
                clearTerminal();
                std::cout << SUCCESS "Terminating Program" << std::endl;
                return 0;
            }
            //-- Sorts
            case 1: {
                clearTerminal();
                std::cout << CYAN " Sorts" << std::endl;
                std::cout << TAB CYAN "1." CYAN2 " Selection Sort"  IMPLEMENTED << std::endl;
                std::cout << TAB CYAN "2." CYAN2 " Insertion Sort"  IMPLEMENTING << std::endl;
                std::cout << TAB CYAN "3." CYAN2 " Bubble Sort"     IMPLEMENTED << std::endl;
                std::cout << TAB CYAN "4." CYAN2 " Merge Sort"      IMPLEMENTING << std::endl;
                std::cout << TAB CYAN "5." CYAN2 " Quick Sort"      IMPLEMENTING << std::endl;
                std::cout << TAB CYAN "6." CYAN2 " Heap Sort"       IMPLEMENTING << std::endl;
                std::cout << TAB CYAN "0." CYAN2 " Back" << std::endl;
                int choice;
                std::cout << CYAN "Enter Choice : " CYAN2; std::cin >> choice;
                //-- Handle Choice
                switch (choice) {
                    //-- Back
                    case 0: {
                        // cv::destroyAllWindows();
                        break;
                    }
                    //-- Selection Sort
                    case 1: {
                        //-- Create Algorithm Object
                        Algorithms algorithm(
                            ALGORITHM_SORT_SELECTION,
                            ENVIRONMENT_2D,
                            USE_RANDOM_DATA,
                            USE_SINGLE_THREAD
                        );
                        break;
                    }
                    //-- Insertion Sort
                    case 2: {
                        break;
                    }
                    //-- Bubble Sort
                    case 3: {
                        //-- Create Algorithm Object
                        Algorithms algorithm(
                            ALGORITHM_SORT_BUBBLE,
                            ENVIRONMENT_2D,
                            USE_RANDOM_DATA,
                            USE_SINGLE_THREAD
                        );
                        std::cin >> choice;
                        break;
                    }
                    //-- Merge Sort
                    case 4: {
                        break;
                    }
                    //-- Quick Sort
                    case 5: {
                        break;
                    }
                    //-- Heap Sort
                    case 6: {
                        break;
                    }
                    //-- Default
                    default: {
                        break;
                    }
                }
                break;
            }
        }
    }
}