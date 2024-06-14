# ifndef ALGORITHMS_OMID_SOJOODI
    # include "Algorithms.hpp"
    /**
     * @brief Algorithms Constructor
     * @details This Constructor Initializes the Algorithm with the Given Parameters.
     * 
     * @param algorithm The Algorithm to Use
     * @param environment The Environment to Use
     * @param dataMethod The Data Method to Use
     * @param processingMethod The Processing Method to Use
     * 
     * @see ENUM_SUPPORTED_ALGORITHMS               (\ref Algorithms.hpp "Algorithm" Supported by the Class)
     * @see ENUM_ALGORITHM_ENVIRONMENT              (\ref Graphics.hpp "Graphics" Environment)
     * @see ENUM_ALGORITHMS_DATA_METHOD             (\ref Algorithms.hpp "Algorithm" Data Generation Methods)
     * @see ENUM_ALGORIHTMS_PROCESSING_METHODS      (\ref Algorithms.hpp "Algorithm" Processing Methods)
     */
    Algorithms::Algorithms(
        ENUM_SUPPORTED_ALGORITHMS algorithm,
        ENUM_ALGORITHM_ENVIRONMENT environment,
        ENUM_ALGORITHMS_DATA_METHOD dataMethod = USE_RANDOM_DATA,
        ENUM_ALGORIHTMS_PROCESSING_METHODS processingMethod = USE_SINGLE_THREAD
    ) {
        std::cout << MODULE ALGORITHMS_LABEL "Initialized" << std::endl;
        //-- Initialize Algorithm
        switch (algorithm) {
            //-- Bubble Sort
            case ALGORITHM_SORT_BUBBLE: {
                //-- Generate Random Data
                if (dataMethod == USE_RANDOM_DATA) {
                    generateRandomData(
                        MAX_RANDOM_DATA,
                        int(WINDOW_WIDTH * 0.1),
                        int(WINDOW_WIDTH * 0.9),
                        environment,
                        RANDOM_DATA_SHAPE_DELTOID,
                        CALCULATE_DATA_THETA_MIDDLE
                    );
                } else if (dataMethod == USE_INPUT_FILE) {
                    std::cout << TAB ERROR "Loading Data from Input File Method Not Yet Implemented" << std::endl;
                } else {
                    std::cout << TAB ERROR "Data Method Not Supported" << std::endl;
                }
                //-- Sort with Visualization
                std::vector<env::Point2D> sorted_array;
                sorted_array = sorts.bubble.getSorted2D(
                    graphics.points2D,
                    BUBBLE_ASCENDING,
                    true,
                    graphics,
                    BUBBLE_SORT_THETA
                );
                //-- Starting Time
                begin_time = std::chrono::high_resolution_clock::now();
                //-- Sort
                sorts.bubble.getSorted2D(
                    graphics.points2D,
                    BUBBLE_ASCENDING,
                    false,
                    graphics
                );
                //-- Ending Time
                end_time = std::chrono::high_resolution_clock::now();
                algorithm_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
                std::cout << MODULE "Algorithm Process Time: " << algorithm_duration.count() << "s" << RESET << std::endl;
                //-- Show Sorted Array
                int red, green, blue;
                for (int i = 0; i < sorted_array.size() - 1; i++) {
                    if (i % SHOW_FRAME_THRESHOLD == 0) {
                        cv::imshow(WINDOW_NAME, graphics.windows.main.matrix);
                        cv::waitKey(1);
                    }
                    //-- Handle Line Color
                    green = 254 * (i / double(sorted_array.size())) / 3 + 20;
                    blue = 254 * (i / double(sorted_array.size())) / 2 + 20;
                    red = 254 * (i / double(sorted_array.size())) / 5 + 20;
                    if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                    if (green > 254) green = 254; else if (green < 0) green = 50;
                    if (red > 254) red = 254; else if (red < 0) red = 50;
                    cv::line(
                        graphics.windows.main.matrix,
                        cv::Point(sorted_array[i].x, sorted_array[i].y),
                        cv::Point(sorted_array[i + 1].x, sorted_array[i + 1].y),
                        cv::Scalar(blue, green, red),
                        1,
                        cv::LINE_AA
                    );
                }
                cv::imshow(WINDOW_NAME, graphics.windows.main.matrix);
                cv::waitKey(1);
                break;
            }
            //-- Selection Sort
            case ALGORITHM_SORT_SELECTION: {
                //-- Generate Random Data
                if (dataMethod == USE_RANDOM_DATA) {
                    generateRandomData(
                        MAX_RANDOM_DATA,
                        int(WINDOW_WIDTH * 0.1),
                        int(WINDOW_WIDTH * 0.9),
                        environment,
                        RANDOM_DATA_SHAPE_SPIRAL,
                        CALCULATE_DATA_THETA_MIDDLE
                    );
                } else if (dataMethod == USE_INPUT_FILE) {
                    std::cout << TAB ERROR "Loading Data from Input File Method Not Yet Implemented" << std::endl;
                } else {
                    std::cout << TAB ERROR "Data Method Not Supported" << std::endl;
                }
                //-- Sort with Visualization
                std::vector<env::Point2D> sorted_array;
                sorted_array = sorts.selection.getSorted2D(
                    graphics.points2D,
                    SELECTION_ASCENDING,
                    true,
                    graphics,
                    SELECTION_SORT_THETA
                );
                //-- Starting Time
                begin_time = std::chrono::high_resolution_clock::now();
                //-- Sort
                sorts.selection.getSorted2D(
                    graphics.points2D,
                    SELECTION_ASCENDING,
                    false,
                    graphics
                );
                //-- Ending Time
                end_time = std::chrono::high_resolution_clock::now();
                algorithm_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - begin_time);
                std::cout << MODULE "Algorithm Process Time: " << algorithm_duration.count() << "s" << RESET << std::endl;
                //-- Show Sorted Array
                int red, green, blue;
                for (int i = 0; i < sorted_array.size() - 1; i++) {
                    if (i % SHOW_FRAME_THRESHOLD == 0) {
                        cv::imshow(WINDOW_NAME, graphics.windows.main.matrix);
                        cv::waitKey(1);
                    }
                    //-- Handle Line Color
                    green = 254 * (i / double(sorted_array.size())) / 3 + 20;
                    blue = 254 * (i / double(sorted_array.size())) / 2 + 20;
                    red = 254 * (i / double(sorted_array.size())) / 5 + 20;
                    if (blue > 254) blue = 254; else if (blue < 0) blue = 50;
                    if (green > 254) green = 254; else if (green < 0) green = 50;
                    if (red > 254) red = 254; else if (red < 0) red = 50;
                    cv::line(
                        graphics.windows.main.matrix,
                        cv::Point(sorted_array[i].x, sorted_array[i].y),
                        cv::Point(sorted_array[i + 1].x, sorted_array[i + 1].y),
                        cv::Scalar(blue, green, red),
                        1,
                        cv::LINE_AA
                    );
                }
                cv::imshow(WINDOW_NAME, graphics.windows.main.matrix);
                cv::waitKey(0);
                break;
            }
        }
    }
    /**
     * @brief Algorithms Destructor
     * @details This Destructor Finalizes the Algorithm and Shows the Processing Time.
     */
    Algorithms::~Algorithms() {
        end_time = std::chrono::high_resolution_clock::now();
        algorithm_duration = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - begin_time);
        std::cout << LOG "Algorithm Process Time: " << algorithm_duration.count() << "s" << RESET << std::endl;
    }
    /**
     * @brief Generate Random Data
     * @details This Method Generates Random Data for the Algorithm.
     * 
     * @param amount The Amount of Data to Generate
     * @param min The Minimum Value of Data
     * @param max The Maximum Value of Data
     */
    void Algorithms::generateRandomData(
        int amount,
        int min,
        int max,
        ENUM_ALGORITHM_ENVIRONMENT environment,
        ENUM_RANDOM_DATA_SHAPES shape,
        ENUM_CALCULATE_DATA_THETA calc_theta
    ) {
        // std::cout << LOG "Generating Random Data ..." << RESET << std::endl;
        //-- Generate Random Data According to Algorithm Environment
        if (environment == ENVIRONMENT_1D) {
            std::cout << TAB ERROR "Generating Data for 1D Environment has Not Yet been Implemented" << std::endl;
        } else if (environment == ENVIRONMENT_2D) {
            //-- Generate Random Data on 2D Environment
            graphics.points2D.clear();
            bool show_flag;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<> dist_r(min, max);
            std::uniform_real_distribution<> dist_theta;
            std::uniform_real_distribution<> dist_offset(-37, 37);
            if (shape == RANDOM_DATA_SHAPE_SPIRAL or shape == RANDOM_DATA_SHAPE_SPIRAL_ROAD or shape == RANDOM_DATA_SHAPE_SATURN or shape == RANDOM_DATA_SHAPE_qb) {
                dist_theta = std::uniform_real_distribution<>(0, 13.5 * M_PI);
            } else if (shape == RANDOM_DATA_SHAPE_qb) {
                dist_theta = std::uniform_real_distribution<>(0, 37.5 * M_PI);
            } else {
                dist_theta = std::uniform_real_distribution<>(0, 2 * M_PI);
            }
            //-- Generate Center Dense Random Points
            int x, y;
            bool calc_flag = true;
            for (int i = 0; i < amount; i++) {
                if (shape == RANDOM_DATA_SHAPE_SPIRAL) {
                    double offset = dist_offset(gen);
                    const double a = 5;
                    const double b = 0.12;
                    double theta = dist_theta(gen);
                    double r = a * std::exp(b * theta) + offset;
                    x = static_cast<int>(WINDOW_WIDTH / 2 - r * std::cos(theta));
                    y = static_cast<int>(WINDOW_HEIGHT / 2 + r * std::sin(theta));
                } else if (shape == RANDOM_DATA_SHAPE_SPIRAL_ROAD) {
                    const double a = 5;
                    const double b = 0.1;
                    double theta = dist_theta(gen);
                    double r = a * std::exp(b * theta);
                    x = static_cast<int>(WINDOW_WIDTH / 2 + r * std::cos(theta));
                    y = static_cast<int>(WINDOW_HEIGHT / 2 + r * std::atan(theta));
                } else if (shape == RANDOM_DATA_SHAPE_SATURN) {
                    const double a = 5;
                    const double b = 0.1;
                    double theta = dist_theta(gen);
                    double r = a * std::exp(b * theta);
                    x = static_cast<int>(WINDOW_WIDTH / 2 + r * std::cos(theta) + 250 * sin(theta));
                    y = static_cast<int>(WINDOW_HEIGHT / 2 + r * std::sin(theta)) + 250 * cos(theta);
                } else if (shape == RANDOM_DATA_SHAPE_qb) {
                    const double a = 3.7;
                    const double b = 0.037;
                    double theta = dist_theta(gen);
                    double r = a * std::exp(b * theta);
                    x = static_cast<int>(WINDOW_WIDTH / 2 - r * std::cos(theta));
                    y = static_cast<int>(WINDOW_HEIGHT / 2 + r * std::sin(theta)) + 37 / cos(theta);
                } else {
                    double r = std::abs(dist_r(gen)) / 7;
                    double theta = dist_theta(gen);
                    //-- Generate Data According to Shape
                    if (shape == RANDOM_DATA_SHAPE_LINE) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * sin(theta) * cos(theta));
                        y = static_cast<int>(WINDOW_WIDTH / 2 + r * sin(theta) * cos(theta));
                    } else if (shape == RANDOM_DATA_SHAPE_CLUSTER) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * sin(theta));
                    } else if (shape == RANDOM_DATA_SHAPE_LISSAJOUS_CURVE) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * sin(3 * theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * sin(2 * theta));
                    } else if (shape == RANDOM_DATA_SHAPE_NAUTILUS) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * theta * cos(theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * theta * sin(theta));
                    } else if (shape == RANDOM_DATA_SHAPE_HYPOTROCHOID) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + (r - 20) * cos(theta) + 20 * cos((r / 20 - 1) * theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + (r - 20) * sin(theta) - 20 * sin((r / 20 - 1) * theta));
                    } else if (shape == RANDOM_DATA_SHAPE_ROSE_3) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(3 * theta) * cos(theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * cos(3 * theta) * sin(theta));
                    } else if (shape == RANDOM_DATA_SHAPE_ROSE_4) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(2 * theta) * cos(theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * cos(2 * theta) * sin(theta));
                    } else if (shape == RANDOM_DATA_SHAPE_ROSE_5) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(5 * theta) * cos(theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * cos(5 * theta) * sin(theta));
                    } else if (shape == RANDOM_DATA_SHAPE_ROSE_8) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(4 * theta) * cos(theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * cos(4 * theta) * sin(theta));
                    } else if (shape == RANDOM_DATA_SHAPE_LEMNISCATE_OF_BERNOULLI) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(theta) / (1 + sin(theta) * sin(theta)));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * sin(theta) * cos(theta) / (1 + sin(theta) * sin(theta)));
                    } else if (shape == RANDOM_DATA_SHAPE_ELLIPSE) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + 0.5 * r * sin(theta));
                    } else if (shape == RANDOM_DATA_SHAPE_ASTROID) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * pow(cos(theta), 3));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * pow(sin(theta), 3));
                    } else if (shape == RANDOM_DATA_SHAPE_DELTOID) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * (2 * cos(theta) + cos(2 * theta)));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * (2 * sin(theta) - sin(2 * theta)));
                    } else if (shape == RANDOM_DATA_SHAPE_STAR_1) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(theta) + 20 * cos(10 * theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * sin(theta) + 20 * sin(10 * theta));
                    } else if (shape == RANDOM_DATA_SHAPE_STAR_2) {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(theta) + 50 * cos(13 * theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * sin(theta) + 50 * sin(13 * theta));
                    } else {
                        x = static_cast<int>(WINDOW_WIDTH / 2 + r * cos(theta));
                        y = static_cast<int>(WINDOW_HEIGHT / 2 + r * sin(theta));
                    }
                }
                //-- Handle Show Flag Threshold
                if (i % SHOW_FRAME_THRESHOLD == 0) {
                    show_flag = true;
                } else {
                    show_flag = false;
                }
                //-- Calculate Theta
                double theta;
                if (calc_theta == CALCULATE_DATA_THETA_MIDDLE) {
                    theta = std::atan2(y - WINDOW_HEIGHT / 2, x - WINDOW_WIDTH / 2);
                } else if (calc_theta == CALCULATE_DATA_THETA_CORNER) {
                    theta = std::atan2(y, x);
                } else {
                    theta = 0;
                    calc_flag = false;
                }
                //-- Draw Point
                if (x >= min && x < max && y >= min && y < max) {
                    graphics.drawPoint(
                        env::Point2D(
                            x,
                            y,
                            theta,
                            POINT_COLOR
                        ),
                        true,
                        show_flag,
                        SHOW_POINT_NORMAL,
                        SHOW_ON_MAIN_WINDOW,
                        "None"
                    );
                }
            }
            //-- Check if Calculating Theta Flag is True
            if (calc_flag == false) {
                //-- Find Base Index
                if (calc_theta == CALCULATE_DATA_THETA_HIGHEST) {
                    //-- Find Highest Point
                    int index = 0;
                    int highest_point = 0;
                    for (int i = 0; i < graphics.points2D.size(); i++) {
                        if (graphics.points2D[i].y < graphics.points2D[highest_point].y) {
                            //-- Show Line from Current Point to Last Highest Point
                            if (index > 0) {
                                graphics.drawLine(
                                    graphics.points2D[highest_point],
                                    graphics.points2D[i],
                                    std::to_string(index),
                                    cv::Scalar(126, 128, 88),
                                    LINE_TICKNESS,
                                    false,
                                    true,
                                    SHOW_LINE_WEIGHTED,
                                    SHOW_ON_TEMP_WINDOW
                                );
                            }
                            //-- Show Point Itself
                            graphics.drawPoint(
                                graphics.points2D[i],
                                false,
                                true,
                                SHOW_POINT_RING,
                                SHOW_ON_TEMP_WINDOW,
                                "None"
                            );
                            //-- Update Highest Point
                            highest_point = i;
                            base_index = highest_point;
                            //-- Increase Index
                            index++;
                            //-- Show Window
                            cv::imshow(WINDOW_NAME, graphics.windows.temp1.matrix);
                            cv::waitKey(SHOW_FRAME_THRESHOLD);
                        }
                    }
                } else if (calc_theta == CALCULATE_DATA_THETA_LOWEST) {
                    //-- Find Lowest Point
                    int index = 0;
                    int lowest_point = 0;
                    for (int i = 0; i < graphics.points2D.size(); i++) {
                        if (graphics.points2D[i].y > graphics.points2D[lowest_point].y) {
                            //-- Show Line from Current Point to Last Lowest Point
                            if (index > 0) {
                                graphics.drawLine(
                                    graphics.points2D[lowest_point],
                                    graphics.points2D[i],
                                    std::to_string(index),
                                    cv::Scalar(126, 128, 88),
                                    LINE_TICKNESS,
                                    false,
                                    true,
                                    SHOW_LINE_WEIGHTED,
                                    SHOW_ON_TEMP_WINDOW
                                );
                            }
                            //-- Show Point Itself
                            graphics.drawPoint(
                                graphics.points2D[i],
                                false,
                                true,
                                SHOW_POINT_RING,
                                SHOW_ON_TEMP_WINDOW,
                                "None"
                            );
                            //-- Update Lowest Point
                            lowest_point = i;
                            base_index = lowest_point;
                            //-- Increase Index
                            index++;
                            //-- Show Window
                            cv::imshow(WINDOW_NAME, graphics.windows.temp1.matrix);
                            cv::waitKey(SHOW_FRAME_THRESHOLD);
                        }
                    }
                } else {
                    std::cout << TAB ERROR "Theta Calculation Method Not Supported" << std::endl;
                }
                //-- Show Base Point
                // graphics.drawPoint(
                //     graphics.points2D[base_index],
                //     false,
                //     true,
                //     SHOW_POINT_INFO_BOX,
                //     SHOW_ON_TEMP_WINDOW,
                //     "Base"
                // );
                //-- Calculate each Point's Theta According to Base Point
                for (int i = 0; i < graphics.points2D.size(); i++) {
                    graphics.points2D[i].theta = atan2(
                        graphics.points2D[i].y - graphics.points2D[base_index].y,
                        graphics.points2D[i].x - graphics.points2D[base_index].x
                    ) * 180 / M_PI;
                    //-- Show Point Itself with Frame Threshold
                    // if (i % (SHOW_FRAME_THRESHOLD / 2) == 0) {
                    //     graphics.drawPoint(
                    //         graphics.points2D[i],
                    //         false,
                    //         true,
                    //         SHOW_POINT_INFO_BOX,
                    //         SHOW_ON_TEMP_WINDOW_RESET,
                    //         std::to_string(graphics.points2D[i].theta)
                    //     );
                    // }
                }
                std::cout << SUCCESS "All Points Theta Calculated" << RESET << std::endl;
            }
            std::cout << SUCCESS "Random Data Generated" << RESET << std::endl;
            //-- Show Graphics
            cv::waitKey(0);
            cv::imshow(WINDOW_NAME, graphics.windows.main.matrix);
        } else if (environment == ENVIRONMENT_3D) {
            std::cout << TAB ERROR "Generating Data for 3D Environment has Not Yet been Implemented" << std::endl;
        } else {
            std::cout << ERROR "Environment Not Supported" << std::endl;
        }
    }
# endif // ALGORITHMS_OMID_SOJOODI