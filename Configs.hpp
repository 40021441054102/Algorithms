//-- Configuration File
# ifndef ALGORITHMS_OMID_SOJOODI_CONFIGS
    /**
     * @file Configs.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Configurations Header File
     * @date 2024-06-07
     * @def ALGORITHMS_OMID_SOJOODI_CONFIGS
     * @brief Configurations Header File Macro
     * @details This Header File Contains Configurations
     */
    # define ALGORITHMS_OMID_SOJOODI_CONFIGS
    /**
     * @def WARNING
     * @brief Warning Message
     * @details This Macro Defines Warning Message Log Label for Algorithms Class
     */
    # define WARNING "\033[38;2;255;255;0m[WARNING]\033[0m "
    /**
     * @def SUCCESS
     * @brief Success Message
     * @details This Macro Defines Success Message Log Label for Algorithms Class
     */
    # define SUCCESS "\033[38;2;0;255;0m[SUCCESS]\033[0m "
    /**
     * @def ERROR
     * @brief Error Message
     * @details This Macro Defines Error Message Log Label for Algorithms Class
     */
    # define ERROR "\033[38;2;255;0;0m[ERROR]\033[0m "
    /**
     * @def INFO
     * @brief Information Message
     * @details This Macro Defines Information Message Log Label for Algorithms Class
     */
    # define INFO "\033[38;2;0;255;255m[INFO]\033[0m "
    /**
     * @def LOG
     * @brief Log Message
     * @details This Macro Defines Log Message Log Label for Algorithms Class
     */
    # define LOG "\033[38;2;170;170;170m[LOG]\033[0m "
    /**
     * @def MODULE
     * @brief Module Message
     * @details This Macro Defines Module Message Log Label for Algorithms Class Modules
     */
    # define MODULE "\033[38;2;93;255;170m[MODULE]\033[0m "
    /**
     * @def RESET
     * @brief Reset Message
     * @details This Macro Resets Log Message Format
     */
    # define RESET "\033[0m"
    /**
     * @def TAB
     * @brief Tab Message
     * @details This Macro Adds Tab to Log Messages
     */
    # define TAB "   "
    //-- Include IOStream
    # ifndef _GLIBCXX_IOSTREAM
        # include <iostream>
    # endif // _GLIBCXX_IOSTREAM
# endif // ALGORITHMS_OMID_SOJOODI_CONFIGS