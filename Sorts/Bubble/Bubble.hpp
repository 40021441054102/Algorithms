//-- Bubble Sort
# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE
    /**
     * @file Bubble.hpp
     * @author Ramtin Kosari ( ramtinkosari@gmail.com )
     * @brief Bubble Sort Header File
     * @date 2024-06-07
     * @def ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE
     * @brief Bubble Sort Header File Macro
     * @details This Header File Contains Bubble Sort Algorithm
     */
    # define ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE
    //-- Include Configurations
    # ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
        # include "../../Configs.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_CONFIGS
    //-- Include Graphics Module
    # ifndef GRAPHICS_OMID_SOJOODI
        # include "../../Graphics.hpp"
    # endif // GRAPHICS_OMID_SOJOODI
    /**
     * @def BUBBLE_SORT_LABEL
     * @brief Bubble Sort Log Message
     * @details This Macro Defines Bubble Sort Log Message Label
     */
    # define BUBBLE_SORT_LABEL "\033[38;2;177;245;217m[BUBBLE SORT]\033[0m "
    /**
     * @enum ENUM_SUPPORTED_SORT_ORDERS
     * @brief Supported Sort Orders
     * @details This Enum Contains Supported Sort Orders for Bubble Sort Algorithm
     * 
     * @param ASCENDING Ascending Sort Order
     * @param DESCENDING Descending Sort Order
     */
    enum ENUM_SUPPORTED_SORT_ORDERS_BUBBLE {
        BUBBLE_ASCENDING,
        BUBBLE_DESCENDING
    };
    /**
     * @enum ENUM_SUPPORTED_SORTING_METHODS
     * @brief Supported Sorting Methods
     * @details This Enum Contains Supported Sorting Methods for Bubble Sort Algorithm
     * 
     * @param BUBBLE_SORT_LEFT_TO_RIGHT Left to Right Sorting Method
     * @param BUBBLE_SORT_RIGHT_TO_LEFT Right to Left Sorting Method
     * @param BUBBLE_SORT_TOP_TO_BOTTOM Top to Bottom Sorting Method
     * @param BUBBLE_SORT_BOTTOM_TO_TOP Bottom to Top Sorting Method
     * @param BUBBLE_SORT_THETA Theta Sorting Method
     */
    enum ENUM_SUPPORTED_SORTING_METHODS {
        BUBBLE_SORT_LEFT_TO_RIGHT,
        BUBBLE_SORT_RIGHT_TO_LEFT,
        BUBBLE_SORT_TOP_TO_BOTTOM,
        BUBBLE_SORT_BOTTOM_TO_TOP,
        BUBBLE_SORT_THETA
    };
    /**
     * @class BubbleSort
     * @brief Bubble Sort Class
     * @details This Class Contains Bubble Sort Algorithm
     */
    class BubbleSort {
        public:
            /**
             * @brief Bubble Sort Constructor
             * @details This Constructor Initializes Bubble Sort Module
             */
            BubbleSort();
            /**
             * @brief Bubble Sort Destructor
             * @details This Destructor Deinitializes Bubble Sort Module
             */
            ~BubbleSort();
            /**
             * @brief Bubble Sort Algorithm
             * @details This Function Sorts an 2D Array (Points Array) Using Bubble Sort Algorithm
             * 
             * @param array Array to Sort
             * @param size Size of Array
             * @param order Sort Order
             * @param graphics Graphics Object
             * @param method Sorting Method
             */
            std::vector<env::Point2D> getSorted2D(
                std::vector<env::Point2D> array,
                ENUM_SUPPORTED_SORT_ORDERS_BUBBLE order,
                bool use_graphics,
                Graphics &  graphics,
                ENUM_SUPPORTED_SORTING_METHODS method = BUBBLE_SORT_THETA
            );
    };
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE