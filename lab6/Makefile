# 컴파일러 지정
CC = gcc
# 컴파일 옵션 (디버깅 정보 포함, 모든 경고 표시)
CFLAGS = -g -Wall -pg
# 최종 실행 파일 이름
TARGET = main

# 라이브러리 관련 경로 및 파일 이름
LIB_DIR = calc_lib
LIB_NAME = calc
STATIC_LIB = $(LIB_DIR)/lib$(LIB_NAME).a

# 라이브러리를 구성하는 소스 파일과 목적 파일
LIB_SRCS = $(wildcard $(LIB_DIR)/*.c)
LIB_OBJS = $(patsubst %.c, %.o, $(LIB_SRCS))

# 'make'만 입력하면 'main'을 빌드
all: $(TARGET)

# 메인 프로그램을 빌드하는 규칙
$(TARGET): main.c $(STATIC_LIB)
	$(CC) $(CFLAGS) -o $(TARGET) main.c -L$(LIB_DIR) -l$(LIB_NAME)

# 정적 라이브러리를 빌드하는 규칙
$(STATIC_LIB): $(LIB_OBJS)
	ar rcs $@ $^

# calc_lib 폴더의 .c 파일로부터 .o 파일을 생성하는 규칙
$(LIB_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 빌드 결과물을 삭제하는 규칙
clean:
	rm -f $(TARGET) $(LIB_OBJS) $(STATIC_LIB)

# 가짜 타겟 선언
.PHONY: all clean
