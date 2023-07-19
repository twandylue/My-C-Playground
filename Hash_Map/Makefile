CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
STYLE=llvm # google, llvm, chromium, mozilla, webkit

all: main.c
	clang $(CFLAGS) -c Hash_Map.c -o hash_map.o
	clang $(CFLAGS) main.c hash_map.o -o all
	./all
hashmap: Hash_Map.c
	clang $(CFLAGS) -c Hash_Map.c -o hash_map.o
hashmap_ts: Hash_Map_ts.c
	clang $(CFLAGS) -c Hash_Map_ts.c -o hash_map_ts.o
format:
	clang-format --style=$(STYLE) -i *.c
	clang-format --style=$(STYLE) -i *.h
