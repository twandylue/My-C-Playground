#include <stdint.h>
#include <stdio.h>

int main(void) {
  const uint64_t table = 0x726F6C6564574820;
  size_t idx[] = {1, 4, 5, 5, 6, 0, 2, 6, 7, 5, 3};

  for (size_t i = 0; i < sizeof(idx) / sizeof(size_t); ++i) {
    putchar((table >> (8 * idx[i])) & 0xFF);
  }

  return 0;
}
