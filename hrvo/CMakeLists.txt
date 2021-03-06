cmake_minimum_required(VERSION 2.8.3)
project(hrvo)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  nav_msgs
  message_generation
)
## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
add_service_files(
  FILES
  AddAgentService.srv
)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  geometry_msgs
  nav_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  #  LIBRARIES hrvo
  CATKIN_DEPENDS roscpp std_msgs geometry_msgs nav_msgs message_runtime
  #  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(Agent src/Agent.cpp )
add_library(Goal src/Goal.cpp)
add_library(KdTree src/KdTree.cpp)
add_library(Simulator src/Simulator.cpp)
add_library(Vector2 src/Vector2.cpp)
# add_library(AMCLWrapper src/AMCLWrapper.cpp)


#set(HRVO_HEADERS
#	src/HRVO.h
#	src/Simulator.h
#	src/Vector2.h)

#set(HRVO_SOURCES
#	src/Agent.cpp
#	src/Agent.h
#	src/Definitions.h
#	src/Goal.cpp
#	src/Goal.h
#	src/KdTree.cpp
#	src/KdTree.h
#	src/Simulator.cpp
#	src/Vector2.cpp)

#add_library(HRVO ${HRVO_HEADERS} ${HRVO_SOURCES})

## Declare a cpp executable
# add_executable(Square
# 	src/Square.cpp
# 	src/Agent.cpp
# 	src/Goal.cpp
# 	src/KdTree.cpp
# 	src/Simulator.cpp
# 	src/Vector2.cpp
# )

# add_executable(Circle
# 	src/Circle.cpp
# 	src/Agent.cpp
# 	src/Goal.cpp
# 	src/KdTree.cpp
# 	src/Simulator.cpp
# 	src/Vector2.cpp
# )

add_executable(Experiment
  src/Experiment.cpp
  src/Agent.cpp
  src/Goal.cpp
  src/KdTree.cpp
  src/Simulator.cpp
  src/Vector2.cpp
  src/Environment.cpp
  src/Model.cpp
  src/Definitions.cpp
  src/Parameter.cpp
  src/Tracker.cpp
  src/AMCLWrapper.cpp
)

#	# Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(Circle ${PROJECT_NAME}_gencpp)

# TODO: EVERY TIME CATKIN_MAKE CLEAN IS CALLED, MESSAGES NEED TO BE GENERATED FIRST, THEN GENCPP
add_dependencies(Experiment ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(Simulator ${PROJECT_NAME}_generate_messages_cpp)

# TODO: THESE LINES NEED TO BE COMMENTED OUT FOR THE FIRST COMPILATION, AND THEN UNCOMMENTED AFTER MESSAGE GENERATION
add_dependencies(Experiment ${PROJECT_NAME}_gencpp)
add_dependencies(Simulator ${PROJECT_NAME}_gencpp)


## Specify libraries to link a library or executable target against
# target_link_libraries(Square
#  	${catkin_LIBRARIES}
# 	Agent
# 	Goal
# 	KdTree
# 	Simulator
# 	Vector2
# )

# target_link_libraries(Circle
# 	${catkin_LIBRARIES}
# 	Agent
# 	Goal
# 	KdTree
# 	Simulator
# 	Vector2
# )

target_link_libraries(Experiment
  ${catkin_LIBRARIES}
  Agent
  Goal
  KdTree
  Simulator
  Vector2
#  AMCLWrapper
)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS hrvo hrvo_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_hrvo.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
