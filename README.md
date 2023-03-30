# OpenAL C++ Wrapper Library

## Build configuration

- Defines:
    - `ALWRAP_CHECK_FUNCS` - Enables OpenAL functions checking for errors. Useful in Debug

## Usage

- `qmake`:
    - Add into your `*.pro` file the next lines:

        ```qmake
        include(path/to/al_wrap.pri)

        # On Debug enable 'OpenAL functions check'
        CONFIG(debug, debug|release) {
            DEFINES += ALWRAP_CHECK_FUNCS
        }
        ```
- `cmake`:
    - Add into `CMakeLists.txt` file the next lines:

        ```cmake
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
        ```
