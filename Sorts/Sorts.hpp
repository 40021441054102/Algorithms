//-- Sort Algorithms
# ifndef ALGORITHMS_OMID_SOJOODI_SORTS
    /**
     * @file Sorts.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Sort Algorithms Header File
     * @date 2024-06-07
     * @def ALGORITHMS_OMID_SOJOODI_SORTS
     * @brief Sort Algorithms Header File Macro
     * @details This Header File Contains Sort Algorithms
     */
    # define ALGORITHMS_OMID_SOJOODI_SORTS
    //-- Include Configurations
    # ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
        # include "../Configs.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_CONFIGS
    //-- Bubble Sort
    # ifndef ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE
        # include "Bubble/Bubble.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE
    //-- Selection Sort
    # ifndef ALGORITHMS_OMID_SOJOODI_SORTS_SELECTION
        # include "Selection/Selection.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_SORTS_SELECTION
    //-- Insertion Sort
    # ifndef ALGORITHMS_OMID_SOJOODI_SORTS_INSERTION
        # include "Insertion/Insertion.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_SORTS_INSERTION
    /**
     * @def SORT_LABEL
     * @brief Sort Log Message
     * @details This Macro Defines Sort Log Message Label
     */
    # define SORT_LABEL "\033[38;2;177;245;217m[SORT]\033[0m "
    /**
     * @class Sorts
     * @brief Sort Algorithms Class
     * @details This Class Contains Sort Algorithms
     * 
     * @param ALGORITHM_SORT_INSERTION Insertion Sort Algorithm
     * @param ALGORITHM_SORT_SELECTION Selection Sort Algorithm
     * @param ALGORITHM_SORT_BUBBLE Bubble Sort Algorithm
     * @param ALGORITHM_SORT_QUICK Quick Sort Algorithm
     * @param ALGORITHM_SORT_MERGE Merge Sort Algorithm
     * @param ALGORITHM_SORT_HEAP Heap Sort Algorithm
     */
    class Sorts {
        public:
            /**
             * @brief Sort Algorithms Constructor
             * @details This Constructor Initializes Sort Algorithms Module
             */
            Sorts();
            /**
             * @brief Bubble Sort Algorithm
             * @details This Method Sorts an Array Using Bubble Sort Algorithm
             */
            BubbleSort bubble;
            /**
             * @brief Selection Sort Algorithm
             * @details This Method Sorts an Array Using Selection Sort Algorithm
             */
            SelectionSort selection;
            /**
             * @brief Insertion Sort Algorithm
             * @details This Method Sorts an Array Using Insertion Sort Algorithm
             */
            InsertionSort insertion;
    };
# endif // ALGORITHMS_OMID_SOJOODI_SORTS