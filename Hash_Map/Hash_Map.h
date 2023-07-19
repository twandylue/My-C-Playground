#ifndef __Hash_Map_H__
#define __Hash_Map_H__

#define Hash_Map_Size 1024
#define MAP_MISSING -3 /* No such element */
#define MAP_FULL -2    /* HashMap is full */
#define MAP_OMEM -1    /* Out of memory */
#define MAP_OK 0       /* OK */

typedef void *any_t;
typedef any_t map_t;

/* Create a HashMap. */
extern map_t hashmap_new(void);

/* Insert a key-value pair into the HashMap. Return MAP_OK or MAP_FULL */
extern int hashmap_insert(map_t in, const char *key, any_t value);

/* Remove a key-value from the HashMap. Return MAP_OK or MAP_MISSING */
extern int hashmap_remove(map_t in, const char *key);

/* Get a key-value from the HashMap. Return MAP_OK or MAP_MISSING*/
extern int hashmap_get(map_t in, const char *key, any_t **arg);

/* Return the size of the HashMap. */
extern int hashmap_length(const map_t in);

/* Free the HashMap */
extern void hashmap_free(map_t in);

#endif
