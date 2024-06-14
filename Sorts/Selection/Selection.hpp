//-- Selection Sort
# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_SELECTION
    /**
     * @file Selection.hpp
     * @author Ramtin Kosari ( ramtinkosari@gmail.com )
     * @brief Selection Sort Header File
     * @date 2024-06-14
     * @def ALGORITHMS_OMID_SOJOODI_SORTS_SELECTION
     * @brief Selection Sort Header File Macro
     * @details This Header File Contains Selection Sort Algorithm
     */
    # define ALGORITHMS_OMID_SOJOODI_SORTS_SELECTION
    //-- Include Configurations
    # ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
        # include "../../Configs.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_CONFIGS
    //-- Include Graphics Module
    # ifndef GRAPHICS_OMID_SOJOODI
        # include "../../Graphics.hpp"
    # endif // GRAPHICS_OMID_SOJOODI
    /**
     * @def SELECTION_SORT_LABEL
     * @brief Selection Sort Log Message
     * @details This Macro Defines Selection Sort Log Message Label
     */
    # define SELECTION_SORT_LABEL "\033[38;2;177;245;217m[SELECTION SORT]\033[0m "
    /**
     * @enum ENUM_SUPPORTED_SORT_ORDERS
     * @brief Supported Sort Orders
     * @details This Enum Contains Supported Sort Orders for Selection Sort Algorithm
     * 
     * @param ASCENDING Ascending Sort Order
     * @param DESCENDING Descending Sort Order
     */
    enum ENUM_SUPPORTED_SORT_ORDERS_SELECTION {
        SELECTION_ASCENDING,
        SELECTION_DESCENDING
    };
    /**
     * @enum ENUM_SUPPORTED_SORTING_METHODS_SELECTION
     * @brief Supported Sorting Methods
     * @details This Enum Contains Supported Sorting Methods for Selection Sort Algorithm
     * 
     * @param SELECTION_SORT_LEFT_TO_RIGHT Left to Right Sorting Method
     * @param SELECTION_SORT_RIGHT_TO_LEFT Right to Left Sorting Method
     * @param SELECTION_SORT_TOP_TO_BOTTOM Top to Bottom Sorting Method
     * @param SELECTION_SORT_BOTTOM_TO_TOP Bottom to Top Sorting Method
     * @param SELECTION_SORT_THETA Theta Sorting Method
     */
    enum ENUM_SUPPORTED_SORTING_METHODS_SELECTION {
        SELECTION_SORT_LEFT_TO_RIGHT,
        SELECTION_SORT_RIGHT_TO_LEFT,
        SELECTION_SORT_TOP_TO_BOTTOM,
        SELECTION_SORT_BOTTOM_TO_TOP,
        SELECTION_SORT_THETA
    };
    /**
     * @class SelectionSort
     * @brief Selection Sort Class
     * @details This Class Contains Selection Sort Algorithm
     */
    class SelectionSort {
        public:
            /**
             * @brief Selection Sort Constructor
             * @details This Constructor Initializes Selection Sort Class
             */
            SelectionSort();
            /**
             * @brief Selection Sort Destructor
             * @details This Destructor Finalizes Selection Sort Class
             */
            ~SelectionSort();
            /**
             * @brief Selection Sort Algorithm
             * @details This Function Sorts an 2D Array (Points Array) Using Selection Sort Algorithm
             * 
             * @param array Array to Sort
             * @param size Size of Array
             * @param order Sort Order
             * @param graphics Graphics Object
             * @param method Sorting Method
             */
            std::vector<env::Point2D> getSorted2D(
                std::vector<env::Point2D> array,
                ENUM_SUPPORTED_SORT_ORDERS_SELECTION order,
                bool use_graphics,
                Graphics &  graphics,
                ENUM_SUPPORTED_SORTING_METHODS_SELECTION method = SELECTION_SORT_THETA
            );
    };
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_SELECTION