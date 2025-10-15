#include <stdio.h>
#include <dlfcn.h> // 동적 로딩 함수를 위해 필요

int main() {
    void *handle;
    int (*add)(int, int);
    int (*subtract)(int, int);
    char *error;

    // 공유 라이브러리를 엽니다.
    handle = dlopen("./calc_lib/libcalc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // 라이브러리에서 'add'와 'subtract' 함수의 주소를 찾습니다.
    add = dlsym(handle, "add");
    subtract = dlsym(handle, "subtract");

    printf("동적 로딩 연산 결과 (a=10, b=5)\n");
    if (add && subtract) { // 함수를 성공적으로 찾았는지 확인
        printf("덧셈: %d\n", (*add)(10, 5));
        printf("뺄셈: %d\n", (*subtract)(10, 5));
    }

    dlclose(handle); // 라이브러리를 닫습니다.
    return 0;
}
