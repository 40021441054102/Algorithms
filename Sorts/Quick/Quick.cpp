# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_QUICK
    # include "Quick.hpp"
    /**
     * @brief Quick Sort Constructor
     * @details This Constructor Initializes Quick Sort Module
     */
    QuickSort::QuickSort() {
        std::cout << MODULE QUICK_SORT_LABEL "Initialized" << std::endl;
    }
    /**
     * @brief Quick Sort Destructor
     * @details This Destructor Deinitializes Quick Sort Module
     */
    QuickSort::~QuickSort() {
        // std::cout << MODULE QUICK_SORT_LABEL "Deinitialized Successfully" << std::endl;
    }
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
    int QuickSort::partition(std::vector<env::Point2D> &array, int low, int high, Graphics &  graphics) {
        //-- Handle Graphics
        if (use_graphics) {
            //-- Handle Order
            if (order == QUICK_ASCENDING) {
                //-- Handle Method
                if (method == QUICK_SORT_LEFT_TO_RIGHT) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    int pivot = array[high].x;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].x < pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else if (method == QUICK_SORT_RIGHT_TO_LEFT) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    int pivot = array[high].x;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].x > pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else if (method == QUICK_SORT_TOP_TO_BOTTOM) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    int pivot = array[high].y;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].y < pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else if (method == QUICK_SORT_BOTTOM_TO_TOP) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    int pivot = array[high].y;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].y > pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else if (method == QUICK_SORT_THETA) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    double pivot = array[high].theta;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].theta < pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else {
                    std::cout << ERROR QUICK_SORT_LABEL "Invalid Sorting Method" << std::endl;
                    return -1;
                }
            } else if (order == QUICK_DESCENDING) {
                //-- Handle Method
                if (method == QUICK_SORT_LEFT_TO_RIGHT) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    int pivot = array[high].x;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].x > pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else if (method == QUICK_SORT_RIGHT_TO_LEFT) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    int pivot = array[high].x;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].x < pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else if (method == QUICK_SORT_TOP_TO_BOTTOM) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    int pivot = array[high].y;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].y > pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else if (method == QUICK_SORT_BOTTOM_TO_TOP) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    int pivot = array[high].y;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].y < pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else if (method == QUICK_SORT_THETA) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    double pivot = array[high].theta;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        5,
                        cv::Scalar(0, 255, 255),
                        1
                    );
                    int i = low - 1;
                    cv::circle(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[i].x, array[i].y),
                        5,
                        cv::Scalar(0, 120, 255),
                        1
                    );
                    cv::line(
                        graphics.windows.temp2.matrix,
                        cv::Point(array[high].x, array[high].y),
                        cv::Point(array[low].x, array[low].y),
                        cv::Scalar(0, 120, 120),
                        1
                    );
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].theta > pivot) {
                            if (i != low - 1) {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Scalar(120, 200, 0),
                                    1
                                );
                            }
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                    cv::waitKey(1);
                    return i + 1;
                } else {
                    std::cout << ERROR QUICK_SORT_LABEL "Invalid Sorting Method" << std::endl;
                    return -1;
                }
            } else {
                std::cout << ERROR QUICK_SORT_LABEL "Invalid Sort Order" << std::endl;
                return -1;
            }
        } else {
            //-- Handle Order
            if (order == QUICK_ASCENDING) {
                //-- Handle Method
                if (method == QUICK_SORT_LEFT_TO_RIGHT) {
                    int pivot = array[high].x;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].x < pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else if (method == QUICK_SORT_RIGHT_TO_LEFT) {
                    int pivot = array[high].x;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].x > pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else if (method == QUICK_SORT_TOP_TO_BOTTOM) {
                    int pivot = array[high].y;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].y < pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else if (method == QUICK_SORT_BOTTOM_TO_TOP) {
                    int pivot = array[high].y;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].y > pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else if (method == QUICK_SORT_THETA) {
                    double pivot = array[high].theta;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].theta < pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else {
                    std::cout << ERROR QUICK_SORT_LABEL "Invalid Sorting Method" << std::endl;
                    return -1;
                }
            } else if (order == QUICK_DESCENDING) {
                //-- Handle Method
                if (method == QUICK_SORT_LEFT_TO_RIGHT) {
                    int pivot = array[high].x;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].x > pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else if (method == QUICK_SORT_RIGHT_TO_LEFT) {
                    int pivot = array[high].x;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].x < pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else if (method == QUICK_SORT_TOP_TO_BOTTOM) {
                    int pivot = array[high].y;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].y > pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else if (method == QUICK_SORT_BOTTOM_TO_TOP) {
                    int pivot = array[high].y;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].y < pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else if (method == QUICK_SORT_THETA) {
                    double pivot = array[high].theta;
                    int i = low - 1;
                    for (int j = low; j <= high - 1; j++) {
                        if (array[j].theta > pivot) {
                            i++;
                            std::swap(array[i], array[j]);
                        }
                    }
                    std::swap(array[i + 1], array[high]);
                    return i + 1;
                } else {
                    std::cout << ERROR QUICK_SORT_LABEL "Invalid Sorting Method" << std::endl;
                    return -1;
                }
            } else {
                std::cout << ERROR QUICK_SORT_LABEL "Invalid Sort Order" << std::endl;
                return -1;
            }
        }
    }
    /**
     * @brief Quick Sort Algorithm
     * @details This Function Sorts an Array Using Quick Sort Algorithm
     * 
     * @param array Array to Sort
     * @param low Low Index
     * @param high High Index
     * @param graphics Graphics Object
     */
    void QuickSort::Sort(std::vector<env::Point2D> &array, int low, int high, Graphics &  graphics) {
        if (low < high) {
            int pi = partition(array, low, high, graphics);
            cv::circle(
                graphics.windows.temp1.matrix,
                cv::Point(array[pi].x, array[pi].y),
                5,
                cv::Scalar(0, 255, 0),
                1
            );
            Sort(array, low, pi - 1, graphics);
            Sort(array, pi + 1, high, graphics);
        }
    }
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
    std::vector<env::Point2D> QuickSort::getSorted2D(
        std::vector<env::Point2D> array,
        ENUM_SUPPORTED_SORT_ORDERS_QUICK order,
        bool use_graphics,
        Graphics &  graphics,
        ENUM_SUPPORTED_SORTING_METHODS_QUICK method
    ) {
        //-- Set Graphics
        this->use_graphics = use_graphics;
        //-- Set Order
        this->order = order;
        //-- Set Method
        this->method = method;
        //-- Handle Graphics
        if (use_graphics) {
            graphics.windows.main.matrix.copyTo(graphics.windows.temp1.matrix);
        }
        //-- Sort Array
        Sort(array, 0, array.size() - 1, graphics);
        //-- Return Sorted Array
        return array;
    }
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_QUICK