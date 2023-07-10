cmake_minimum_required(VERSION 3.20.2)

project(playingWithDL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release
RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if(NOT CMAKE_DL_LIBS )
  message(ERROR "The point of this is to work with ldl!!!")
endif()
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS None Debug Release RelWithDebInfo MinSizeRel)

include(GNUInstallDirs)

add_library(utils dlHandler.cpp)
target_link_libraries(utils ${CMAKE_DL_LIBS})
add_executable(${PROJECT_NAME} main.cxx)
target_link_libraries(${PROJECT_NAME} utils)


#the plugins:
foreach(plugin A B C)
  add_library(${plugin} SHARED ${plugin}.cpp)
  set_target_properties(${plugin} PROPERTIES PREFIX "")  
endforeach(plugin)