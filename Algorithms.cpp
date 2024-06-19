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
        ENUM_ALGORITHMS_DATA_METHOD dataMethod,
        ENUM_ALGORIHTMS_PROCESSING_METHODS processingMethod
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
            //-- Insertion Sort
            case ALGORITHM_SORT_INSERTION: {
                //-- Generate Random Data
                if (dataMethod == USE_RANDOM_DATA) {
                    generateRandomData(
                        MAX_RANDOM_DATA,
                        int(WINDOW_WIDTH * 0.1),
                        int(WINDOW_WIDTH * 0.9),
                        environment,
                        RANDOM_DATA_SHAPE_SPIRAL_ROAD,
                        CALCULATE_DATA_THETA_MIDDLE
                    );
                } else if (dataMethod == USE_INPUT_FILE) {
                    std::cout << TAB ERROR "Loading Data from Input File Method Not Yet Implemented" << std::endl;
                } else {
                    std::cout << TAB ERROR "Data Method Not Supported" << std::endl;
                }
                //-- Sort with Visualization
                std::vector<env::Point2D> sorted_array;
                sorted_array = sorts.insertion.getSorted2D(
                    graphics.points2D,
                    INSERTION_ASCENDING,
                    true,
                    graphics,
                    INSERTION_SORT_BOTTOM_TO_TOP
                );
                //-- Starting Time
                begin_time = std::chrono::high_resolution_clock::now();
                //-- Sort
                sorts.insertion.getSorted2D(
                    graphics.points2D,
                    INSERTION_ASCENDING,
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
            //-- Merge Sort
            case ALGORITHM_SORT_MERGE: {
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
                sorted_array = sorts.merge.getSorted2D(
                    graphics.points2D,
                    MERGE_DESCENDING,
                    true,
                    graphics,
                    MERGE_SORT_THETA
                );
                //-- Starting Time
                begin_time = std::chrono::high_resolution_clock::now();
                //-- Sort
                sorts.merge.getSorted2D(
                    graphics.points2D,
                    MERGE_ASCENDING,
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
            //-- Quick Sort
            case ALGORITHM_SORT_QUICK: {
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
                sorted_array = sorts.quick.getSorted2D(
                    graphics.points2D,
                    QUICK_ASCENDING,
                    true,
                    graphics,
                    QUICK_SORT_LEFT_TO_RIGHT
                );
                //-- Starting Time
                begin_time = std::chrono::high_resolution_clock::now();
                //-- Sort
                sorts.quick.getSorted2D(
                    graphics.points2D,
                    QUICK_ASCENDING,
                    false,
                    graphics,
                    QUICK_SORT_THETA
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
            //-- N Queens
            case ALGORITHM_N_QUEENS: {
                //-- Generate Random Data
                if (dataMethod == USE_RANDOM_DATA) {
                    generateChessBoardData(
                        CHESS_BOARD_SIZE,
                        SHOW_BOX_CHESS_WEIGHTED,
                        ENVIRONMENT_2D
                    );
                } else if (dataMethod == USE_INPUT_FILE) {
                    std::cout << TAB ERROR "Loading Data from Input File Method Not Yet Implemented" << std::endl;
                } else {
                    std::cout << TAB ERROR "Data Method Not Supported" << std::endl;
                }
                //-- Solve N Queens Problem
                nqueens.getSolved(
                    graphics.boxes2D,
                    graphics
                );
                //-- Show Solutions on Chess Board
                cv::Mat image;
                cv::Mat image_black = cv::imread("../NQueens/assets/2.png", cv::IMREAD_COLOR);
                cv::Mat image_white = cv::imread("../NQueens/assets/1.png", cv::IMREAD_COLOR);
                for (int index = 0; index < nqueens.solutions.size(); ++index) {
                    graphics.windows.main.matrix.copyTo(graphics.windows.temp1.matrix);
                    std::cout << MODULE NQUEENS_LABEL "Solution " << index + 1 << ":" << std::endl;
                    for (int i = 0; i < nqueens.solutions[index].size(); ++i) {
                        for (int j = 0; j < nqueens.solutions[index].size(); ++j) {
                            //-- Handle Image Color
                            if (i % 2 == 0) {
                                if (j % 2 == 0) {
                                    image = image_white;
                                } else {
                                    image = image_black;
                                }
                            } else {
                                if (j % 2 == 0) {
                                    image = image_black;
                                } else {
                                    image = image_white;
                                }
                            }
                            if (nqueens.solutions[index][i] == j) {
                                std::cout << TERMINAL_BACKGROUND TERMINAL_QUEEN " \033[0m";
                                //-- Draw Rectangle on graphics.box2D (Chess Board) Where Queen is Placed
                                // cv::rectangle(
                                //     graphics.windows.temp1.matrix,
                                //     cv::Point(
                                //         graphics.boxes2D[i][j].p1.x,
                                //         graphics.boxes2D[i][j].p1.y
                                //     ),
                                //     cv::Point(
                                //         graphics.boxes2D[i][j].p2.x,
                                //         graphics.boxes2D[i][j].p2.y
                                //     ),
                                //     cv::Scalar(0, 255, 255),
                                //     -1,
                                //     cv::LINE_AA
                                // );
                                //-- Draw Queen on graphics.box2D (Chess Board)
                                graphics.drawImage(
                                    cv::Point(
                                        graphics.boxes2D[i][j].p1.x + 5,
                                        graphics.boxes2D[i][j].p1.y + 5
                                    ),
                                    cv::Point(
                                        graphics.boxes2D[i][j].p2.x - 5,
                                        graphics.boxes2D[i][j].p2.y - 5
                                    ),
                                    // cv::imread("../NQueens/assets/black.png", cv::IMREAD_COLOR)
                                    image
                                );
                                //-- Show Chess Board
                                cv::imshow(WINDOW_NAME, graphics.windows.temp1.matrix);
                                cv::waitKey(73);
                            }
                            else {
                                std::cout << TERMINAL_BACKGROUND TERMINAL_EMPTY " \033[0m";
                            }
                        }
                        std::cout << std::endl;
                    }
                    cv::waitKey(0);
                }
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
    /**
     * @brief Generate Chess Board Data
     * @details This Method Generates Chess Board Data for the Algorithm.
     * 
     * @param size The Size of the Chess Board
     * @param method The Method to Show the Box
     * @param environment The Environment to Generate Data
     */
    void Algorithms::generateChessBoardData(
        int size,
        ENUM_SHOW_BOX_METHODS method,
        ENUM_ALGORITHM_ENVIRONMENT environment
    ) {
        //-- Generate Chess Board Data According to Algorithm Environment
        if (environment == ENVIRONMENT_1D) {
            std::cout << TAB ERROR "Generating Data for 1D Environment has Not Yet been Implemented" << std::endl;
        } else if (environment == ENVIRONMENT_2D) {
            //-- Extract Box Length According to Size and Window Width
            int box_length = WINDOW_WIDTH / size;
            //-- Generate Chess Board Data on 2D Environment
            cv::Scalar color, text_color;
            for (int i = 0; i < size; i++) {
                std::vector<env::Box2D> row;
                for (int j = 0; j < size; j++) {
                    //-- Handle Color
                    if ((i + j) % 2 == 0) {
                        color = CHESS_BOARD_WHITE_COLOR;
                        text_color = CHESS_BOARD_BLACK_COLOR;
                    } else {
                        color = CHESS_BOARD_BLACK_COLOR;
                        text_color = CHESS_BOARD_WHITE_COLOR;
                    }
                    //-- Generate Point 1
                    env::Point2D point1 = env::Point2D(
                        j * box_length, // Correct order for X coordinate
                        i * box_length, // Correct order for Y coordinate
                        0,
                        color
                    );
                    //-- Generate Point 2
                    env::Point2D point2 = env::Point2D(
                        j * box_length + box_length,
                        i * box_length + box_length,
                        0,
                        color
                    );
                    //-- Generate Chess Home Name
                    std::string home_name = "";
                    if (method == SHOW_BOX_CHESS_WEIGHTED || method == SHOW_BOX_NORMAL_WEIGHTED || method == SHOW_BOX_CHESS_COLORFUL_WEIGHTED) {
                        home_name = std::string(1, char(65 + j)) + std::to_string(i + 1);
                    } else {
                        home_name = "None";
                    }
                    //-- Draw Box
                    graphics.drawBox(
                        i,
                        env::Box2D(
                            point1,
                            point2
                        ),
                        home_name,
                        text_color,
                        color,
                        true
                    );
                    //-- Add Box to Row
                    row.push_back(env::Box2D(point1, point2));
                }
                graphics.boxes2D.push_back(row);
            }
            std::cout << SUCCESS "Chess Board Data has been Generated" << RESET << std::endl;
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