SRC_FILES = main.c
CC_FLAGS = -Wall -Wextra -g -std=c11
CC = clang
BIN_DIR = bin

all:
	@mkdir -p ${BIN_DIR}
	${CC} ${SRC_FILES} ${CC_FLAGS} -o ${BIN_DIR}/vs