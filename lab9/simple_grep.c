#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[256];

    if (argc != 3) {
        fprintf(stderr, "사용법: %s <패턴> <파일명>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, argv[1])) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
