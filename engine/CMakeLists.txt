set(BASE_DIR "${PROJECT_SOURCE_DIR}/engine")

set (ENGINE_INCLUDE_DIR "${BASE_DIR}/include" CACHE INTERNAL "")
set (PROJECT_SRC_DIR     "${BASE_DIR}/src")

# Gets the list of files inside the src directory
file(GLOB_RECURSE SOURCES "${PROJECT_SRC_DIR}/*.cpp" "${PROJECT_SRC_DIR}/*.c")

include_directories("${ENGINE_INCLUDE_DIR}")

add_library(engine STATIC ${SOURCES})
