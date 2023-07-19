#include "Hash_Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _HashMap_Element {
  char *key;
  any_t value;
  int in_use;
} hashmap_element;

typedef struct _HashMap {
  int table_size;
  int size;
  hashmap_element *data;
} hashmap_map;

/* Hash function to calculate the hash value for a given key */
unsigned int hash(map_t in, const char *key) {
  hashmap_map *map = (hashmap_map *)in;
  unsigned long hashval = 5381;
  int c;

  while ((c = *key++)) {
    hashval = ((hashval << 5) + hashval) + c; // hashval * 33 + c
  }

  return hashval % map->table_size;
}
/*
 * Return the integer of the location in data
 * to store the point to the item, or MAP_FULL.
 */
int hashmap_hash(map_t in, const char *key) {
  hashmap_map *map = (hashmap_map *)in;
  if (map->size == map->table_size) {
    return MAP_FULL;
  }

  int curr = hash(map, key);
  printf("key: %s, hash: %d\n", key, curr);

  /* probling */
  for (int i = 0; i < map->table_size; ++i) {
    if (map->data[curr].in_use == 0) {
      return curr;
    }

    // TODO: Why?
    if (strcmp(map->data[curr].key, key) == 0 && map->data[curr].in_use == 1) {
      return curr;
    }

    // NOTE:
    curr = (curr + 1) % map->table_size;
  }

  return MAP_FULL;
}

extern map_t hashmap_new(void) {
  hashmap_map *map = (hashmap_map *)malloc(sizeof(hashmap_map));
  if (map == NULL) {
    goto err;
  }
  map->table_size = Hash_Map_Size;
  map->data = (hashmap_element *)calloc(Hash_Map_Size, sizeof(hashmap_element));
  if (map->data == NULL) {
    goto err;
  }
  map->size = 0;

  return map;

err:
  if (map != NULL) {
    hashmap_free(map);
  }
  return NULL;
}

extern int hashmap_insert(map_t in, const char *key, any_t value) {
  hashmap_map *map = (hashmap_map *)in;
  int index = hashmap_hash(map, key);
  if (index == MAP_FULL) {
    return MAP_FULL;
  }

  /* NOTE: set the data */
  map->data[index].key = strdup(key);
  map->data[index].value = value;
  map->data[index].in_use = 1;
  map->size += 1;

  return MAP_OK;
}

extern int hashmap_remove(map_t in, const char *key) {
  hashmap_map *map = (hashmap_map *)in;
  int index = hashmap_hash(map, key);

  /* NOTE: linear probling, if necessary. */
  for (int i = 0; i < map->table_size; ++i) {
    if (strcmp(map->data[index].key, key) == 0 &&
        map->data[index].in_use == 1) {
      map->data[index].in_use = 0;
      map->data[index].key = NULL;
      map->data[index].value = NULL;
      map->size -= 1;

      return MAP_OK;
    }
    index = (index + 1) % map->table_size;
  }

  return MAP_MISSING;
}

extern int hashmap_get(map_t in, const char *key, any_t **arg) {
  hashmap_map *map = (hashmap_map *)in;
  int index = hashmap_hash(map, key);
  if (map->data[index].key == NULL) {
    return MAP_MISSING;
  }

  /* NOTE: linear probling, if necessary. */
  for (int i = 0; i < map->table_size; ++i) {
    if (strcmp(map->data[index].key, key) == 0 &&
        map->data[index].in_use == 1) {
      *arg = map->data[index].value;
      return MAP_OK;
    }

    index = (index + 1) % map->table_size;
  }

  arg = NULL;
  return MAP_MISSING;
}

extern int hashmap_length(const map_t in) {
  hashmap_map *map = (hashmap_map *)in;
  if (map == NULL) {
    return 0;
  }

  return map->size;
}

extern void hashmap_free(map_t in) {
  hashmap_map *map = (hashmap_map *)in;
  free(map->data);
  free(map);
}
