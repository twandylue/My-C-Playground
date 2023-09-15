CFLAGS=-Wall -Wextra -Werror -pedantic-errors -ggdb --std=c11
STYLE=google # google, llvm, chromium, mozilla, webkit

program: main.c
	cc $(CFLAGS) main.c -o tmp
	./tmp
format:
	clang-format --style=$(STYLE) -i *.c
clean:
	rm -f tmp hello *.o
	rm -rf *.dSYM
