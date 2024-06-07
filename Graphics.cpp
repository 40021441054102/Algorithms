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
            windows.info.position.x = screen.width / 2 + WINDOW_WIDTH / 2;
            windows.info.position.y = screen.height / 2 - WINDOW_HEIGHT / 2;
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
     */
    void Graphics::drawPoint(env::Point2D point, bool add_to_points = true, bool show_flag = false) {
        //-- Draw Point
        cv::circle(
            windows.main.matrix,
            cv::Point(point.x, point.y),
            POINT_RADIUS,
            point.color,
            POINT_THICKNESS,
            cv::LINE_4
        );
        //-- Add Point to Points
        if (add_to_points) {
            points2D.push_back(point);
        }
        if(show_flag) {
            //-- Show Main Window
            cv::imshow(WINDOW_NAME, windows.main.matrix);
            cv::waitKey(1);
        }
    }
# endif // GRAPHICS_OMID_SOJOODI