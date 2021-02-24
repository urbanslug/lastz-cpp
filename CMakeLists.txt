cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(mashz VERSION 0.0.1)

include(GNUInstallDirs)
include(CheckCXXCompilerFlag)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)                          # Falling back to different standard it not allowed.
set(CMAKE_CXX_EXTENSIONS OFF)                                # Make sure no compiler-specific features are used.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -mcx16 -march=native -g -fpermissive -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mcx16 -march=native -g -fpermissive -fsanitize=address")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src/lastz EXCLUDE_FROM_ALL)

add_executable(lastz-cpp
  src/main.cpp) #$(CXX) $(CXXFLAGS) $(CPPFLAGS) -Lsrc/lastz/build/lib $(SOURCE_1) -o mashz -llastz

target_include_directories(lastz-cpp PRIVATE
  src/lastz)

target_link_libraries(lastz-cpp
  lastz)

install(TARGETS lastz-cpp DESTINATION bin)
