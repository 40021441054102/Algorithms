# ifndef GRAPHICS_OMID_SOJOODI
    /**
     * @file Graphics.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Graphis Header File
     * @version 0.1
     * @date 2024-04-14
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
    //-- Include X11
    # ifndef _X11_XLIB_H_
        # include <X11/Xlib.h>
    # endif // _X11_XLIB_H_
    //-- Include Needed Libraries
    # ifndef _GLIBCXX_IOSTREAM
        # include <iostream>
    # endif // _GLIBCXX_IOSTREAM
    //-- Define Log Messages
    # define WARNING "\033[38;2;255;255;0m[WARNING]\033[0m "
    # define SUCCESS "\033[38;2;0;255;0m[SUCCESS]\033[0m "
    # define ERROR "\033[38;2;255;0;0m[ERROR]\033[0m "
    # define INFO "\033[38;2;0;255;255m[INFO]\033[0m "
    # define LOG "\033[38;2;170;170;170m[LOG]\033[0m "
    # define RESET "\033[0m"
    # define TAB "   "
    //-- Window Configurations
    # define WINDOW_WIDTH                           1200
    # define WINDOW_HEIGHT                          1200
    # define WINDOW_NAME                            "Graphical View"
    # define WINDOW_BACKGROUND                      cv::Scalar(20, 10, 0)
    //-- Information Window Configurations
    # define INFO_WINDOW_WIDTH                      WINDOW_WIDTH / 4
    # define INFO_WINDOW_HEIGHT                     WINDOW_HEIGHT / 4
    # define INFO_WINDOW_NAME "Info"
    //-- Colors and Shapes Propetries
    # define COLOR_CYAN                             cv::Scalar(255, 255, 0)
    # define COLOR_CYAN_DARK                        cv::Scalar(170, 170, 0)
    /**
     * @brief Algorithms Environment
     */
    enum ENUM_ALGORITHM_ENVIRONMENT {
        ENVIRONMENT_1D,
        ENVIRONMENT_2D,
        ENVIRONMENT_3D
    };
    /**
     * @brief Environment Related Namespace
     */
    namespace env {
        /**
         * @brief 2D Point Class Definition
         */
        class Point2D {
            public:
                //-- X and Y
                double x, y;
                //-- Angle
                double theta;
                //-- Color
                cv::Scalar color;
                //-- Constructor
                Point2D();
                //-- Constructor with Parameters
                Point2D(
                    double      &   _x,
                    double      &   _y,
                    double      &   _theta,
                    cv::Scalar  &   _color
                );
        };
        /**
         * @brief 3D Point Class Definition
         */
        class Point3D {
            public:
                //-- X, Y and Z
                double x, y, z;
                //-- Angle
                double theta;
                //-- Color
                cv::Scalar color;
                //-- Constructor
                Point3D();
                //-- Constructor with Parameters
                Point3D(
                    double      &   _x,
                    double      &   _y,
                    double      &   _z,
                    double      &   _theta,
                    cv::Scalar  &   _color
                );
        };
        /**
         * @brief 2D Box Class Definition
         */
        class Box2D {
            public:
                //-- Top Left Point
                Point2D topLeft;
                //-- Bottom Right Point
                Point2D bottomRight;
                //-- Constructor
                Box2D();
        };
        /**
         * @brief 3D Box Class Definition
         */
        class Box3D {
            public:
                //-- Top Diameter Point
                Point3D topDiamPoint;
                //-- Down Diameter Point
                Point3D downDiamPoint;
                //-- Constructor
                Box3D();
        };
    }
    /**
     * @brief Mouse States
     */
    enum class ENUM_MOUSE_STATE {
        EVENTS_INACTIVE,
        EVENTS_ACTIVE
    };
    /**
     * @brief Class to Handle Graphics
     */
    template <typename _type> class Graphics {
        private:
            //-- Environment
            ENUM_ALGORITHM_ENVIRONMENT environment;
            //-- Window Matrix
            cv::Mat window;
            //-- Temp Windows
            std::vector<cv::Mat> tmp_windows;
            //-- 2D Points Instance
            std::vector<env::Point2D> points2D;
            //-- 3D Points Instance
            std::vector<env::Point3D> points3D;
        public:
            //-- Graphics Construct,or
            Graphics(
                ENUM_ALGORITHM_ENVIRONMENT      &   _environment
            );
    };
# endif // GRAPHICS_OMID_SOJOODI

/**
 * @brief Notes
 * @note add color to lines of 2D and 3D box
 * 
 */
# define NOTES_GRAPHICS

    //-- Include Needed Libraries
    // # include <iostream>
    // # include <chrono>
    // # include <string>
    // # include <vector>
    // # include <map>
    // # include <algorithm>
    // # include <thread>
    // # include <mutex>
    // # include <condition_variable>
    // # include <future>
    // # include <random>
    // # include <fstream>
    // # include <sstream>
    // # include <iomanip>
    // # include <cmath>
    // # include <limits>
    // # include <numeric>
    // # include <functional>
    // # include <utility>
    // # include <memory>
    // # include <stdexcept>
    // # include <type_traits>
    // # include <initializer_list>
    // # include <tuple>
    // # include <array>
    // # include <list>
    // # include <forward_list>
    // # include <deque>
    // # include <queue>
    // # include <stack>
    // # include <set>
    // # include <unordered_set>
    // # include <map>
    // # include <unordered_map>
    // # include <iterator>
    // # include <algorithm>
    // # include <regex>
    // # include <atomic>
    // # include <cctype>
    // # include <locale>
    // # include <codecvt>
    // # include <optional>
    // # include <variant>
    // # include <any>
    // # include <charconv>
    // # include <execution>
    // # include <filesystem>
    // # include <memory_resource>
    // # include <numeric>
    // # include <ranges>
    // # include <compare>
    // # include <format>
    // # include <source_location>
    // # include <stop_token>
    // # include <syncstream>
    // # include <bit>
    // # include <concepts>
    // # include <coroutine>
    // # include <latch>
    // # include <barrier>
    // # include <semaphore>
    // # include <jthread>
    // # include <syncstream>
    // # include <version>
    // # include <typeindex>
    // # include <typeinfo>
    // # include <type_traits>
    // # include <typeindex>
    // # include <typeinfo>
    // # include <type_traits>
    // # include <utility>
    // # include <valarray>
    // # include <variant>
    // # include <version>
    // # include <version>
    // # include <version>