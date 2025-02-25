#include<stdio.h>
#include "vector.h"

int main() {
    printf("Crumbles Data Structures\n");
    ivec* list = ivec_new();
    ivec_push(list, 1);
    ivec_push(list, 2);
    ivec_push(list, 3);
    ivec_push(list, 4);
    ivec_push(list, 5);
    ivec_push(list, 6);
    ivec_push(list, 7);
    ivec_push(list, 8);
    ivec_push(list, 9);
    ivec_push(list, 10);
    ivec_push(list, 11);

    ivec_print(list);
    printf("size: %d, cap: %d\n", list->len, list->cap);

    printf("removing index 3, value 4...\n");
    ivec_remove(list, 3);
    ivec_print(list);
    printf("size: %d, cap: %d\n", list->len, list->cap);

    ivec_free(list);
    printf("freeing vector, trying to use pointer to confirm...\n");
    ivec_push(list, 12);
    return 0;
}
