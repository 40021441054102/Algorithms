# ifndef GRAPHICS_OMID_SOJOODI
    /**
     * @file Graphics.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Graphics Header File
     * @date 2024-04-14
     * @def GRAPHICS_OMID_SOJOODI
     * @brief Graphics Header File Macro
     * @details This Header File Contains All the Required Libraries and Classes for Graphical Visualization
     */
    # define GRAPHICS_OMID_SOJOODI
    //-- Include OpenCV HighGUI
    # ifndef OPENCV_HIGHGUI_HPP
        # include "opencv4/opencv2/highgui.hpp"
    # endif // OPENCV_HIGHGUI_HPP
    //-- Include OpenCV ImgProc
    # ifndef OPENCV_IMGPROC_HPP
        # include "opencv4/opencv2/imgproc.hpp"
    # endif // OPENCV_IMGPROC_HPP
    //-- Include OpenCV Viz
    // # ifndef OPENCV_VIZ_HPP
    //     # include "opencv4/opencv2/viz.hpp"
    // # endif // OPENCV_VIZ_HPP
    //-- Include X11
    # ifndef _X11_XLIB_H_
        # include <X11/Xlib.h>
    # endif // _X11_XLIB_H_
    //-- Include Exception
    # ifndef __EXCEPTION__
        # include <exception>
    # endif // _GLIBCXX_EXCEPTION
    //-- Include Configurations
    # ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
        # include "Configs.hpp"
    # endif // ALGORITHMS_OMID_SOJOODI_CONFIGS
    /**
     * @brief Cyan Color Configuration
     * @details This Macro Defines the Cyan Color
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define COLOR_CYAN                             cv::Scalar(255, 255, 0)
    /**
     * @brief Dark Cyan Color Configuration
     * @details This Macro Defines the Dark Cyan Color
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define COLOR_CYAN_DARK                        cv::Scalar(170, 170, 0)
    /**
     * @def WINDOW_WIDTH
     * @brief Window Width Configuration
     * @details This Macro Defines the Width of the Window
     */
    # define WINDOW_WIDTH                           1730
    /**
     * @def WINDOW_HEIGHT
     * @brief Window Height Configuration
     * @details This Macro Defines the Height of the Window
     */
    # define WINDOW_HEIGHT                          1730
    /**
     * @def WINDOW_NAME
     * @brief Window Name Configuration
     * @details This Macro Defines the Name of the Window
     */
    # define WINDOW_NAME                            "Graphical View"
    /**
     * @def WINDOW_BACKGROUND
     * @brief Window Background Configuration
     * @details This Macro Defines the Background Color of the Window
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define WINDOW_BACKGROUND                      cv::Scalar(20, 10, 0)
    /**
     * @def WINDOWS_PADDING
     * @brief Windows Padding Configuration
     * @details This Macro Defines the Padding between the Windows
     */
    # define WINDOWS_PADDING                        50
    /**
     * @def INFO_WINDOW_WIDTH
     * @brief Info Window Width Configuration
     * @details This Macro Defines the Width of the Info Window
     */
    # define INFO_WINDOW_WIDTH                      WINDOW_WIDTH / 3
    /**
     * @def INFO_WINDOW_HEIGHT
     * @brief Info Window Height Configuration
     * @details This Macro Defines the Height of the Info Window
     */
    # define INFO_WINDOW_HEIGHT                     WINDOW_HEIGHT / 1.5
    /**
     * @def INFO_WINDOW_NAME
     * @brief Info Window Name Configuration
     * @details This Macro Defines the Name of the Info Window
     */
    # define INFO_WINDOW_NAME                       "Info"
    /**
     * @brief Info Window Button Width Configuration
     * @details This Macro Defines the Info Window Button Width
     */
    # define INFO_WINDOW_BUTTON_WIDTH               INFO_WINDOW_WIDTH / 4
    /**
     * @brief Info Window Button Height Configuration
     * @details This Macro Defines the Info Window Button Height
     */
    # define INFO_WINDOW_BUTTON_HEIGHT              INFO_WINDOW_WIDTH / 4
    /**
     * @brief Info Window Button Color Configuration
     * @details This Macro Defines the Info Window Button Color
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define INFO_WINDOW_BUTTON_COLOR               cv::Scalar(255, 255, 255)
    /**
     * @brief Info Window Button Text Configuration
     * @details This Macro Defines the Info Window Button Text
     */
    # define INFO_WINDOW_BUTTON_TEXT                "Home"
    /**
     * @brief Info Window Button Text Color Configuration
     * @details This Macro Defines the Info Window Button Text Color
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define INFO_WINDOW_BUTTON_TEXT_COLOR          cv::Scalar(0, 0, 0)
    /**
     * @brief Info Window Button Text Thickness Configuration
     * @details This Macro Defines the Info Window Button Text Thickness
     */
    # define INFO_WINDOW_BUTTON_TEXT_SIZE          0.5
    /**
     * @brief Info Window Button Text Thickness Configuration
     * @details This Macro Defines the Info Window Button Text Thickness
     */
    # define INFO_WINDOW_BUTTON_TEXT_THICKNESS     1
    /**
     * @def POINT_RADIUS
     * @brief Point Radius Configuration
     * @details This Macro Defines the Radius of the Point
     */
    # define POINT_RADIUS                          1
    /**
     * @def POINT_THICKNESS
     * @brief Point Thickness Configuration
     * @details This Macro Defines the Thickness of the Point
     */
    # define POINT_THICKNESS                       -1
    /**
     * @def POINT_COLOR
     * @brief Point Color Configuration
     * @details This Macro Defines the Color of the Point
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define POINT_COLOR                           cv::Scalar(170, 170, 0)
    /**
     * @def POINT_RING_RADIUS
     * @brief Point Ring Radius Configuration
     * @details This Macro Defines the Radius of the Ring around the Point
     */
    # define POINT_RING_RADIUS                     7
    /**
     * @def POINT_RING_LINE_BEGIN
     * @brief Point Ring Line Begin Configuration
     * @details This Macro Defines the Begin Distance of the Lines around the Point
     */
    # define POINT_RING_LINE_BEGIN                 POINT_RING_RADIUS - 2
    /**
     * @def POINT_RING_LINE_SIZE
     * @brief Point Ring Line Size Configuration
     * @details This Macro Defines the Size of the Lines around the Point
     */
    # define POINT_RING_LINE_SIZE                  9
    /**
     * @def POINT_RING_COLOR
     * @brief Point Ring Color Configuration
     * @details This Macro Defines the Color of the Ring around the Point
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define POINT_RING_COLOR                      cv::Scalar(90, 209, 137)
    /**
     * @def POINT_RING_LINE_COLOR
     * @brief Point Ring Line Color Configuration
     * @details This Macro Defines the Color of the Lines around the Point
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define POINT_RING_LINE_COLOR                 cv::Scalar(76, 147, 22)
    /**
     * @def POINT_RING_THICKNESS
     * @brief Point Ring Thickness Configuration
     * @details This Macro Defines the Thickness of the Ring around the Point
     */
    # define POINT_RING_THICKNESS                  1
    /**
     * @def LINE_TICKNESS
     * @brief Line Thickness Configuration
     * @details This Macro Defines the Thickness of the Line
     */
    # define LINE_TICKNESS                         1
    /**
     * @def LINE_COLOR
     * @brief Line Color Configuration
     * @details This Macro Defines the Color of the Line
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define LINE_COLOR                            cv::Scalar(0, 255, 255)
    /**
     * @def LINE_WEIGHT_TEXT_SIZE
     * @brief Line Weight Text Size Configuration
     * @details This Macro Defines the Size of the Text for Line Weight
     */
    # define LINE_WEIGHT_TEXT_SIZE                 0.6
    /**
     * @def LINE_WEIGHT_TEXT_THICKNESS
     * @brief Line Weight Text Thickness Configuration
     * @details This Macro Defines the Thickness of the Text for Line Weight
     */
    # define LINE_WEIGHT_TEXT_THICKNESS            2
    /**
     * @def LINE_WEIGHT_TEXT_COLOR
     * @brief Line Weight Text Color Configuration
     * @details This Macro Defines the Color of the Text for Line Weight
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define LINE_WEIGHT_TEXT_COLOR                cv::Scalar(60, 0, 0)
    /**
     * @def LINE_WEIGHT_BACKGROUND_COLOR
     * @brief Line Weight Background Color Configuration
     * @details This Macro Defines the Background Color of the Text for Line Weight
     * @note Color Object Must be cv::Scalar
     * @note Format Must be BGR
     */
    # define LINE_WEIGHT_BACKGROUND_COLOR          cv::Scalar(217, 245, 177)
    /**
     * @def LINE_WEIGHT_BACKGROUND_PADDING
     * @brief Line Weight Background Padding Configuration
     * @details This Macro Defines the Padding of the Background of the Text for Line Weight
     */
    # define LINE_WEIGHT_BACKGROUND_PADDING        6
    /**
     * @def SHOW_FRAME_THRESHOLD
     * @brief Show Frame Threshold Configuration
     * @details This Macro Defines the Threshold for Showing the Frame After Amount of Frame Update
     */
    # define SHOW_FRAME_THRESHOLD                  30
    /**
     * @enum ENUM_ALGORITHM_ENVIRONMENT
     * @brief Algorithm Environment
     * @details This Enum Defines the Environment of the Algorithm
     * @param ENVIRONMENT_1D 1D Environment
     * @param ENVIRONMENT_2D 2D Environment
     * @param ENVIRONMENT_3D 3D Environment
     */
    enum ENUM_ALGORITHM_ENVIRONMENT {
        ENVIRONMENT_1D,
        ENVIRONMENT_2D,
        ENVIRONMENT_3D
    };
    /**
     * @enum ENUM_SHOW_POINT_METHODS
     * @brief Show Point Methods Enum
     * @details This Enum Defines the Method of Showing the Point
     * @param SHOW_POINT_INFO_BOX Show Point with Info Box
     * @param SHOW_POINT_NORMAL Show Point Normal
     * @param SHOW_POINT_RING Show Ring around Point
     */
    enum ENUM_SHOW_POINT_METHODS {
        SHOW_POINT_INFO_BOX,
        SHOW_POINT_NORMAL,
        SHOW_POINT_RING
    };
    /**
     * @enum ENUM_SHOW_LINE_METHODS
     * @brief Show Line Methods Enum
     * @details This Enum Defines the Method of Showing the Line
     * @param SHOW_LINE_NORMAL Show Line Normal
     * @param SHOW_LINE_WEIGHTED Show Line Weighted
     */
    enum ENUM_SHOW_LINE_METHODS {
        SHOW_LINE_NORMAL,
        SHOW_LINE_WEIGHTED
    };
    /**
     * @enum ENUM_SHOW_WINDOW_MODE
     * @brief Show on Window Mode Enum
     * @details This Enum Defines the Mode of Showing on the Window
     * @param SHOW_ON_MAIN_WINDOW Show on Main Window
     * @param SHOW_ON_TEMP_WINDOW Show on Temp Window
     */
    enum ENUM_SHOW_WINDOW_MODE {
        SHOW_ON_MAIN_WINDOW,
        SHOW_ON_TEMP_WINDOW
    };
    /**
     * @namespace env
     * @brief Environment Namespace
     * @details This Namespace Contains All the Environment Classes for Algorithms
     * @param Point2D 2D Point Class
     * @param Point3D 3D Point Class
     * @param Box2D 2D Box Class
     * @param Box3D 3D Box Class
     * @note All the Environment Properties Classes are Defined in this Namespace
     */
    namespace env {
        /**
         * @class Point2D
         * @brief 2D Point Class Definition
         * @details This Class Contains the Definition of 2D Point and Its Properties
         * 
         * @param x X Coordinate
         * @param y Y Coordinate
         * @param theta Angle
         * @param color Color
         * 
         * @note All the Properties are Public
         * @note Method has Constructor with Parameters
         * @note Method has Constructor without Parameters
         * 
         * @warning This Class is Defined in @ref env Namespace
         * @warning This Class Can be Used in 2D Environment Only
         * 
         * @see ENUM_ALGORITHM_ENVIRONMENT
         */
        class Point2D {
            public:
                /**
                 * @brief X - Axis Coordinate
                 * @details This Variable Contains the X - Axis Coordinate of the Point
                 */
                double x;
                /**
                 * @brief Y - Axis Coordinate
                 * @details This Variable Contains the Y - Axis Coordinate of the Point
                 */
                double y;
                /**
                 * @brief Angle
                 * @details This Variable Contains the Angle of the Point
                 */
                double theta;
                /**
                 * @brief Color
                 * @details This Variable Contains the Color of the Point
                 * @note Color Object Must be cv::Scalar
                 * @note Format Must be BGR
                 */
                cv::Scalar color;
                /**
                 * @brief Constructor
                 * @details This Constructor Initializes the Point with Default Values
                 */
                Point2D();
                /**
                 * @brief Constructor with Parameters
                 * @details This Constructor Initializes the Point with Given Parameters
                 * 
                 * @param _x X Coordinate
                 * @param _y Y Coordinate
                 * @param _theta Angle
                 * @param _color Color
                 */
                Point2D(
                    double          _x,
                    double          _y,
                    double          _theta,
                    cv::Scalar      _color
                );
        };
        /**
         * @class Point3D
         * @brief 3D Point Class Definition
         * @details This Class Contains the Definition of 3D Point and Its Properties
         * 
         * @param x X Coordinate
         * @param y Y Coordinate
         * @param z Z Coordinate
         * @param theta Angle
         * @param color Color
         * 
         * @note All the Properties are Public
         * @note Method has Constructor with Parameters
         * @note Method has Constructor without Parameters
         * 
         * @warning This Class is Defined in @ref env Namespace
         * @warning This Class Can be Used in 3D Environment Only
         * 
         * @see ENUM_ALGORITHM_ENVIRONMENT
         */
        class Point3D {
            public:
                /**
                 * @brief X - Axis Coordinate
                 * @details This Variable Contains the X - Axis Coordinate of the Point
                 */
                double x;
                /**
                 * @brief Y - Axis Coordinate
                 * @details This Variable Contains the Y - Axis Coordinate of the Point
                 */
                double y;
                /**
                 * @brief Z - Axis Coordinate
                 * @details This Variable Contains the Z - Axis Coordinate of the Point
                 */
                double z;
                /**
                 * @brief Angle
                 * @details This Variable Contains the Angle of the Point
                 */
                double theta;
                /**
                 * @brief Color
                 * @details This Variable Contains the Color of the Point
                 * @note Color Object Must be cv::Scalar
                 * @note Format Must be BGR
                 */
                cv::Scalar color;
                /**
                 * @brief Constructor
                 * @details This Constructor Initializes the Point with Default Values
                 */
                Point3D();
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
                Point3D(
                    double      &   _x,
                    double      &   _y,
                    double      &   _z,
                    double      &   _theta,
                    cv::Scalar  &   _color
                );
        };
        /**
         * @class Point3D
         * @brief 3D Point Class Definition
         * @details This Class Contains the Definition of 3D Point and Its Properties
         * 
         * @param x X Coordinate
         * @param y Y Coordinate
         * @param z Z Coordinate
         * @param theta Angle
         * @param color Color
         * 
         * @note All the Properties are Public
         * @note Method has Constructor with Parameters
         * @note Method has Constructor without Parameters
         * 
         * @warning This Class is Defined in @ref env Namespace
         * @warning This Class Can be Used in 3D Environment Only
         * 
         * @see ENUM_ALGORITHM_ENVIRONMENT
         */
        /**
         * @class Box2D
         * @brief 2D Box Class Definition
         * @details This Class Contains the Definition of 2D Box and Its Properties
         * 
         * @param topLeft Top Left Point
         * @param bottomRight Bottom Right Point
         * 
         * @note All the Properties are Public
         * @note Method has Default Constructor
         * 
         * @warning This Class is Defined in @ref env Namespace
         * @warning This Class Can be Used in 2D Environment Only
         * 
         * @see ENUM_ALGORITHM_ENVIRONMENT
         */
        class Box2D {
            public:
                /**
                 * @brief Top Left Point
                 * @details This Variable Contains the Top Left Point of the Box
                 */
                Point2D topLeft;
                /**
                 * @brief Bottom Right Point
                 * @details This Variable Contains the Bottom Right Point of the Box
                 */
                Point2D bottomRight;
                /**
                 * @brief Constructor
                 * @details This Constructor Initializes the Box with Default Values
                 */
                Box2D();
        };
        /**
         * @class Box3D
         * @brief 3D Box Class Definition
         * @details This Class Contains the Definition of 3D Box and Its Properties
         * 
         * @param topDiamPoint Top Diameter Point
         * @param downDiamPoint Down Diameter Point
         * 
         * @note All the Properties are Public
         * @note Method has Default Constructor
         * 
         * @warning This Class is Defined in @ref env Namespace
         * @warning This Class Can be Used in 3D Environment Only
         * 
         * @see ENUM_ALGORITHM_ENVIRONMENT
         */
        class Box3D {
            public:
                /**
                 * @brief Top Diameter Point
                 * @details This Variable Contains the Top Diameter Point of the Box
                 */
                Point3D topDiamPoint;
                /**
                 * @brief Down Diameter Point
                 * @details This Variable Contains the Down Diameter Point of the Box
                 */
                Point3D downDiamPoint;
                /**
                 * @brief Constructor
                 * @details This Constructor Initializes the Box with Default Values
                 */
                Box3D();
        };
    }
    /**
     * @enum ENUM_MOUSE_STATE
     * @brief Mouse State Enum
     * @details This Enum Defines the State of the Mouse
     * @param EVENTS_INACTIVE Mouse Events are Inactive
     * @param EVENTS_ACTIVE Mouse Events are Active
     */
    enum class ENUM_MOUSE_STATE {
        EVENTS_INACTIVE,
        EVENTS_ACTIVE
    };
    /**
     * @class Graphics
     * @brief Graphics Class Definition
     * @details This Class Contains the Definition of Graphics and Its Properties
     * 
     * @param environment Environment
     * @param window Window Matrix
     * @param tmp_windows Temp Windows
     * @param points2D 2D Points Instance
     * @param points3D 3D Points Instance
     * 
     * @note All the Properties are Private
     * @note Method has Constructor with Parameters
     * 
     * @warning This Class is Defined in @ref env Namespace
     * @warning This Class Can be Used in 2D and 3D Environment Only
     * 
     * @see ENUM_ALGORITHM_ENVIRONMENT
     */
    class Graphics {
        private:
            /**
             * @brief Environment
             * @details This Variable Contains the Environment of the Algorithm
             * 
             * @note Environment Must be ENUM_ALGORITHM_ENVIRONMENT
             * 
             * @see ENUM_ALGORITHM_ENVIRONMENT
             */
            ENUM_ALGORITHM_ENVIRONMENT environment;
            /**
             * @struct SCREEN
             * @brief Screen Structure
             * @details This Structure Contains the Screen Properties as Follows:
             * @param width Width
             * @param height Height
             */
            struct STRUCT_SCREEN {
                /**
                 * @brief Width
                 * @details This Variable Contains the Width of the Screen
                 */
                int width;
                /**
                 * @brief Height
                 * @details This Variable Contains the Height of the Screen
                 */
                int height;
                /**
                 * @struct STRUCT_SCREEN_CENTER
                 * @brief Screen Center Structure
                 * @details This Structure Contains the Screen Center Properties as Follows:
                 * @param x X Center
                 * @param y Y Center
                 */
                struct STRUCT_SCREEN_CENTER {
                    /**
                     * @brief X Center
                     * @details This Variable Contains the X Center of the Screen
                     */
                    int x;
                    /**
                     * @brief Y Center
                     * @details This Variable Contains the Y Center of the Screen
                     */
                    int y;
                } center;
            } screen;
            /**
             * @brief Mouse State
             * @details This Variable Contains the State of the Mouse
             * 
             * @note Mouse State Must be ENUM_MOUSE_STATE
             * 
             * @see ENUM_MOUSE_STATE
             */
            ENUM_MOUSE_STATE mouseState;
        public:
            /**
             * @struct STRUCT_WINDOWS
             * @brief Graphics Windows Structure
             * @details This Structure Contains the Windows Properties as Follows:
             * @param main Main Window
             * @param info Info Window
             */
            struct STRUCT_WINDOWS {
                /**
                 * @struct STRUCT_MAIN_WINDOW
                 * @brief Main Window Structure
                 * @details This Structure Contains the Main Window Properties as Follows:
                 */
                struct STRUCT_MAIN_WINDOW {
                    /**
                     * @brief Matrix
                     * @details This Variable Contains the Matrix of the Main Window
                     * 
                     * @note Matrix Must be cv::Mat
                     */
                    cv::Mat matrix;
                    /**
                     * @struct STRUCT_MAIN_WINDOW_POSITION
                     * @brief Main Window Position Structure
                     * @details This Structure Contains the Main Window Position Properties as Follows:
                     * @param x X Position
                     * @param y Y Position
                     */
                    struct STRUCT_MAIN_WINDOW_POSITION {
                        /**
                         * @brief X Position
                         * @details This Variable Contains the X Position of the Main Window
                         */
                        int x;
                        /**
                         * @brief Y Position
                         * @details This Variable Contains the Y Position of the Main Window
                         */
                        int y;
                    } position;
                } main;
                /**
                 * @struct STRUCT_INFO_WINDOW
                 * @brief Info Window Structure
                 * @details This Structure Contains the Info Window Properties as Follows:
                 */
                struct STRUCT_INFO_WINDOW {
                    /**
                     * @brief Matrix
                     * @details This Variable Contains the Matrix of the Info Window
                     * 
                     * @note Matrix Must be cv::Mat
                     */
                    cv::Mat matrix;
                    /**
                     * @struct STRUCT_INFO_WINDOW_POSITION
                     * @brief Info Window Position Structure
                     * @details This Structure Contains the Info Window Position Properties as Follows:
                     * @param x X Position
                     * @param y Y Position
                     */
                    struct STRUCT_INFO_WINDOW_POSITION {
                        /**
                         * @brief X Position
                         * @details This Variable Contains the X Position of the Info Window
                         */
                        int x;
                        /**
                         * @brief Y Position
                         * @details This Variable Contains the Y Position of the Info Window
                         */
                        int y;
                    } position;
                } info;
                /**
                 * @struct STRUCT_TEMP_WINDOWS
                 * @brief Temp Windows Structure
                 * @details This Structure Contains the Temporary Windows Properties as Follows:
                 * @param temp1 Temp Window 1
                 * @param temp2 Temp Window 2
                 * @param temp3 Temp Window 3
                 * @param temp4 Temp Window 4
                 * @param temp5 Temp Window 5
                 */
                struct STRUCT_TEMP_WINDOW {
                    /**
                     * @brief Matrix
                     * @details This Variable Contains the Matrix of the Temp Window
                     * 
                     * @note Matrix Must be cv::Mat
                     */
                    cv::Mat matrix;
                    /**
                     * @struct STRUCT_TEMP_WINDOW_POSITION
                     * @brief Temp Window Position Structure
                     * @details This Structure Contains the Temp Window Position Properties as Follows:
                     * @param x X Position
                     * @param y Y Position
                     */
                    struct STRUCT_TEMP_WINDOW_POSITION {
                        /**
                         * @brief X Position
                         * @details This Variable Contains the X Position of the Temp Window
                         */
                        int x;
                        /**
                         * @brief Y Position
                         * @details This Variable Contains the Y Position of the Temp Window
                         */
                        int y;
                    } position;
                } temp1, temp2, temp3, temp4, temp5;
            } windows;
            /**
             * @brief 2D Points Instance
             * @details This Variable Contains the 2D Points Instance
             * 
             * @note 2D Points Instance Must be std::vector<env::Point2D>
             */
            std::vector<env::Point2D> points2D;
            /**
             * @brief 3D Points Instance
             * @details This Variable Contains the 3D Points Instance
             * 
             * @note 3D Points Instance Must be std::vector<env::Point3D>
             */
            std::vector<env::Point3D> points3D;
            /**
             * @brief Constructor with Parameters
             * @details This Constructor Initializes the Graphics with Given Parameters
             * 
             * @param _environment Environment
             */
            Graphics(
                ENUM_ALGORITHM_ENVIRONMENT _environment = ENVIRONMENT_2D
            );
            /**
             * @brief Destructor
             * @details This Destructor Destroys the Graphics
             */
            ~Graphics();
            /**
             * @brief Method to Generate Info Window GUI
             * @details This Method Generates the Info Window GUI
             */
            void generateInfoWindow();
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
            static void onMouseCallback(int event, int x, int y, int flags, void* userdata);
            /**
             * @brief Mouse Events Method
             * @details This Method Handles the Mouse Events
             * 
             * @param event Event
             * @param x X - Axis Coordinate
             * @param y Y - Axis Coordinate
             * @param flags Flags
             */
            void onMouse(int event, int x, int y, int flags);
            /**
             * @brief Method to Draw Point
             * @details This Method Draws a Point on the Screen
             * 
             * @param point Point
             * @param add_to_points Add to Points
             * @param show_flag Show Flag
             * @param method Method
             * @param window_mode Window Mode
             */
            void drawPoint(
                env::Point2D point,
                bool add_to_points,
                bool show_flag,
                ENUM_SHOW_POINT_METHODS show_method,
                ENUM_SHOW_WINDOW_MODE window_method
            );
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
             * @param window_method Window Method
             * @param weight Line Weight
             */
            void drawLine(
                env::Point2D point1,
                env::Point2D point2,
                std::string weight,
                cv::Scalar color,
                int thickness,
                bool add_to_lines,
                bool show_flag,
                ENUM_SHOW_LINE_METHODS show_method,
                ENUM_SHOW_WINDOW_MODE window_method
            );
            void drawText(
                std::string text,
                env::Point2D point,
                cv::Scalar color,
                double size,
                int thickness
            );
    };
    /**
     * @class EXCEPTION_GRAPHICS
     * @brief Graphics Exception Class Definition
     * @details This Class Contains the Definition of Graphics Exception and Its Properties
     * 
     * @param message Message
     * 
     * @note All the Properties are Private
     * @note Method has Constructor with Parameters
     * @note Method has what() Method
     */
    class EXCEPTION_GRAPHICS : public std::exception {
        private:
            /**
             * @brief Message
             * @details This Variable Contains the Message of the Exception
             */
            std::string message_;
        public:
            /**
             * @brief Constructor with Parameters
             * @details This Constructor Initializes the Graphics Exception with Given Parameters
             * 
             * @param message Message
             */
            explicit EXCEPTION_GRAPHICS(const std::string& message)
                : message_(message) {}
            /**
             * @brief what() Method
             * @details This Method Returns the Message of the Exception
             * 
             * @return Message
             */
            virtual const char* what() const noexcept override {
                return message_.c_str();
            }
    };
# endif // GRAPHICS_OMID_SOJOODI