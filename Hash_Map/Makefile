CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
STYLE=llvm # google, llvm, chromium, mozilla, webkit

all: main.c
	cc $(CFLAGS) -c Hash_Map.c -o hash_map.o
	cc $(CFLAGS) main.c hash_map.o -o all
	./all
hashmap: Hash_Map.c
	cc $(CFLAGS) -c Hash_Map.c -o hash_map.o
hashmap_ts: Hash_Map_ts.c
	cc $(CFLAGS) -c Hash_Map_ts.c -o hash_map_ts.o
format:
	clang-format --style=$(STYLE) -i *.c
	clang-format --style=$(STYLE) -i *.h
