#[[
    # Example of usage

    Add into your CMakeLists.txt the next lines:

    # --------------------------------------------------------------------------

    # Add 'al_wrap' into modules search path - to find this file (al_wrap.cmake)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/path/to/al_wrap/")
    include(al_wrap)

    add_executable( <YOUR_EXECUTABLE>
        # ...
        ${ALWRAP_HEADERS} ${ALWRAP_SOURCES}
    )

    # Add 'al_wrap' includes search path
    target_include_directories( <YOUR_EXECUTABLE> ${ALWRAP_INCLUDE_DIRECTORIES} )

    # Add 'al_wrap' dependency libraries (OpenAL library)
    target_link_libraries( <YOUR_EXECUTABLE> ${ALWRAP_LIBRARIES} )

    # Add (on Debug) 'al_wrap' define - to enable OpenAL functions checking
    if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        target_compile_definitions( <YOUR_EXECUTABLE> ALWRAP_CHECK_FUNCS )
    endif()

    # --------------------------------------------------------------------------
]]

set(ALWRAP_INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_LIST_DIR}/include/
)

set(ALWRAP_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/include/al_wrap/al_simple_init.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/al_wrap/al_error_checking.hpp

    ${CMAKE_CURRENT_LIST_DIR}/include/al_wrap/al_Listener.hpp

    ${CMAKE_CURRENT_LIST_DIR}/include/al_wrap/objects/al_Object.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/al_wrap/objects/al_Buffer.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/al_wrap/objects/al_Source.hpp
)

set(ALWRAP_SOURCES
    $$PWD/sources/al_simple_init.cpp
    $$PWD/sources/al_error_checking.cpp

    $$PWD/sources/al_Listener.cpp

    $$PWD/sources/objects/al_Object.cpp
    $$PWD/sources/objects/al_Buffer.cpp
    $$PWD/sources/objects/al_Source.cpp
)

set(ALWRAP_LIBRARIES
    openal
)
