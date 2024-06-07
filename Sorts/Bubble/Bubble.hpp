//-- Bubble Sort
# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE
    /**
     * @file Bubble.hpp
     * @author Ramtin Kosari (
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
    class BubbleSort {
        public:
            /**
             * @brief Bubble Sort Constructor
             * @details This Constructor Initializes Bubble Sort Module
             */
            BubbleSort();
    };
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE