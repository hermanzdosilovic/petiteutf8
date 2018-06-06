if( NOT TARGET PetiteUtf8 )

    include( ${CMAKE_CURRENT_LIST_DIR}/PetiteUtf8.srcs.cmake )

    add_library( PetiteUtf8 INTERFACE )
    target_sources( PetiteUtf8 INTERFACE ${SOURCES} )
    target_include_directories( PetiteUtf8 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Source )

endif( NOT TARGET PetiteUtf8 )
