CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb

heap: main.c
	clang-format --style=LLVM -i main.c
	cc $(CFLAGS) main.c -o fb
	./fb
