# ifndef ALGORITHMS_OMID_SOJOODI_SORTS_INSERTION
    # include "Insertion.hpp"
    /**
     * @brief Insertion Sort Constructor
     * @details This Constructor Initializes Insertion Sort Module
     */
    InsertionSort::InsertionSort() {
        std::cout << MODULE INSERTION_SORT_LABEL "Initialized" << std::endl;
    }
    /**
     * @brief Insertion Sort Destructor
     * @details This Destructor Deinitializes Insertion Sort Module
     */
    InsertionSort::~InsertionSort() {
        // std::cout << MODULE INSERTION_SORT_LABEL "Deinitialized" << std::endl;
    }
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
    std::vector<env::Point2D> InsertionSort::getSorted2D(
        std::vector<env::Point2D> array,
        ENUM_SUPPORTED_SORT_ORDERS_INSERTION order,
        bool use_graphics,
        Graphics &  graphics,
        ENUM_SUPPORTED_SORTING_METHODS_INSERTION method
    ) {
        //-- Handle Graphics
        if (use_graphics) {
            bool show_flag = false;
            int blue = 0, green = 0, red = 0;
            graphics.windows.main.matrix.copyTo(graphics.windows.temp1.matrix);
            //-- Handle Order
            if (order == INSERTION_ASCENDING) {
                //-- Handle Method
                if (method == INSERTION_SORT_LEFT_TO_RIGHT) {
                    //-- Sort Left to Right
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].x > key.x) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_RIGHT_TO_LEFT) {
                    //-- Sort Right to Left
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].x < key.x) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_TOP_TO_BOTTOM) {
                    //-- Sort Top to Bottom
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].y > key.y) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_BOTTOM_TO_TOP) {
                    //-- Sort Bottom to Top
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].y < key.y) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_THETA) {
                    //-- Sort Theta
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].theta > key.theta) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else {
                    std::cout << ERROR INSERTION_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else if (order == INSERTION_DESCENDING) {
                //-- Handle Method
                if (method == INSERTION_SORT_LEFT_TO_RIGHT) {
                    //-- Sort Left to Right
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].x < key.x) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_RIGHT_TO_LEFT) {
                    //-- Sort Right to Left
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].x > key.x) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_TOP_TO_BOTTOM) {
                    //-- Sort Top to Bottom
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].y < key.y) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_BOTTOM_TO_TOP) {
                    //-- Sort Bottom to Top
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].y > key.y) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_THETA) {
                    //-- Sort Theta
                    for (int i = 1; i < array.size(); i++) {
                        graphics.windows.temp1.matrix.copyTo(graphics.windows.temp2.matrix);
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].theta < key.theta) {
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
                            array[j + 1] = array[j];
                            cv::line(
                                graphics.windows.temp2.matrix,
                                cv::Point(array[i].x, array[i].y),
                                cv::Point(array[j].x, array[j].y),
                                // cv::Scalar(30, 50, 10),
                                cv::Scalar(blue, green, red),
                                1
                            );
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else {
                    std::cout << ERROR INSERTION_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else {
                std::cout << ERROR INSERTION_SORT_LABEL "Invalid Sorting Order" << std::endl;
            }
        } else {
            //-- Handle Order
            if (order == INSERTION_ASCENDING) {
                //-- Handle Method
                if (method == INSERTION_SORT_LEFT_TO_RIGHT) {
                    //-- Sort Left to Right
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].x > key.x) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_RIGHT_TO_LEFT) {
                    //-- Sort Right to Left
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].x < key.x) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_TOP_TO_BOTTOM) {
                    //-- Sort Top to Bottom
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].y > key.y) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_BOTTOM_TO_TOP) {
                    //-- Sort Bottom to Top
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].y < key.y) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_THETA) {
                    //-- Sort Theta
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].theta > key.theta) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else {
                    std::cout << ERROR INSERTION_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else if (order == INSERTION_DESCENDING) {
                //-- Handle Method
                if (method == INSERTION_SORT_LEFT_TO_RIGHT) {
                    //-- Sort Left to Right
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].x < key.x) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_RIGHT_TO_LEFT) {
                    //-- Sort Right to Left
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].x > key.x) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_TOP_TO_BOTTOM) {
                    //-- Sort Top to Bottom
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].y < key.y) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_BOTTOM_TO_TOP) {
                    //-- Sort Bottom to Top
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].y > key.y) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else if (method == INSERTION_SORT_THETA) {
                    //-- Sort Theta
                    for (int i = 1; i < array.size(); i++) {
                        env::Point2D key = array[i];
                        int j = i - 1;
                        while (j >= 0 && array[j].theta < key.theta) {
                            array[j + 1] = array[j];
                            j = j - 1;
                        }
                        array[j + 1] = key;
                    }
                } else {
                    std::cout << ERROR INSERTION_SORT_LABEL "Invalid Sorting Method" << std::endl;
                }
            } else {
                std::cout << ERROR INSERTION_SORT_LABEL "Invalid Sorting Order" << std::endl;
            }
        }
        //-- Return Sorted Array
        return array;
    }
# endif // ALGORITHMS_OMID_SOJOODI_SORTS_INSERTION