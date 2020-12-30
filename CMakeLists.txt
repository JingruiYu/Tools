cmake_minimum_required(VERSION 2.8)
project(Tools)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

find_package(OpenCV 3.0 QUIET)
find_package(Eigen3 REQUIRED)
find_package(PCL 1.8 REQUIRED)

set(NDT_OMP_INCLUDE_DIR /home/yujr/ros_catkin/src/ndt_omp/include)
set(NDT_OMP_LIB_DIR /home/yujr/ros_catkin/devel/lib)

include_directories(
    include
    ${OPENCV_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${PCL_INCLUDE_DIRS}
    ${NDT_OMP_INCLUDE_DIR}
)

link_directories(
   ${PCL_LIBRARY_DIRS}
   ${NDT_OMP_LIB_DIR}
)

add_library(${PROJECT_NAME}
    src/forTxt.cc
    src/Eigen_CV_G2O_Convert.cc
    src/pclDraw.cc
)

target_link_libraries(${PROJECT_NAME}
${OpenCV_LIBS}
${EIGEN3_LIBS}
${PCL_LIBRARIES}
ndt_omp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/examples)

add_executable(drawPC tool/drawPC.cc)
target_link_libraries(drawPC ${PROJECT_NAME})