#include <stdio.h>
#include "calc_lib/calc.h"

int main() {
    int a = 10;
    int b = 5;

    printf("사칙연산 결과 (a=10, b=5)\n");
    printf("덧셈: %d\n", add(a, b));
    printf("뺄셈: %d\n", subtract(a, b));
    printf("곱셈: %d\n", multiply(a, b));
    printf("나눗셈: %f\n", divide(a, b));

    return 0;
}
