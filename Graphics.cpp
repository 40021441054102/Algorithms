# ifndef GRAPHICS_OMID_SOJOODI
    # include "Graphics.hpp"
    /**
     * @brief 2D Environment Point Default Constructor
     */
    env::Point2D::Point2D() {
        x = 0;
        y = 0;
        theta = 0;
    }
    /**
     * @brief 2D Environment Point Parametric Constructor
     */
    env::Point2D::Point2D(
        double      &   _x,
        double      &   _y,
        double      &   _theta,
        cv::Scalar  &   _color
    ) {
        x = _x;
        y = _y;
        theta = _theta;
        color = _color;
    }
    /**
     * @brief 2D Environment Box Constructor
     */
    env::Box2D::Box2D() {
        topLeft = Point2D();
        bottomRight = Point2D();
    }
    /**
     * @brief 3D Environment Point Constructor
     */
    env::Point3D::Point3D() {
        x = 0;
        y = 0;
        z = 0;
        theta = 0;
    }
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
     * @brief 3D Environment Box Constructor
     */
    env::Box3D::Box3D() {
        topDiamPoint = Point3D();
        downDiamPoint = Point3D();
    }
    /**
     * @brief Graphics Constructor
     */
    Graphics::Graphics(
        ENUM_ALGORITHM_ENVIRONMENT      &   _environment
    ) {
        environment = _environment;
        //-- Act According to Specific Environment
        if (environment == ENVIRONMENT_1D) {
            std::cout << ERROR "Can Not Load Graphics Module, 1D Environment Not Implemented" << std::endl;
        } else if (environment == ENVIRONMENT_2D) {
            window = cv::Mat(
                WINDOW_HEIGHT,
                WINDOW_WIDTH,
                CV_8UC3,
                WINDOW_BACKGROUND
            );
        } else if (environment == ENVIRONMENT_3D) {
        } else {
            std::cout << ERROR "Can Not Load Graphics Module, Invalid Environment" << std::endl;
        }

        points.resize(0);
        infoWindow = cv::Mat(
            INFO_WINDOW_HEIGHT,
            INFO_WINDOW_WIDTH,
            CV_8UC3,
            WINDOW_BACKGROUND
        );
        int width, height;
        Display* disp = XOpenDisplay(NULL);
        Screen* scrn = DefaultScreenOfDisplay(disp);
        XCloseDisplay(disp);
        height = scrn->height;
        width = scrn->width;
        windowPositionCenter.x = width / 2;
        windowPositionCenter.y = height / 2;
        cv::imshow(WINDOW_NAME, window);
        cv::moveWindow(
            WINDOW_NAME,
            width / 2 - WINDOW_WIDTH / 2,
            height / 2 - WINDOW_HEIGHT / 2
        );
        // startAnimation();
        //-- Set Mouse Callback
        cv::setMouseCallback(WINDOW_NAME, onMouseCallback, this);
        //-- Set Mouse Event Active Status
        mouseStatus = EVENTS_ACTIVE;
        std::cout << LOG "Graphics Module Loaded Successfully!" << std::endl;
    }
# endif // GRAPHICS_OMID_SOJOODI