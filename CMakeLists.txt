cmake_minimum_required(VERSION 3.10)

project(SensorsPlayer
    VERSION     0.1.0
    LANGUAGES   CXX
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(FFmpeg COMPONENTS AVCODEC AVUTIL REQUIRED)

add_library(sensors
    ${CMAKE_CURRENT_SOURCE_DIR}/include/libsensors.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libsensors/libsensors.cpp
)

target_compile_features(sensors
    PRIVATE
        cxx_std_17
)

target_include_directories(sensors
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${FFMPEG_INCLUDE_DIRS}
)

target_link_libraries(sensors
    PRIVATE
        Eigen3::Eigen
        ${FFMPEG_LIBRARIES}
)

add_executable(sensors-preview
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sensors-preview/main.cpp
)

target_compile_features(sensors-preview
    PUBLIC
        cxx_std_17
)

target_link_libraries(sensors-preview
    sensors
    ${OpenCV_LIBS}
)
