#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct {
    int*    array;
    int     len;
    int     cap;
} ivec;

ivec* ivec_new();
void ivec_init(ivec* v);
void ivec_push(ivec* v, int element);
int ivec_remove(ivec* v, int i);
void ivec_insert(ivec* v, int i, int element);
void ivec_set(ivec* v, int i, int element);
int ivec_get(ivec* v, int i);
int* ivec_getp(ivec* v, int i);
void ivec_cpy(ivec* v, int* arr);
void ivec_print(ivec* v);
void ivec_free(ivec* v);

#endif // VECTOR_H_
