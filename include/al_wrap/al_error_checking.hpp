#pragma once

namespace al {

const char* al_error_to_str(int errorId);

const char* al_error_description_str(int errorId);

bool check_al_error(const char* file, int line, const char* str);

#if defined(ALWRAP_CHECK_FUNCS)

    #pragma message "ALWRAP :: OpenAL functions checking: enabled"

    #define ALWRAP_AL_CHECK(expression) \
        do { \
            expression; \
            (void) al::check_al_error(__FILE__, __LINE__, #expression); \
        } while(false)

#else // !defined(ALWRAP_CHECK_FUNCS)

    #pragma message "ALWRAP :: OpenAL functions checking: disabled"

    #define ALWRAP_AL_CHECK(expression) \
        expression

#endif

} // namespace al
