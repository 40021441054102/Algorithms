# ifndef GRAPHICS_OMID_SOJOODI
    /**
     * @file Graphics.cpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Graphics Module Implementation
     * @date 2024-04-14
     */
    # include "Graphics.hpp"
    /**
     * @brief Constructor
     * @details This Constructor Initializes the Point with Default Values
     */
    env::Point2D::Point2D() {
        x = 0;
        y = 0;
        theta = 0;
    }
    /**
     * @brief Constructor with Parameters
     * @details This Constructor Initializes the Point with Given Parameters
     * 
     * @param _x X Coordinate
     * @param _y Y Coordinate
     * @param _theta Angle
     * @param _color Color
     */
    env::Point2D::Point2D(
        double          _x,
        double          _y,
        double          _theta,
        cv::Scalar      _color
    ) {
        x = _x;
        y = _y;
        theta = _theta;
        color = _color;
    }
    /**
     * @brief Constructor
     * @details This Constructor Initializes the Box with Default Values
     */
    env::Box2D::Box2D() {
        topLeft = Point2D();
        bottomRight = Point2D();
    }
    /**
     * @brief Constructor
     * @details This Constructor Initializes the Point with Default Values
     */
    env::Point3D::Point3D() {
        x = 0;
        y = 0;
        z = 0;
        theta = 0;
    }
    /**
     * @brief Constructor with Parameters
     * @details This Constructor Initializes the Point with Given Parameters
     * 
     * @param _x X Coordinate
     * @param _y Y Coordinate
     * @param _z Z Coordinate
     * @param _theta Angle
     * @param _color Color
     */
    env::Point3D::Point3D(
        double      &   _x,
        double      &   _y,
        double      &   _z,
        double      &   _theta,
        cv::Scalar  &   _color
    ) {
        x = _x;
        y = _y;
        z = _z;
        theta = _theta;
        color = _color;
    }
    /**
     * @brief Constructor
     * @details This Constructor Initializes the Box with Default Values
     */
    env::Box3D::Box3D() {
        topDiamPoint = Point3D();
        downDiamPoint = Point3D();
    }
    /**
     * @brief Constructor with Parameters
     * @details This Constructor Initializes the Graphics with Given Parameters
     * 
     * @param _environment Environment
     */
    Graphics::Graphics(
        ENUM_ALGORITHM_ENVIRONMENT _environment
    ) {
        environment = _environment;
        //-- Act According to Specific Environment
        if (environment == ENVIRONMENT_1D) {
            std::cout << ERROR "Can Not Load Graphics Module, 1D Environment Not Implemented" << std::endl;
            //-- Raise Exception
            throw EXCEPTION_GRAPHICS("1D Environment Not Implemented");
        } else if (environment == ENVIRONMENT_2D) {
            //-- Initialize Window
            windows.main.matrix = cv::Mat(
                WINDOW_HEIGHT,
                WINDOW_WIDTH,
                CV_8UC3,
                WINDOW_BACKGROUND
            );
            //-- Initialize Info Window
            windows.info.matrix = cv::Mat(
                INFO_WINDOW_HEIGHT,
                INFO_WINDOW_WIDTH,
                CV_8UC3,
                WINDOW_BACKGROUND
            );
            //-- Show Main Window
            cv::imshow(WINDOW_NAME, windows.main.matrix);
            //-- Show Info Window
            cv::imshow(INFO_WINDOW_NAME, windows.info.matrix);
            //-- Get Screen Resolution
            Display* disp = XOpenDisplay(NULL);
            Screen* scrn = DefaultScreenOfDisplay(disp);
            screen.center.y = scrn->height / 2;
            screen.center.x = scrn->width / 2;
            screen.height = scrn->height;
            screen.width = scrn->width;
            XCloseDisplay(disp);
            //-- Generate Main Window Position
            windows.main.position.x = screen.width / 2 - WINDOW_WIDTH / 2;
            windows.main.position.y = screen.height / 2 - WINDOW_HEIGHT / 2;
            //-- Generate Info Window Position
            // windows.info.position.x = screen.width / 2 - INFO_WINDOW_WIDTH / 2;
            // windows.info.position.y = screen.height / 2 - INFO_WINDOW_HEIGHT / 2;
            windows.info.position.x = screen.width / 2 + WINDOW_WIDTH / 2 + WINDOWS_PADDING;
            windows.info.position.y = screen.height / 2 - INFO_WINDOW_HEIGHT / 2;
            //-- Move Main Window to Its Positions
            cv::moveWindow(
                WINDOW_NAME,
                windows.main.position.x,
                windows.main.position.y
            );
            //-- Move Info Window to Its Positions
            cv::moveWindow(
                INFO_WINDOW_NAME,
                windows.info.position.x,
                windows.info.position.y
            );
            //-- Generate Info Window GUI
            // generateInfoWindow();
        } else if (environment == ENVIRONMENT_3D) {
            // cv::viz::Viz3d window3D(WINDOW_NAME);
            // window3D.setWindowSize(cv::Size(WINDOW_WIDTH, WINDOW_HEIGHT));
            // window3D.setWindowPosition(cv::Point(screen.width / 2 - WINDOW_WIDTH / 2, screen.height / 2 - WINDOW_HEIGHT / 2));
            // window3D.setBackgroundColor(WINDOW_BACKGROUND);
            // window3D.showWidget("Coordinate Widget", cv::viz::WCoordinateSystem());
            // window3D.spin();
            // window3D.waitKey(30);
            std::cout << ERROR "Can Not Load Graphics Module, 3D Environment Not Implemented" << std::endl;
            //-- Raise Exception
            throw EXCEPTION_GRAPHICS("3D Environment Not Implemented");
        } else {
            std::cout << ERROR "Can Not Load Graphics Module, Invalid Environment" << std::endl;
            //-- Raise Exception
            throw EXCEPTION_GRAPHICS("Invalid Environment Initialization for Graphics Module");
        }
        //-- Initialize Mouse State
        mouseState = ENUM_MOUSE_STATE::EVENTS_ACTIVE;
        //-- Initialize Mouse Callback on Main Window
        cv::setMouseCallback(WINDOW_NAME, onMouseCallback, this);
        //-- Initialize Mouse Callback on Info Window
        cv::setMouseCallback(INFO_WINDOW_NAME, onMouseCallback, this);
        //-- Finish Initialization
        std::cout << LOG "Graphics Module Loaded Successfully!" << std::endl;
    }
    /**
     * @brief Destructor
     * @details This Destructor Destroys the Graphics Module
     */
    Graphics::~Graphics() {
        //-- Finish Destruction
        std::cout << LOG "Graphics Module Unloaded Successfully!" << std::endl;
    }
    /**
     * @brief Method to Generate Info Window GUI
     * @details This Method Generates the Info Window GUI
     */
    void Graphics::generateInfoWindow() {
        //-- Generate Home Button
        cv::rectangle(
            windows.info.matrix,
            cv::Point(
                INFO_WINDOW_WIDTH - INFO_WINDOW_BUTTON_WIDTH,
                INFO_WINDOW_BUTTON_HEIGHT
            ),
            cv::Point(
                INFO_WINDOW_WIDTH,
                0
            ),
            INFO_WINDOW_BUTTON_COLOR,
            -1
        );
        //-- Generate Home Button Text in Middle of Button
        std::string home_button_text = INFO_WINDOW_BUTTON_TEXT;
        //-- Get Text Size
        cv::Size button_size = cv::getTextSize(
            home_button_text,
            cv::FONT_HERSHEY_SIMPLEX,
            INFO_WINDOW_BUTTON_TEXT_SIZE,
            INFO_WINDOW_BUTTON_TEXT_THICKNESS,
            0
        );
        //-- Calculate Text Position
        cv::Point text_position(
            INFO_WINDOW_WIDTH - INFO_WINDOW_BUTTON_WIDTH / 2 - button_size.width / 2,
            INFO_WINDOW_BUTTON_HEIGHT / 2 + button_size.height / 2
        );
        //-- Draw Text
        cv::putText(
            windows.info.matrix,
            home_button_text,
            text_position,
            cv::FONT_HERSHEY_SIMPLEX,
            INFO_WINDOW_BUTTON_TEXT_SIZE,
            INFO_WINDOW_BUTTON_TEXT_COLOR,
            INFO_WINDOW_BUTTON_TEXT_THICKNESS
        );
        //-- Show Info Window
        cv::imshow(INFO_WINDOW_NAME, windows.info.matrix);
    }
    /**
     * @brief Mouse Callback Method
     * @details This Method is the Callback Method for Mouse Events
     * 
     * @param event Event
     * @param x X - Axis Coordinate
     * @param y Y - Axis Coordinate
     * @param flags Flags
     * @param userdata User Data
     */
    void Graphics::onMouseCallback(
        int         event,
        int         x,
        int         y,
        int         flags,
        void*       userdata
    ) {
        Graphics* graphics = (Graphics*) userdata;
        graphics->onMouse(event, x, y, flags);
    }
    /**
     * @brief Mouse Events Method
     * @details This Method Handles the Mouse Events
     * 
     * @param event Event
     * @param x X - Axis Coordinate
     * @param y Y - Axis Coordinate
     * @param flags Flags
     */
    void Graphics::onMouse(
        int         event,
        int         x,
        int         y,
        int         flags
    ) {
        if (event == cv::EVENT_MOUSEMOVE) {
            std::cout << LOG "Mouse Moved to (" << x << ", " << y << ")" << std::endl;
        }
    }
    /**
     * @brief Method to Draw Point
     * @details This Method Draws a Point on the Screen
     * 
     * @param point Point
     * @param add_to_points Add to Points
     * @param show_flag Show Flag
     * @param show_method Show Method
     * @param window_mode Window Mode
     */
    void Graphics::drawPoint(
        env::Point2D point,
        bool add_to_points = true,
        bool show_flag = false,
        ENUM_SHOW_POINT_METHODS show_method = SHOW_POINT_NORMAL,
        ENUM_SHOW_WINDOW_MODE window_mode = SHOW_ON_MAIN_WINDOW
    ) {
        //-- Handle Window Mode
        cv::Mat temp;
        if (window_mode == SHOW_ON_TEMP_WINDOW) {
            //-- Check if Temp Window is Empty
            if (windows.temp1.matrix.empty()) {
                windows.temp1.matrix = windows.main.matrix;
            }
            temp = windows.temp1.matrix;
        } else {
            temp = windows.main.matrix;
        }
        //-- Show Normal Point
        if (show_method == SHOW_POINT_NORMAL) {
            cv::circle(
                temp,
                cv::Point(point.x, point.y),
                POINT_RADIUS,
                point.color,
                POINT_THICKNESS,
                cv::LINE_4
            );
        }
        //-- Show Ring Around Point
        if (show_method == SHOW_POINT_RING) {
            //-- Draw Ring Around Point
            cv::circle(
                temp,
                cv::Point(point.x, point.y),
                POINT_RADIUS + POINT_RING_RADIUS,
                POINT_RING_COLOR,
                POINT_RING_THICKNESS,
                cv::LINE_AA
            );
            //-- Draw 4 Plus Shaped Lines Around Point
            //- First Line
            cv::line(
                temp,
                cv::Point(point.x + POINT_RING_LINE_BEGIN, point.y),
                cv::Point(point.x + POINT_RING_LINE_BEGIN + POINT_RING_LINE_SIZE, point.y),
                POINT_RING_LINE_COLOR,
                POINT_RING_THICKNESS,
                cv::LINE_AA
            );
            //- Second Line
            cv::line(
                temp,
                cv::Point(point.x - POINT_RING_LINE_BEGIN, point.y),
                cv::Point(point.x - POINT_RING_LINE_BEGIN - POINT_RING_LINE_SIZE, point.y),
                POINT_RING_LINE_COLOR,
                POINT_RING_THICKNESS,
                cv::LINE_AA
            );
            //- Third Line
            cv::line(
                temp,
                cv::Point(point.x, point.y + POINT_RING_LINE_BEGIN),
                cv::Point(point.x, point.y + POINT_RING_LINE_BEGIN + POINT_RING_LINE_SIZE),
                POINT_RING_LINE_COLOR,
                POINT_RING_THICKNESS,
                cv::LINE_AA
            );
            //- Fourth Line
            cv::line(
                temp,
                cv::Point(point.x, point.y - POINT_RING_LINE_BEGIN),
                cv::Point(point.x, point.y - POINT_RING_LINE_BEGIN - POINT_RING_LINE_SIZE),
                POINT_RING_LINE_COLOR,
                POINT_RING_THICKNESS,
                cv::LINE_AA
            );
        }
        //-- Add Point to Points
        if (add_to_points) {
            points2D.push_back(point);
        }
        //-- Load Final Matrix from Temp
        if (window_mode == SHOW_ON_TEMP_WINDOW) {
            windows.temp1.matrix = temp;
        } else {
            windows.main.matrix = temp;
        }
        //-- Check Show Flag
        if(show_flag) {
            if (window_mode == SHOW_ON_MAIN_WINDOW) {
                //-- Show Main Window
                cv::imshow(WINDOW_NAME, windows.main.matrix);
                cv::waitKey(1);
            } else if (window_mode == SHOW_ON_TEMP_WINDOW) {
                //-- Copy Main Window to Temp Window if Temp Window is Empty
                if (windows.temp1.matrix.empty()) {
                    windows.main.matrix.copyTo(windows.temp1.matrix);
                }
                //-- Show Temp Window
                cv::imshow(WINDOW_NAME, windows.temp1.matrix);
                cv::waitKey(1);
            }
        }
    }
    /**
     * @brief Method to Draw Line
     * @details This Method Draws a Line on the Screen
     * 
     * @param point1 Point 1
     * @param point2 Point 2
     * @param color Color
     * @param thickness Thickness
     * @param add_to_lines Add to Lines
     * @param show_flag Show Flag
     * @param show_method Show Method
     * @param window_mode Window Mode
     * @param weight Line Weight
     */
    void Graphics::drawLine(
        env::Point2D point1,
        env::Point2D point2,
        std::string weight = 0,
        cv::Scalar color = LINE_COLOR,
        int thickness = LINE_TICKNESS,
        bool add_to_lines = false,
        bool show_flag = true,
        ENUM_SHOW_LINE_METHODS show_method = SHOW_LINE_NORMAL,
        ENUM_SHOW_WINDOW_MODE window_mode = SHOW_ON_MAIN_WINDOW
    ) {
        //-- Handle Window Mode
        cv::Mat temp;
        if (window_mode == SHOW_ON_TEMP_WINDOW) {
            //-- Check if Temp Window is Empty
            if (windows.temp1.matrix.empty()) {
                windows.temp1.matrix = windows.main.matrix;
            }
            temp = windows.temp1.matrix;
        } else {
            temp = windows.main.matrix;
        }
        cv::line(
            temp,
            cv::Point(point1.x, point1.y),
            cv::Point(point2.x, point2.y),
            color,
            thickness,
            cv::LINE_4
        );
        //-- Show Line Weights
        if (show_method == SHOW_LINE_WEIGHTED) {
            //-- Calculate Mid Point
            env::Point2D mid_point(
                (point1.x + point2.x) / 2,
                (point1.y + point2.y) / 2,
                0,
                color
            );
            //-- Initialize Weight Text (Features May Be Added in Future)
            std::string weight_text = weight;
            //-- Get Text Size
            cv::Size text_size = cv::getTextSize(
                weight_text,
                cv::FONT_HERSHEY_SIMPLEX,
                LINE_WEIGHT_TEXT_SIZE,
                LINE_WEIGHT_TEXT_THICKNESS,
                0
            );
            //-- Calculate Text Position
            cv::Point text_position(
                mid_point.x - text_size.width / 2 + 1,
                mid_point.y + text_size.height / 2
            );
            //-- Draw Background Circle in Size of Text
            cv::circle(
                temp,
                cv::Point(mid_point.x, mid_point.y),
                text_size.width / 2 + LINE_WEIGHT_BACKGROUND_PADDING,
                LINE_WEIGHT_BACKGROUND_COLOR,
                -1
            );
            //-- Draw Text
            cv::putText(
                temp,
                weight_text,
                text_position,
                cv::FONT_HERSHEY_SIMPLEX,
                LINE_WEIGHT_TEXT_SIZE,
                LINE_WEIGHT_TEXT_COLOR,
                LINE_WEIGHT_TEXT_THICKNESS
            );
        }
        //-- Add Line to Lines
        if (add_to_lines) {
            //-- Not Implemented Yet
            std::cout << ERROR "Add to Lines Not Implemented Yet !" << std::endl;
            // lines2D.push_back(env::Line2D(point1, point2, color, thickness));
        }
        //-- Load Final Matrix from Temp
        if (window_mode == SHOW_ON_TEMP_WINDOW) {
            windows.temp1.matrix = temp;
        } else {
            windows.main.matrix = temp;
        }
        //-- Check Show Flag
        if(show_flag) {
            if (window_mode == SHOW_ON_MAIN_WINDOW) {
                //-- Show Main Window
                cv::imshow(WINDOW_NAME, windows.main.matrix);
                cv::waitKey(1);
            } else if (window_mode == SHOW_ON_TEMP_WINDOW) {
                //-- Copy Main Window to Temp Window if Temp Window is Empty
                if (windows.temp1.matrix.empty()) {
                    windows.main.matrix.copyTo(windows.temp1.matrix);
                }
                //-- Show Temp Window
                cv::imshow(WINDOW_NAME, windows.temp1.matrix);
                cv::waitKey(1);
            }
        }
    }
# endif // GRAPHICS_OMID_SOJOODI