set( SOURCES "" )

set( Source
    ${CMAKE_CURRENT_LIST_DIR}/Source/RandomString.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Source/Unicode.hpp

    ${CMAKE_CURRENT_LIST_DIR}/Source/Test/EncodeTest.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Source/Test/DecodeTest.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Source/Test/Main.cpp
)

source_group( "Source" FILES ${Source} )
list( APPEND SOURCES ${Source} )
