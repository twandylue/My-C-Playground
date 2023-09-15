CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
STYLE=llvm # google, llvm, chromium, mozilla, webkit

tokenization: main.c
	cc $(CFLAGS) main.c -o tokenization
	./tokenization

format:
	clang-format --style=$(STYLE) -i *.c
	# clang-format --style=$(STYLE) -i *.h

clean:
	rm -f tokenization
