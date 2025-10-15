#include <stdio.h>
#include "my_assert.h"
#include <stdlib.h>

// my_assert.h에서 사용할 전역 변수를 여기서 정의
const char* program_name;

void foo(int num)
{
    my_assert( ((num >= 0) && (num <= 100)) );
    printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[])
{
    // 프로그램 이름을 전역 변수에 저장 (가장 먼저 수행!)
    program_name = argv[0];

    int num;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s aNumber (0 <= aNumber <= 100)\n", program_name);
        exit(1);
    }
    num = atoi(argv[1]);
    foo(num);
    return 0;
}
