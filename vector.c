#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INIT_VEC_CAP 10
#define CHECK_BOUNDS(len, i) \
if ((i) < 0 || (i) >= (len)) { \
    printf("Index out of bounds: %d with length %d", (i), (len)); \
    exit(-1); \
}

ivec* ivec_new() {
    ivec* v = malloc(sizeof(ivec));
    ivec_init(v);
    return v;
}

void ivec_init(ivec* v) {
    v->array = malloc(sizeof(int) * INIT_VEC_CAP);
    v->cap = INIT_VEC_CAP;
    v->len = 0;
}

void ivec_push(ivec* v, int element) {
    if (v->len == v->cap) { // if the underlying array is out of space
        const int new_cap = v->cap * 1.5; // new capacity
        int* new_array = realloc(v->array, sizeof(int) * new_cap); // reallocate the array with a new capacity
        v->array = new_array; // update array pointer to the reallocated pointer
        v->cap = new_cap; // update capacity
    }

    v->array[v->len] = element; // set data after last element
    v->len += 1;
}

int ivec_remove(ivec* v, int i) {
    int removed = ivec_get(v, i);
    for (; i + 1 < v->len; i++) { // shift everything after i back by 1
        int next = v->array[i + 1]; // get the next element
        int* set = &v->array[i]; // get the pointer to the current element
        *set = next; // set the current element to the next element
    }
    
    v->len -= 1;
    return removed;
}

void ivec_set(ivec* v, int i, int element) {
    int* ptr = ivec_getp(v, i);
    *ptr = element;
}

int ivec_get(ivec* v, int i) {
    CHECK_BOUNDS(v->len, i);
    //return *(v->array + i);
    return v->array[i];
}
int* ivec_getp(ivec* v, int i) {
    CHECK_BOUNDS(v->len, i);
    //return v->array + i;
    return &v->array[i];
}

void ivec_cpy(ivec* v, int* arr) {
    for (int i = 0; i < v->len; i++) {
        int x = v->array[i];
        v->array[i] = x;
    }
}

void ivec_print(ivec* v) {
    printf("{ ");
    for (int i = 0; i < v->len; i++) {
        int x = v->array[i];
        if (i > 0) printf(", ");
        printf("%d", x);
    }
    printf(" }\n");
}

void ivec_free(ivec* v) {
    free(v->array);
    free(v);
}
