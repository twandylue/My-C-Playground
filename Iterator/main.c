#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
char array[N];
typedef char *iterator;
iterator iter_begin(char a[]) { return &a[0]; }
iterator iter_end(char a[], size_t n) { return &a[n]; }
iterator iter_next(iterator it) { return ++it; }

int main(void) {
  char *a = "Hello World";
  iterator it = iter_begin(a);
  iterator end = iter_end(a, strlen(a));
  for (; it < end; it = iter_next(it)) {
    printf("%c\n", *it);
  }

  return 0;
}
