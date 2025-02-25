#include<stdio.h>
#include "vector.h"
#include "linked_list.h"

void test_vec() {
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
    printf("freeing vector\n");
}

void test_llist() {
    illist* list = illist_new();
    illist_push(list, 1);
    illist_push(list, 2);
    illist_push(list, 3);
    illist_push(list, 4);
    illist_push(list, 5);

    illist_print(list);
    printf("size: %d\n", list->len);

    int removed = illist_remove(list, 3);
    printf("removing index 3, value %d...\n", removed);
    illist_print(list);
    printf("size: %d\n", list->len);

    printf("inserting value 4, at index 3...\n");
    illist_insert(list, 3, 4);
    illist_print(list);
    printf("size: %d\n", list->len);

    illist_free(list);
    printf("freeing linked list\n");
}

int main() {
    printf("Crumbles Data Structures\n");
    test_vec();
    printf("\n");
    test_llist();
    return 0;
}
