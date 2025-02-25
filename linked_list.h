#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct ilistnode inode;
struct ilistnode {
    int     data;
    inode*  next;
    inode*  last;
};
typedef struct {
    inode*  head;
    inode*  tail;
    int     len;
} illist;

illist* illist_new();
void illist_init(illist* l);
void illist_push(illist* l, int element);
int illist_remove(illist* l, int i);
void illist_insert(illist* l, int i, int element);
void illist_set(illist* l, int i, int element);
int illist_get(illist* l, int i);
inode* illist_getn(illist* l, int i);
void illist_print(illist* l);
void illist_free(illist* l);

#endif // LINKED_LIST_H_
