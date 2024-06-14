//-- Insertion Sort
# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_INSERTION
    /**
     * @file Insertion.hpp
     * @author Ramtin Kosari ( ramtinkosari@gmail.com )
     * @brief Insertion Sort Header File
     * @date 2024-06-14
     * @def ALGORITHMS_OMID_SOJOODI_SORTS_INSERTION
     * @brief Insertion Sort Header File Macro
     * @details This Header File Contains Insertion Sort Algorithm
     */
    # define ALGORITHMS_OMID_SOJOODI_SORTS_INSERTION
    //-- Include Configurations
    # ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
        # include "../../Configs.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_CONFIGS
    //-- Include Graphics Module
    # ifndef GRAPHICS_OMID_SOJOODI
        # include "../../Graphics.hpp"
    # endif // GRAPHICS_OMID_SOJOODI
    /**
     * @def INSERTION_SORT_LABEL
     * @brief Insertion Sort Log Message
     * @details This Macro Defines Insertion Sort Log Message Label
     */
    # define INSERTION_SORT_LABEL "\033[38;2;177;245;217m[INSERTION SORT]\033[0m "
    /**
     * @enum ENUM_SUPPORTED_SORT_ORDERS
     * @brief Supported Sort Orders
     * @details This Enum Contains Supported Sort Orders for Insertion Sort Algorithm
     * 
     * @param ASCENDING Ascending Sort Order
     * @param DESCENDING Descending Sort Order
     */
    enum ENUM_SUPPORTED_SORT_ORDERS_INSERTION {
        INSERTION_ASCENDING,
        INSERTION_DESCENDING
    };
    /**
     * @enum ENUM_SUPPORTED_SORTING_METHODS_INSERTION
     * @brief Supported Sorting Methods
     * @details This Enum Contains Supported Sorting Methods for Insertion Sort Algorithm
     * 
     * @param INSERTION_SORT_LEFT_TO_RIGHT Left to Right Sorting Method
     * @param INSERTION_SORT_RIGHT_TO_LEFT Right to Left Sorting Method
     * @param INSERTION_SORT_TOP_TO_BOTTOM Top to Bottom Sorting Method
     * @param INSERTION_SORT_BOTTOM_TO_TOP Bottom to Top Sorting Method
     * @param INSERTION_SORT_THETA Theta Sorting Method
     */
    enum ENUM_SUPPORTED_SORTING_METHODS_INSERTION {
        INSERTION_SORT_LEFT_TO_RIGHT,
        INSERTION_SORT_RIGHT_TO_LEFT,
        INSERTION_SORT_TOP_TO_BOTTOM,
        INSERTION_SORT_BOTTOM_TO_TOP,
        INSERTION_SORT_THETA
    };
    /**
     * @class InsertionSort
     * @brief Insertion Sort Class
     * @details This Class Contains Insertion Sort Algorithm
     */
    class InsertionSort {
        public:
            /**
             * @brief Insertion Sort Constructor
             * @details This Constructor Initializes Insertion Sort Class
             */
            InsertionSort();
            /**
             * @brief Insertion Sort Destructor
             * @details This Destructor Finalizes Insertion Sort Class
             */
            ~InsertionSort();
            /**
             * @brief Insertion Sort Algorithm
             * @details This Function Sorts an 2D Array (Points Array) Using Insertion Sort Algorithm
             * 
             * @param array Array to Sort
             * @param size Size of Array
             * @param order Sort Order
             * @param graphics Graphics Object
             * @param method Sorting Method
             */
            std::vector<env::Point2D> getSorted2D(
                std::vector<env::Point2D> array,
                ENUM_SUPPORTED_SORT_ORDERS_INSERTION order,
                bool use_graphics,
                Graphics &  graphics,
                ENUM_SUPPORTED_SORTING_METHODS_INSERTION method = INSERTION_SORT_THETA
            );
    };
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_INSERTION