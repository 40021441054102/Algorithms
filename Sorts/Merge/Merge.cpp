# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_MERGE
    # include "Merge.hpp"
    /**
     * @brief Merge Sort Constructor
     * @details This Constructor Initializes Merge Sort Module
     */
    MergeSort::MergeSort() {
        std::cout << MODULE MERGE_SORT_LABEL "Initialized" << std::endl;
    }
    /**
     * @brief Merge Sort Destructor
     * @details This Destructor Deinitializes Merge Sort Module
     */
    MergeSort::~MergeSort() {
        // std::cout << MODULE MERGE_SORT_LABEL "Deinitialized Successfully" << std::endl;
    }
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
    void MergeSort::Merge(std::vector<env::Point2D> &array, int l, int m, int r, Graphics &  graphics) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        std::vector<env::Point2D> L(n1), R(n2);
        for (i = 0; i < n1; i++) {
            L[i] = array[l + i];
        }
        for (j = 0; j < n2; j++) {
            R[j] = array[m + 1 + j];
        }
        i = 0;
        j = 0;
        k = l;
        //-- Handle Graphics
        if (use_graphics) {
            //-- Handle Order
            if (order == MERGE_ASCENDING) {
                //-- Handle Method
                if (method == MERGE_SORT_LEFT_TO_RIGHT) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].x <= R[j].x) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else if (method == MERGE_SORT_RIGHT_TO_LEFT) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].x >= R[j].x) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else if (method == MERGE_SORT_TOP_TO_BOTTOM) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].y <= R[j].y) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else if (method == MERGE_SORT_BOTTOM_TO_TOP) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].y >= R[j].y) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else if (method == MERGE_SORT_THETA) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].theta <= R[j].theta) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else {
                    std::cout << ERROR MERGE_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else if (order == MERGE_DESCENDING) {
                //-- Handle Method
                if (method == MERGE_SORT_LEFT_TO_RIGHT) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].x >= R[j].x) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else if (method == MERGE_SORT_RIGHT_TO_LEFT) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].x <= R[j].x) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else if (method == MERGE_SORT_TOP_TO_BOTTOM) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].y >= R[j].y) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else if (method == MERGE_SORT_BOTTOM_TO_TOP) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].y <= R[j].y) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else if (method == MERGE_SORT_THETA) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    while (i < n1 && j < n2) {
                        if (L[i].theta >= R[j].theta) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                        cv::line(
                            graphics.windows.temp2.matrix,
                            cv::Point(
                                array[k].x,
                                array[k].y
                            ),
                            cv::Point(
                                array[k - 1].x,
                                array[k - 1].y
                            ),
                            cv::Scalar(240, 120, 40),
                            1
                        );
                    }
                } else {
                    std::cout << ERROR MERGE_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else {
                std::cout << ERROR MERGE_SORT_LABEL "Invalid Sort Order" << std::endl;
            }
        } else {
            //-- Handle Order
            if (order == MERGE_ASCENDING) {
                //-- Handle Method
                if (method == MERGE_SORT_LEFT_TO_RIGHT) {
                    while (i < n1 && j < n2) {
                        if (L[i].x <= R[j].x) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else if (method == MERGE_SORT_RIGHT_TO_LEFT) {
                    while (i < n1 && j < n2) {
                        if (L[i].x >= R[j].x) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else if (method == MERGE_SORT_TOP_TO_BOTTOM) {
                    while (i < n1 && j < n2) {
                        if (L[i].y <= R[j].y) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else if (method == MERGE_SORT_BOTTOM_TO_TOP) {
                    while (i < n1 && j < n2) {
                        if (L[i].y >= R[j].y) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else if (method == MERGE_SORT_THETA) {
                    while (i < n1 && j < n2) {
                        if (L[i].theta <= R[j].theta) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else {
                    std::cout << ERROR MERGE_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else if (order == MERGE_DESCENDING) {
                //-- Handle Method
                if (method == MERGE_SORT_LEFT_TO_RIGHT) {
                    while (i < n1 && j < n2) {
                        if (L[i].x >= R[j].x) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else if (method == MERGE_SORT_RIGHT_TO_LEFT) {
                    while (i < n1 && j < n2) {
                        if (L[i].x <= R[j].x) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else if (method == MERGE_SORT_TOP_TO_BOTTOM) {
                    while (i < n1 && j < n2) {
                        if (L[i].y >= R[j].y) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else if (method == MERGE_SORT_BOTTOM_TO_TOP) {
                    while (i < n1 && j < n2) {
                        if (L[i].y <= R[j].y) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else if (method == MERGE_SORT_THETA) {
                    while (i < n1 && j < n2) {
                        if (L[i].theta >= R[j].theta) {
                            array[k] = L[i];
                            i++;
                        } else {
                            array[k] = R[j];
                            j++;
                        }
                        k++;
                    }
                } else {
                    std::cout << ERROR MERGE_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else {
                std::cout << ERROR MERGE_SORT_LABEL "Invalid Sort Order" << std::endl;
            }
        }
        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }
    }
    /**
     * @brief Merge Sort Algorithm
     * @details This Function Sorts an Array Using Merge Sort Algorithm
     * 
     * @param array Array to Sort
     * @param l Left Index
     * @param r Right Index
     * @param graphics Graphics Object
     */
    void MergeSort::Sort(std::vector<env::Point2D> &array, int l, int r, Graphics &  graphics) {
        if (l < r) {
            int m = l + (r - l) / 2;
            Sort(array, l, m, graphics);
            Sort(array, m + 1, r, graphics);
            Merge(array, l, m, r, graphics);
            index++;
            if (use_graphics) {
                //-- Show Treshold
                if (index % 10 == 0) {
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                }
            }
        }
    }
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
    std::vector<env::Point2D> MergeSort::getSorted2D(
        std::vector<env::Point2D> array,
        ENUM_SUPPORTED_SORT_ORDERS_MERGE order,
        bool use_graphics,
        Graphics &  graphics,
        ENUM_SUPPORTED_SORTING_METHODS_MERGE method
    ) {
        //-- Set Graphics
        this->use_graphics = use_graphics;
        //-- Set Method
        this->method = method;
        //-- Set Order
        this->order = order;
        //-- Set Index
        this->index = 0;
        //-- Handle Graphics
        if (use_graphics) {
            graphics.windows.main.matrix.copyTo(graphics.windows.temp1.matrix);
        }
        //-- Sort Array
        Sort(array, 0, array.size() - 1, graphics);
        //-- Return Sorted Array
        return array;
    }
    
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_MERGE