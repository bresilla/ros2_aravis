cmake_minimum_required(VERSION 3.8)
project(ros2_aravis)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
  add_compile_options(-Wall -Wextra -Wpedantic -Wunknown-pragmas)
endif()

# include(FetchContent)
# FetchContent_Declare(rerun_sdk URL
#     https://github.com/rerun-io/rerun/releases/latest/download/rerun_cpp_sdk.zip)
# FetchContent_MakeAvailable(rerun_sdk)

include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Aravis REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(lifecycle_msgs REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(fmt REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(ros_dependencies
  rclcpp
  std_msgs
  std_srvs
  lifecycle_msgs
  rclcpp_lifecycle
  sensor_msgs
  cv_bridge
  image_transport
  Aravis
  OpenCV
  fmt
)


rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/CameraDevice.msg"
  "msg/CameraDeviceArray.msg"
  "srv/AskCamera.srv"
  "srv/TriggerCamera.srv"
  "srv/TriggerCapture.srv"
)
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(pack src/main.cpp)
ament_target_dependencies(pack ${ros_dependencies})
target_link_libraries(pack "${cpp_typesupport_target}")


install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY cmake DESTINATION share/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})


ament_package()