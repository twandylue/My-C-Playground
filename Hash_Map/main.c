#include "Hash_Map.h"
#include <stdio.h>

int main(void) {
  map_t *map = hashmap_new();

  int age = 28;
  int s1 = hashmap_insert(map, "andy", &age);
  printf("status: %d\n", s1);
  /* char *word = "Hi"; */
  /* int s2 = hashmap_insert(map, "amy", &word); */
  char age2 = 20;
  int s2 = hashmap_insert(map, "amy", &age2);
  printf("status: %d\n", s2);

  printf("map length before: %d\n", hashmap_length(map));
  int s3 = hashmap_remove(map, "andy");
  printf("map length after: %d\n", hashmap_length(map));
  printf("status: %d\n", s3);

  any_t *val1 = NULL;
  int s4 = hashmap_get(map, "amy", &val1);
  printf("status: %d\n", s4);
  printf("val1: %d\n", *(int *)val1);

  int s5 = hashmap_get(map, "andy", &val1);
  printf("status: %d\n", s5);
  if (val1) {
    printf("val1: %d\n", *(int *)val1);
  } else {
    printf("val1 is null\n");
  }

  any_t *val2 = NULL;
  int s6 = hashmap_get(map, "auther", &val2);
  printf("status: %d\n", s6);
  if (!val2) {
    printf("val2 is null\n");
  }

  hashmap_free(map);
  return 0;
}
