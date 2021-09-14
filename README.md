# OpenAL C++ Wrapper Library 

## Build configuring

- Defines
    - `ALWRAP_CHECK_FUNCS` - Enables OpenAL functions checking for error. Useful in Debug

## Usage

- `qmake`:
    - Add to your `*.pro` file next lines:

        ```qmake
        include(<path/to>/src/al_wrap.pri);

        # On Debug enable 'OpenAL functions check'
        CONFIG(debug, debug|release) {
            DEFINES += ALWRAP_CHECK_FUNCS
        }
        ```
