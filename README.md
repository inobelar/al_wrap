# OpenAL C++ Wrapper Library

## Build configuration

- Defines:
    - `ALWRAP_CHECK_FUNCS` - Enables OpenAL functions checking for errors. Useful in Debug

## Usage

- `qmake`:
    - Add to your `*.pro` file next lines:

        ```qmake
        include(path/to/al_wrap.pri)

        # On Debug enable 'OpenAL functions check'
        CONFIG(debug, debug|release) {
            DEFINES += ALWRAP_CHECK_FUNCS
        }
        ```
