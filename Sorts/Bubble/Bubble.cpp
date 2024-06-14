# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE
    # include "Bubble.hpp"
    /**
     * @brief Bubble Sort Constructor
     * @details This Constructor Initializes Bubble Sort Module
     */
    BubbleSort::BubbleSort() {
        std::cout << MODULE BUBBLE_SORT_LABEL "Initialized" << std::endl;
    }
    /**
     * @brief Bubble Sort Destructor
     * @details This Destructor Deinitializes Bubble Sort Module
     */
    BubbleSort::~BubbleSort() {
        // std::cout << MODULE BUBBLE_SORT_LABEL "Deinitialized" << std::endl;
    }
    /**
     * @brief Bubble Sort Algorithm
     * @details This Function Contains Bubble Sort Algorithm
     * 
     * @param array Array to Sort
     * @param size Size of Array
     * @param order Sort Order
     * @param graphics Graphics Object
     * @param method Sorting Method
     */
    std::vector<env::Point2D> BubbleSort::getSorted2D(
        std::vector<env::Point2D> array,
        ENUM_SUPPORTED_SORT_ORDERS_BUBBLE order,
        bool use_graphics,
        Graphics &  graphics,
        ENUM_SUPPORTED_SORTING_METHODS method
    ) {
        //-- Handle Graphics
        if (use_graphics) {
            bool show_flag = false;
            int blue = 0, green = 0, red = 0;
            graphics.windows.main.matrix.copyTo(graphics.windows.temp1.matrix);
            //-- Handle Sort Methods
            if (method == BUBBLE_SORT_LEFT_TO_RIGHT) {
                std::cout << MODULE BUBBLE_SORT_LABEL "Sorting Left to Right" << std::endl;
                for (int i = 0; i < array.size(); i++) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    for (int j = 0; j < array.size() - i - 1; j++) {
                        //-- Handle Line Color
                        green = 254 * (j / double(array.size() - i - 1)) / 2 + 20;
                        blue = 254 * (j / double(array.size() - i - 1)) / 3 + 20;
                        red = 254 * (j / double(array.size() - i - 1)) / 5 + 20;
                        if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                        if (green > 254) green = 254; else if (green < 0) green = 50;
                        if (red > 254) red = 254; else if (red < 0) red = 50;
                        //-- Show
                        if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                            cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                            cv::waitKey(1);
                        }
                        if (order == BUBBLE_ASCENDING) {
                            if (array[j].x > array[j + 1].x) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        } else if (order == BUBBLE_DESCENDING) {
                            if (array[j].x < array[j + 1].x) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        }
                    }
                }
            } else if (method == BUBBLE_SORT_RIGHT_TO_LEFT) {
                std::cout << MODULE BUBBLE_SORT_LABEL "Sorting Right to Left" << std::endl;
                for (int i = 0; i < array.size(); i++) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    for (int j = 0; j < array.size() - i - 1; j++) {
                        //-- Handle Line Color
                        green = 254 * (j / double(array.size() - i - 1)) / 2 + 20;
                        blue = 254 * (j / double(array.size() - i - 1)) / 3 + 20;
                        red = 254 * (j / double(array.size() - i - 1)) / 5 + 20;
                        if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                        if (green > 254) green = 254; else if (green < 0) green = 50;
                        if (red > 254) red = 254; else if (red < 0) red = 50;
                        //-- Show
                        if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                            cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                            cv::waitKey(1);
                        }
                        if (order == BUBBLE_ASCENDING) {
                            if (array[j].x < array[j + 1].x) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        } else if (order == BUBBLE_DESCENDING) {
                            if (array[j].x > array[j + 1].x) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        }
                    }
                }
            } else if (method == BUBBLE_SORT_TOP_TO_BOTTOM) {
                std::cout << MODULE BUBBLE_SORT_LABEL "Sorting Top to Bottom" << std::endl;
                for (int i = 0; i < array.size(); i++) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    for (int j = 0; j < array.size() - i - 1; j++) {
                        //-- Handle Line Color
                        green = 254 * (j / double(array.size() - i - 1)) / 2 + 20;
                        blue = 254 * (j / double(array.size() - i - 1)) / 3 + 20;
                        red = 254 * (j / double(array.size() - i - 1)) / 5 + 20;
                        if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                        if (green > 254) green = 254; else if (green < 0) green = 50;
                        if (red > 254) red = 254; else if (red < 0) red = 50;
                        //-- Show
                        if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                            cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                            cv::waitKey(1);
                        }
                        if (order == BUBBLE_ASCENDING) {
                            if (array[j].y > array[j + 1].y) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        } else if (order == BUBBLE_DESCENDING) {
                            if (array[j].y < array[j + 1].y) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        }
                    }
                }
            } else if (method == BUBBLE_SORT_BOTTOM_TO_TOP) {
                std::cout << MODULE BUBBLE_SORT_LABEL "Sorting Bottom to Top" << std::endl;
                for (int i = 0; i < array.size(); i++) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    for (int j = 0; j < array.size() - i - 1; j++) {
                        //-- Handle Line Color
                        green = 254 * (j / double(array.size() - i - 1)) / 2 + 20;
                        blue = 254 * (j / double(array.size() - i - 1)) / 3 + 20;
                        red = 254 * (j / double(array.size() - i - 1)) / 5 + 20;
                        if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                        if (green > 254) green = 254; else if (green < 0) green = 50;
                        if (red > 254) red = 254; else if (red < 0) red = 50;
                        //-- Show
                        if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                            cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                            cv::waitKey(1);
                        }
                        if (order == BUBBLE_ASCENDING) {
                            if (array[j].y < array[j + 1].y) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        } else if (order == BUBBLE_DESCENDING) {
                            if (array[j].y > array[j + 1].y) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        }
                    }
                }
            } else if (method == BUBBLE_SORT_THETA) {
                //-- Sort Array According to each Points theta from Base Point's Theta
                for (int i = 0; i < array.size(); i++) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    for (int j = 0; j < array.size() - i - 1; j++) {
                        //-- Handle Line Color
                        green = 254 * (j / double(array.size() - i - 1)) / 2 + 20;
                        blue = 254 * (j / double(array.size() - i - 1)) / 3 + 20;
                        red = 254 * (j / double(array.size() - i - 1)) / 5 + 20;
                        if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                        if (green > 254) green = 254; else if (green < 0) green = 50;
                        if (red > 254) red = 254; else if (red < 0) red = 50;
                        //-- Show
                        if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                            cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                            cv::waitKey(1);
                        }
                        //-- Sort
                        if (order == BUBBLE_ASCENDING) {
                            if (array[j].theta > array[j + 1].theta) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        } else if (order == BUBBLE_DESCENDING) {
                            if (array[j].theta < array[j + 1].theta) {
                                env::Point2D temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 80, 0),
                                    1
                                );
                            } else {
                                cv::line(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[i].x, array[i].y),
                                    cv::Point(array[j].x, array[j].y),
                                    // cv::Scalar(30, 50, 10),
                                    cv::Scalar(blue, green, red),
                                    1
                                );
                                cv::circle(
                                    graphics.windows.temp2.matrix,
                                    cv::Point(array[j].x, array[j].y),
                                    5,
                                    cv::Scalar(0, 170, 0),
                                    1
                                );
                            }
                        }
                    }
                }
            }
            std::cout << MODULE BUBBLE_SORT_LABEL "Sorted 2D Array" << std::endl;
            cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
        } else {
            if (order == BUBBLE_ASCENDING) {
                //-- Sort Array According to each Points theta from Base Point's Theta
                for (int i = 0; i < array.size(); i++) {
                    for (int j = 0; j < array.size() - i - 1; j++) {
                        if (array[j].theta > array[j + 1].theta) {
                            env::Point2D temp = array[j];
                            array[j] = array[j + 1];
                            array[j + 1] = temp;
                        }
                    }
                }
            } else if (order == BUBBLE_DESCENDING) {
                //-- Sort Array According to each Points theta from Base Point's Theta
                for (int i = 0; i < array.size(); i++) {
                    for (int j = 0; j < array.size() - i - 1; j++) {
                        if (array[j].theta < array[j + 1].theta) {
                            env::Point2D temp = array[j];
                            array[j] = array[j + 1];
                            array[j + 1] = temp;
                        }
                    }
                }
            }
        }
        //-- Return Sorted Array
        return array;
    }
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_BUBBLE