# ifndef ALGORITHMS_OMID_SOJOODI
    # include "Algorithms.hpp"
    //-- Constructor
    Algorithms::Algorithms(
        ENUM_SUPPORTED_ALGORITHMS algorithm,
        ENUM_ALGORITHM_ENVIRONMENT environment,
        ENUM_ALGORITHMS_DATA_METHOD dataMethod = USE_RANDOM_DATA,
        ENUM_ALGORIHTMS_PROCESSING_METHODS processingMethod = USE_SINGLE_THREAD
    ) {
        //-- Generate Random Data
        if (dataMethod == USE_RANDOM_DATA) {
            generateRandomData(
                MAX_RANDOM_DATA,
                int(WINDOW_WIDTH * 0.1),
                int(WINDOW_WIDTH * 0.9),
                environment,
                RANDOM_DATA_SHAPE_SPIRAL
            );
        }
        std::cout << LOG "Starting Algorithm Process Time" << RESET << std::endl;
        begin_time = std::chrono::high_resolution_clock::now();
    }
    //-- Destructor
    Algorithms::~Algorithms() {
        end_time = std::chrono::high_resolution_clock::now();
        algorithm_duration = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - begin_time);
        std::cout << LOG "Algorithm Process Time: " << algorithm_duration.count() << "s" << RESET << std::endl;
    }
    //-- Method to Generate Random Data
    void Algorithms::generateRandomData(
        int amount,
        int min,
        int max,
        ENUM_ALGORITHM_ENVIRONMENT environment,
        ENUM_RANDOM_DATA_SHAPES shape
    ) {
        std::cout << LOG "Generating Random Data ..." << RESET << std::endl;
        //-- Generate Random Data According to Algorithm Environment
        if (environment == ENVIRONMENT_1D) {
            std::cout << TAB ERROR "Generating Data for 1D Environment has Not Yet been Implemented" << std::endl;
        } else if (environment == ENVIRONMENT_2D) {
            //-- Initialize Graphics
            Graphics graphics(environment);
            //-- Generate Random Data on 2D Environment
            graphics.points2D.clear();
            bool show_flag;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<> dist_r(min, max);
            std::uniform_real_distribution<> dist_theta;
            std::uniform_real_distribution<> dist_offset(-37, 37);
            if (shape == RANDOM_DATA_SHAPE_SPIRAL or shape == RANDOM_DATA_SHAPE_SPIRAL_ROAD or shape == RANDOM_DATA_SHAPE_SATURN or shape == RANDOM_DATA_SHAPE_qb) {
                dist_theta = std::uniform_real_distribution<>(0, 12.5 * M_PI);
            } else if (shape == RANDOM_DATA_SHAPE_qb) {
                dist_theta = std::uniform_real_distribution<>(0, 37.5 * M_PI);
            } else {
                dist_theta = std::uniform_real_distribution<>(0, 2 * M_PI);
            }
            //-- Generate Center Dense Random Points
            int x, y;
            for (int i = 0; i < amount; i++) {
                if (shape == RANDOM_DATA_SHAPE_SPIRAL) {
                    const double a = 5;
                    const double b = 0.12;
                    double theta = dist_theta(gen);
                    double offset = dist_offset(gen);
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
                //-- Draw Point
                if (x >= min && x < max && y >= min && y < max) {
                    graphics.drawPoint(
                        env::Point2D(
                            x,
                            y,
                            0,
                            POINT_COLOR
                        ),
                        true,
                        show_flag
                    );
                }
            }
            //-- Show Graphics
            cv::imshow(WINDOW_NAME, graphics.windows.main.matrix);
            cv::waitKey(0);
        } else if (environment == ENVIRONMENT_3D) {
            std::cout << TAB ERROR "Generating Data for 3D Environment has Not Yet been Implemented" << std::endl;
        } else {
            std::cout << ERROR "Environment Not Supported" << std::endl;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(1, 100);
        int random_number = distribution(gen);
    }
# endif // ALGORITHMS_OMID_SOJOODI