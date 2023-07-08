CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
STYLE=llvm # google, llvm, chromium, mozilla, webkit

all: main.c
	cc $(CFLAGS) main.c -o fr
	./fr

format:
	clang-format --style=$(STYLE) -i *.c
