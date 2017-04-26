#ifndef LOG_MACROS_H
#define LOG_MACROS_H

/**
 * This library defines macros to log your program.
 */

#include <iostream>
#include <cstdlib>

/* In the release version define NDEBUG macro */
// #define NDEBUG  // Clears out the DEBUG macro
// #define NWARN   // Clears out the WARN macro
// #define NASSERT // Clears out the ASSERT macro
// #define NINFO   // Clears out the INFO macro
// #define NERROR  // Clears out the ERROR macro


/*
 * INFO macro prints a message in the screen using the std iostream
 **/

#ifndef NINFO
#   define INFO(...) \
        std::cout << "[INFO] " << __VA_ARGS__ << std::endl;
#else
#   define INFO(...)
#endif

/*
 * WARN macro prints a message in the screen using the std iostream
 **/

#ifndef NWARN
#   define WARN(...) \
        std::cout << "[WARN] " << __VA_ARGS__ << std::endl;
#else
#   define WARN(...)
#endif

/*
 * ERROR macro raises and error and exit the program with faliure status
 **/

#ifndef NERROR
#   define ERROR(...)                                                         \
    do {                                                                      \
        std::cout << "[ERROR] " << __FILE__ << " line " << __LINE__           \
                  << std::endl << __VA_ARGS__ << std::endl;                   \
        std::exit(EXIT_FAILURE);                                              \
    } while (false)
#else
#   define ERROR(...)
#endif

/**
 * DEBUG macro prints a message in the screen using the std error output
 * If you already have a DEBUG macro defined this macro does not have any
 * effect.
 */

#ifndef DEBUG
    #ifndef NDEBUG
    #   define DEBUG(...) \
            std::cerr << "[DEBUG] " << __VA_ARGS__ << std::endl;
    #else
    #   define DEBUG(...)
    #endif
#endif

/**
 * ASSERT macro tests a condition and if it returns false, stops the program
 *    and prints a message
 * Source:
 *   http://stackoverflow.com/questions/3767869/adding-message-to-assert
 **/

#ifndef NASSERT
#   define ASSERT(condition, ...) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << __VA_ARGS__ << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
    } while (false)
#else
#   define ASSERT(condition, ...)
#endif

#endif
