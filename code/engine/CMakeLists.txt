set(BASE_DIR "${PROJECT_SOURCE_DIR}/code/engine")

set (ENGINE_INCLUDE_DIR "${BASE_DIR}/include" CACHE INTERNAL "")
set (SRC_DIR     "${BASE_DIR}/src")

# Gets the list of files inside the src directory
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.c")

include_directories("${ENGINE_INCLUDE_DIR}")

add_library(engine STATIC ${SOURCES})

#### Install ####

install(TARGETS engine
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)
