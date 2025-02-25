#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

#define CHECK_BOUNDS(len, i) \
if ((i) < 0 || (i) >= (len)) { \
    printf("Index out of bounds: %d with length %d", (i), (len)); \
    exit(-1); \
}


inode* inode_new(int data) {
    inode* node = malloc(sizeof(inode));
    node->data = data;
    return node;
}

illist* illist_new() {
    illist* list = malloc(sizeof(illist));
    illist_init(list);
    return list;
}

void illist_init(illist* l) {
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
}

void illist_push(illist* l, int element) {
    inode* new = inode_new(element);
    if (l->tail == NULL) {
        l->head = new;
        l->tail = new;
        l->len += 1;
        return;
    }

    inode* curr_tail = l->tail;
    curr_tail->next = new;
    new->last = curr_tail;
    l->tail = new;
    l->len += 1;
}

int illist_remove(illist* l, int i) {
    inode* remove = illist_getn(l, i);
    int data = remove->data;
    inode* last = remove->last;
    inode* next = remove->next;

    last->next = next;
    next->last = last;
    free(remove);
    l->len -= 1;

    return data;
}

void illist_insert(illist* l, int i, int element) {
    inode* node = inode_new(element);
    if (i == 0) {
        inode* next = l->head;
        next->last = node;
        l->head = node;
        l->len += 1;
        return;
    }

    inode* next = illist_getn(l, i);
    inode* last = next->last;

    next->last = node;
    node->next = next;
    last->next = node;
    node->last = last;
    l->len += 1;
}

void illist_set(illist* l, int i, int element) {
    inode* set = illist_getn(l, i);
    set->data = element;
}

int illist_get(illist* l, int i) {
    inode* node = illist_getn(l, i);
    return node->data;
}

inode* illist_getn(illist* l, int i) {
    CHECK_BOUNDS(l->len, i);
    inode* curr = l->head;
    for (int at = 0; curr != NULL && at != i; at++) {
        curr = curr->next;
    }

    return curr;
}

void illist_print(illist* l) {
    inode* curr = l->head;
    printf("{ ");
    while (curr != NULL) {
        if (curr != l->head) {
            printf(", ");
        }
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf(" }\n");
}

void illist_free(illist* l) {
    inode* curr = l->head;
    while (curr != NULL) {
        inode* next = curr->next;
        free(curr);
        curr = next;
    }

    free(l);
}
