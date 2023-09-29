CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic -ggdb
STYLE=llvm # google, llvm, chromium, mozilla, webkit

iterator: main.c
	cc $(CFLAGS) main.c -o iterator
	./iterator

format:
	clang-format --style=$(STYLE) -i *.c
	# clang-format --style=$(STYLE) -i *.h

clean:
	rm -f iterator
