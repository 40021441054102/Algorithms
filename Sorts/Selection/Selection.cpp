# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_SELECTION
    # include "Selection.hpp"
    /**
     * @brief Selection Sort Constructor
     * @details This Constructor Initializes Selection Sort Module
     */
    SelectionSort::SelectionSort() {
        std::cout << MODULE SELECTION_SORT_LABEL "Initialized" << std::endl;
    }
    /**
     * @brief Selection Sort Destructor
     * @details This Destructor Deinitializes Selection Sort Module
     */
    SelectionSort::~SelectionSort() {
        // std::cout << MODULE SELECTION_SORT_LABEL "Deinitialized" << std::endl;
    }
    /**
     * @brief Selection Sort Algorithm
     * @details This Function Contains Selection Sort Algorithm
     * 
     * @param array Array to Sort
     * @param size Size of Array
     * @param order Sort Order
     * @param graphics Graphics Object
     * @param method Sorting Method
     */
    std::vector<env::Point2D> SelectionSort::getSorted2D(
        std::vector<env::Point2D> array,
        ENUM_SUPPORTED_SORT_ORDERS_SELECTION order,
        bool use_graphics,
        Graphics &  graphics,
        ENUM_SUPPORTED_SORTING_METHODS_SELECTION method
    ) {
        //-- Handle Graphics
        if (use_graphics) {
            bool show_flag = false;
            int blue = 0, green = 0, red = 0;
            graphics.windows.main.matrix.copyTo(graphics.windows.temp1.matrix);
            //-- Handle Order
            if (order == SELECTION_ASCENDING) {
                //-- Handle Method
                if (method == SELECTION_SORT_LEFT_TO_RIGHT) {
                    std::cout << MODULE SELECTION_SORT_LABEL "Sorting Left to Right" << std::endl;
                    for (int i = 0; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int min = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].x < array[min].x) {
                                min = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else if (method == SELECTION_SORT_RIGHT_TO_LEFT) {
                    for (int i = array.size() - 1; i >= 0; i--) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int min = i;
                        for (int j = i - 1; j >= 0; j--) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].x < array[min].x) {
                                min = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else if (method == SELECTION_SORT_TOP_TO_BOTTOM) {
                    for (int i = 0; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int min = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].y < array[min].y) {
                                min = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else if (method == SELECTION_SORT_BOTTOM_TO_TOP) {
                    graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                    for (int i = array.size() - 1; i >= 0; i--) {
                        int min = i;
                        for (int j = i - 1; j >= 0; j--) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].y < array[min].y) {
                                min = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else if (method == SELECTION_SORT_THETA) {
                    for (int i = 0; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int min = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].theta < array[min].theta) {
                                min = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else {
                    std::cout << ERROR SELECTION_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else if (order == SELECTION_DESCENDING) {
                //-- Handle Method
                if (method == SELECTION_SORT_LEFT_TO_RIGHT) {
                    for (int i = 0; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int max = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].x > array[max].x) {
                                max = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else if (method == SELECTION_SORT_RIGHT_TO_LEFT) {
                    for (int i = array.size() - 1; i >= 0; i--) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int max = i;
                        for (int j = i - 1; j >= 0; j--) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].x > array[max].x) {
                                max = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else if (method == SELECTION_SORT_TOP_TO_BOTTOM) {
                    for (int i = 0; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int max = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].y > array[max].y) {
                                max = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else if (method == SELECTION_SORT_BOTTOM_TO_TOP) {
                    for (int i = array.size() - 1; i >= 0; i--) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int max = i;
                        for (int j = i - 1; j >= 0; j--) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].y > array[max].y) {
                                max = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else if (method == SELECTION_SORT_THETA) {
                    for (int i = 0; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        int max = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            //-- Handle Line Color
                            green = 254 * (j / double(array.size() - i - 1)) / 2 + 10;
                            blue = 254 * (j / double(array.size() - i - 1)) / 3 + 10;
                            red = 254 * (j / double(array.size() - i - 1)) / 5 + 10;
                            if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                            if (green > 254) green = 254; else if (green < 0) green = 50;
                            if (red > 254) red = 254; else if (red < 0) red = 50;
                            //-- Show
                            if (i % (array.size() / 80) == 0 && j % (array.size() / 20) == 0) {
                                cv::imshow(WINDOW_NAME, graphics.windows.temp2.matrix);
                                cv::waitKey(1);
                            }
                            if (array[j].theta > array[max].theta) {
                                max = j;
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
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else {
                    std::cout << ERROR SELECTION_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else {
                std::cout << ERROR SELECTION_SORT_LABEL "Invalid Sorting Order" << std::endl;
            }
        } else {
            //-- Handle Order
            if (order == SELECTION_ASCENDING) {
                //-- Handle Method
                if (method == SELECTION_SORT_LEFT_TO_RIGHT) {
                    for (int i = 0; i < array.size(); i++) {
                        int min = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            if (array[j].x < array[min].x) {
                                min = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else if (method == SELECTION_SORT_RIGHT_TO_LEFT) {
                    for (int i = array.size() - 1; i >= 0; i--) {
                        int min = i;
                        for (int j = i - 1; j >= 0; j--) {
                            if (array[j].x < array[min].x) {
                                min = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else if (method == SELECTION_SORT_TOP_TO_BOTTOM) {
                    for (int i = 0; i < array.size(); i++) {
                        int min = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            if (array[j].y < array[min].y) {
                                min = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else if (method == SELECTION_SORT_BOTTOM_TO_TOP) {
                    for (int i = array.size() - 1; i >= 0; i--) {
                        int min = i;
                        for (int j = i - 1; j >= 0; j--) {
                            if (array[j].y < array[min].y) {
                                min = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else if (method == SELECTION_SORT_THETA) {
                    for (int i = 0; i < array.size(); i++) {
                        int min = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            if (array[j].theta < array[min].theta) {
                                min = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[min];
                        array[min] = temp;
                    }
                } else {
                    std::cout << ERROR SELECTION_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else if (order == SELECTION_DESCENDING) {
                //-- Handle Method
                if (method == SELECTION_SORT_LEFT_TO_RIGHT) {
                    for (int i = 0; i < array.size(); i++) {
                        int max = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            if (array[j].x > array[max].x) {
                                max = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else if (method == SELECTION_SORT_RIGHT_TO_LEFT) {
                    for (int i = array.size() - 1; i >= 0; i--) {
                        int max = i;
                        for (int j = i - 1; j >= 0; j--) {
                            if (array[j].x > array[max].x) {
                                max = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else if (method == SELECTION_SORT_TOP_TO_BOTTOM) {
                    for (int i = 0; i < array.size(); i++) {
                        int max = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            if (array[j].y > array[max].y) {
                                max = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else if (method == SELECTION_SORT_BOTTOM_TO_TOP) {
                    for (int i = array.size() - 1; i >= 0; i--) {
                        int max = i;
                        for (int j = i - 1; j >= 0; j--) {
                            if (array[j].y > array[max].y) {
                                max = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else if (method == SELECTION_SORT_THETA) {
                    for (int i = 0; i < array.size(); i++) {
                        int max = i;
                        for (int j = i + 1; j < array.size(); j++) {
                            if (array[j].theta > array[max].theta) {
                                max = j;
                            }
                        }
                        env::Point2D temp = array[i];
                        array[i] = array[max];
                        array[max] = temp;
                    }
                } else {
                    std::cout << ERROR SELECTION_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else {
                std::cout << ERROR SELECTION_SORT_LABEL "Invalid Sorting Order" << std::endl;
            }
        }
        //-- Return Sorted Array
        return array;
    }
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_SELECTION