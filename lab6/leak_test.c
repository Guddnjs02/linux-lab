#include <stdlib.h>

void memory_leak() {
    malloc(100); // 100바이트를 할당하고 해제(free)하지 않습니다.
}

int main() {
    memory_leak();
    return 0;
}
