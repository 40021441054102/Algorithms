//-- Quick Sort
# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_QUICK
    /**
     * @file Quick.hpp
     * @author Ramtin Kosari ( ramtinkosari@gmail.com )
     * @brief Quick Sort Header File
     * @date 2024-06-14
     * @def ALGORITHMS_OMID_SOJOODI_SORTS_QUICK
     * @brief Quick Sort Header File Macro
     * @details This Header File Contains Quick Sort Algorithm
     */
    # define ALGORITHMS_OMID_SOJOODI_SORTS_QUICK
    //-- Include Configurations
    # ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
        # include "../../Configs.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_CONFIGS
    //-- Include Graphics Module
    # ifndef GRAPHICS_OMID_SOJOODI
        # include "../../Graphics.hpp"
    # endif // GRAPHICS_OMID_SOJOODI
    /**
     * @def QUICK_SORT_LABEL
     * @brief Quick Sort Log Message
     * @details This Macro Defines Quick Sort Log Message Label
     */
    # define QUICK_SORT_LABEL "\033[38;2;177;245;217m[QUICK SORT]\033[0m "
    /**
     * @enum ENUM_SUPPORTED_SORT_ORDERS
     * @brief Supported Sort Orders
     * @details This Enum Contains Supported Sort Orders for Quick Sort Algorithm
     * 
     * @param ASCENDING Ascending Sort Order
     * @param DESCENDING Descending Sort Order
     */
    enum ENUM_SUPPORTED_SORT_ORDERS_QUICK {
        QUICK_ASCENDING,
        QUICK_DESCENDING
    };
    /**
     * @enum ENUM_SUPPORTED_SORTING_METHODS_QUICK
     * @brief Supported Sorting Methods
     * @details This Enum Contains Supported Sorting Methods for Quick Sort Algorithm
     * 
     * @param QUICK_SORT_LEFT_TO_RIGHT Left to Right Sorting Method
     * @param QUICK_SORT_RIGHT_TO_LEFT Right to Left Sorting Method
     * @param QUICK_SORT_TOP_TO_BOTTOM Top to Bottom Sorting Method
     * @param QUICK_SORT_BOTTOM_TO_TOP Bottom to Top Sorting Method
     * @param QUICK_SORT_THETA Theta Sorting Method
     */
    enum ENUM_SUPPORTED_SORTING_METHODS_QUICK {
        QUICK_SORT_LEFT_TO_RIGHT,
        QUICK_SORT_RIGHT_TO_LEFT,
        QUICK_SORT_TOP_TO_BOTTOM,
        QUICK_SORT_BOTTOM_TO_TOP,
        QUICK_SORT_THETA
    };
    /**
     * @class QuickSort
     * @brief Quick Sort Class
     * @details This Class Contains Quick Sort Algorithm
     */
    class QuickSort {
        private:
            /**
             * @brief Use Graphics Flag
             * @details This Flag Indicates if Graphics is Enabled
             */
            bool use_graphics;
            /**
             * @brief Sort Order
             * @details This Variable Contains Sort Order
             */
            ENUM_SUPPORTED_SORT_ORDERS_QUICK order;
            /**
             * @brief Sorting Method
             * @details This Variable Contains Sorting Method
             */
            ENUM_SUPPORTED_SORTING_METHODS_QUICK method;
        public:
            /**
             * @brief Quick Sort Constructor
             * @details This Constructor Initializes Quick Sort Class
             */
            QuickSort();
            /**
             * @brief Quick Sort Destructor
             * @details This Destructor Finalizes Quick Sort Class
             */
            ~QuickSort();
            /**
             * @brief Partition Algorithm
             * @details This Function Partitions an Array
             * 
             * @param array Array to Sort
             * @param low Low Index
             * @param high High Index
             * @param i Index
             * @param j Index
             * @param graphics Graphics Object
             */
            int partition(std::vector<env::Point2D> &array, int low, int high, Graphics &  graphics);
            /**
             * @brief Quick Sort Algorithm
             * @details This Function Sorts an Array Using Quick Sort Algorithm
             * 
             * @param array Array to Sort
             * @param low Low Index
             * @param high High Index
             * @param graphics Graphics Object
             */
            void Sort(std::vector<env::Point2D> &array, int low, int high, Graphics &  graphics);
            /**
             * @brief Quick Sort Algorithm
             * @details This Function Sorts an 2D Array (Points Array) Using Quick Sort Algorithm
             * 
             * @param array Array to Sort
             * @param size Size of Array
             * @param order Sort Order
             * @param graphics Graphics Object
             * @param method Sorting Method
             */
            std::vector<env::Point2D> getSorted2D(
                std::vector<env::Point2D> array,
                ENUM_SUPPORTED_SORT_ORDERS_QUICK order,
                bool use_graphics,
                Graphics &  graphics,
                ENUM_SUPPORTED_SORTING_METHODS_QUICK method = QUICK_SORT_THETA
            );
    };
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_QUICK