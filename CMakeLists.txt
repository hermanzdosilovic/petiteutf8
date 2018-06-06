cmake_minimum_required( VERSION 3.10 )
project( petiteutf8 CXX )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

include( ${CMAKE_CURRENT_LIST_DIR}/PetiteUtf8/PetiteUtf8.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/PetiteUtf8Test/PetiteUtf8Test.cmake )

add_executable( Example Example.cpp)
target_link_libraries( Example PRIVATE PetiteUtf8 )