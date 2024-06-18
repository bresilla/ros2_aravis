cmake_minimum_required(VERSION 3.16...3.27)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(ros2_aravis)


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

# include(FetchContent)
# FetchContent_Declare(fmt
#   GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#   GIT_TAG master
# )
# FetchContent_MakeAvailable(fmt)

include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Aravis REQUIRED)
find_package(GLIB REQUIRED)
find_package(GStreamer REQUIRED)

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
find_package(rosidl_default_generators REQUIRED)

# find_package(rerun_sdk REQUIRED)
# find_package(fmt REQUIRED)

set(ros_dependencies
  rclcpp
  std_msgs
  std_srvs
  lifecycle_msgs
  rclcpp_lifecycle
  sensor_msgs
  cv_bridge
  image_transport
  # fmt
  # rerun_sdk
  GLIB
  Aravis
  OpenCV
)


rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/CameraDevice.msg"
  "msg/CameraDeviceArray.msg"
  "srv/AskCamera.srv"
  "srv/TriggerCamera.srv"
  "srv/TriggerCapture.srv"
)
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")


add_library(Camera src/Camera.cpp)
ament_target_dependencies(Camera ${ros_dependencies})

add_executable(pack 
  src/Camera.cpp
  src/main.cpp)
ament_target_dependencies(pack ${ros_dependencies})
target_link_libraries(pack "${cpp_typesupport_target}")

# target_link_libraries(pack Camera)


install(TARGETS
  pack
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY cmake DESTINATION share/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})


ament_package()