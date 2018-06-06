if( NOT TARGET PetiteUtf8Test )

    include( ${CMAKE_CURRENT_LIST_DIR}/../PetiteUtf8/PetiteUtf8.cmake )

    include( ${CMAKE_CURRENT_LIST_DIR}/PetiteUtf8Test.srcs.cmake )

    add_executable( PetiteUtf8Test ${SOURCES} )
    target_link_libraries( PetiteUtf8Test PRIVATE PetiteUtf8 )
    target_include_directories( PetiteUtf8Test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Source )
    target_include_directories( PetiteUtf8Test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Dependencies/Catch2/single_include )

endif( NOT TARGET PetiteUtf8Test )
