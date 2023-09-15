#include <inttypes.h>
#include <stdio.h>
#include <string.h>

// const char *msg = "Hello, World!";
const char *msg = "Hello World";
#define HIST_CAP 256
size_t hist[HIST_CAP] = {0};
#define TABLE_CAP 64
char table[TABLE_CAP] = {0};
size_t table_sz = 0;
#define IDX_CAP 64
size_t idx[IDX_CAP] = {0};
size_t idx_sz = 0;

int main(void) {
  size_t msg_sz = strlen(msg);
  for (size_t i = 0; i < msg_sz; ++i) {
    hist[(int)msg[i]]++;
  }

  for (size_t i = 0; i < HIST_CAP; ++i) {
    if (hist[i] > 0) {
      table[table_sz++] = (char)i;
    }
  }

  for (size_t i = 0; i < msg_sz; ++i) {
    for (size_t j = 0; j < table_sz; ++j) {
      if (msg[i] == table[j]) {
        idx[idx_sz++] = j;
      }
    }
  }

  printf("msg:   \"%s\"\n", msg);
  printf("table: \"%s\"\n", table);
  printf("Indices: [");
  for (size_t i = 0; i < idx_sz; ++i) {
    if (i > 0) {
      printf(", ");
    }
    printf("%zu", idx[i]);
  }
  printf("]\n");

  printf("table64: 0x%" PRIX64 "\n", *(uint64_t *)table);

  return 0;
}
