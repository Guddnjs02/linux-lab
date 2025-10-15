#include <stdio.h>
#include <stdlib.h>

// 프로그램 이름을 저장할 전역 변수를 외부에서 참조하겠다고 선언
extern const char* program_name;

#ifdef NDEBUG
    #define my_assert(expression) ((void)0)
#else
    #define my_assert(expression) \
        if (!(expression)) { \
            fprintf(stderr, \
                "%s: %s:%d: %s: Assertion `%s' failed.\n", \
                program_name, __FILE__, __LINE__, __func__, #expression); \
            abort(); \
        }
#endif
