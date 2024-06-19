//-- Merge Sort
# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_MERGE
    /**
     * @file Merge.hpp
     * @author Ramtin Kosari ( ramtinkosari@gmail.com )
     * @brief Merge Sort Header File
     * @date 2024-06-14
     * @def ALGORITHMS_OMID_SOJOODI_SORTS_MERGE
     * @brief Merge Sort Header File Macro
     * @details This Header File Contains Merge Sort Algorithm
     */
    # define ALGORITHMS_OMID_SOJOODI_SORTS_MERGE
    //-- Include Configurations
    # ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
        # include "../../Configs.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_CONFIGS
    //-- Include Graphics Module
    # ifndef GRAPHICS_OMID_SOJOODI
        # include "../../Graphics.hpp"
    # endif // GRAPHICS_OMID_SOJOODI
    /**
     * @def MERGE_SORT_LABEL
     * @brief Merge Sort Log Message
     * @details This Macro Defines Merge Sort Log Message Label
     */
    # define MERGE_SORT_LABEL "\033[38;2;177;245;217m[MERGE SORT]\033[0m "
    /**
     * @enum ENUM_SUPPORTED_SORT_ORDERS
     * @brief Supported Sort Orders
     * @details This Enum Contains Supported Sort Orders for Merge Sort Algorithm
     * 
     * @param ASCENDING Ascending Sort Order
     * @param DESCENDING Descending Sort Order
     */
    enum ENUM_SUPPORTED_SORT_ORDERS_MERGE {
        MERGE_ASCENDING,
        MERGE_DESCENDING
    };
    /**
     * @enum ENUM_SUPPORTED_SORTING_METHODS_MERGE
     * @brief Supported Sorting Methods
     * @details This Enum Contains Supported Sorting Methods for Merge Sort Algorithm
     * 
     * @param MERGE_SORT_LEFT_TO_RIGHT Left to Right Sorting Method
     * @param MERGE_SORT_RIGHT_TO_LEFT Right to Left Sorting Method
     * @param MERGE_SORT_TOP_TO_BOTTOM Top to Bottom Sorting Method
     * @param MERGE_SORT_BOTTOM_TO_TOP Bottom to Top Sorting Method
     * @param MERGE_SORT_THETA Theta Sorting Method
     */
    enum ENUM_SUPPORTED_SORTING_METHODS_MERGE {
        MERGE_SORT_LEFT_TO_RIGHT,
        MERGE_SORT_RIGHT_TO_LEFT,
        MERGE_SORT_TOP_TO_BOTTOM,
        MERGE_SORT_BOTTOM_TO_TOP,
        MERGE_SORT_THETA
    };
    /**
     * @class MergeSort
     * @brief Merge Sort Class
     * @details This Class Contains Merge Sort Algorithm
     */
    class MergeSort {
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
            ENUM_SUPPORTED_SORT_ORDERS_MERGE order;
            /**
             * @brief Sorting Method
             * @details This Variable Contains Sorting Method
             */
            ENUM_SUPPORTED_SORTING_METHODS_MERGE method;
            /**
             * @brief Index
             * @details This Variable Contains Index and Used in Treshold Sorting Method Graphics
             */
            int index;
        public:
            /**
             * @brief Merge Sort Constructor
             * @details This Constructor Initializes Merge Sort Class
             */
            MergeSort();
            /**
             * @brief Merge Sort Destructor
             * @details This Destructor Finalizes Merge Sort Class
             */
            ~MergeSort();
            /**
             * @brief Merge Algorithm
             * @details This Function Mergs an Array
             * 
             * @param array Array to Sort
             * @param l Left Index
             * @param r Right Index
             * @param m Middle Index
             * @param graphics Graphics Object
             */
            void Merge(std::vector<env::Point2D> &array, int l, int m, int r, Graphics &  graphics);
            /**
             * @brief Sort Algorithm
             * @details This Function Sorts an Array
             * 
             * @param array Array to Sort
             * @param l Left Index
             * @param r Right Index
             * @param graphics Graphics Object
             */
            void Sort(std::vector<env::Point2D> &array, int l, int r, Graphics &  graphics);
            /**
             * @brief Merge Sort Algorithm
             * @details This Function Sorts an 2D Array (Points Array) Using Merge Sort Algorithm
             * 
             * @param array Array to Sort
             * @param size Size of Array
             * @param order Sort Order
             * @param graphics Graphics Object
             * @param method Sorting Method
             */
            std::vector<env::Point2D> getSorted2D(
                std::vector<env::Point2D> array,
                ENUM_SUPPORTED_SORT_ORDERS_MERGE order,
                bool use_graphics,
                Graphics &  graphics,
                ENUM_SUPPORTED_SORTING_METHODS_MERGE method = MERGE_SORT_THETA
            );
    };
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_MERGE