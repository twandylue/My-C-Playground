#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

char *slurp_file(const char *file_path, size_t *size) {
  char *buffer = NULL;

  FILE *fp = fopen(file_path, "r");
  if (fp == NULL) {
    goto error;
  }

  if (fseek(fp, 0, SEEK_END) < 0) {
    goto error;
  }

  long m = ftell(fp);
  if (m < 0) {
    goto error;
  }

  buffer = malloc(sizeof(char) * m);
  if (fseek(fp, 0, SEEK_SET) < 0) {
    goto error;
  }

  size_t n = fread(buffer, 1, m, fp);
  assert(n == (size_t)m);

  if (ferror(fp) != 0) {
    goto error;
  }

  if (size != 0) {
    *size = n;
  }

  fclose(fp);
  return buffer;

error:
  if (fp != NULL) {
    fclose(fp);
  }

  if (buffer != NULL) {
    free(buffer);
  }

  return NULL;
}

int main(void) {
  size_t content_size = 0;
  char *content = slurp_file("input.txt", &content_size);
  printf("File Content:\n");
  fwrite(content, 1, content_size, stdout);

  return 0;
}
