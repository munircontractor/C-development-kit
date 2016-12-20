#ifndef ARRAYLIST_HEAD
#define ARRAYLIST_HEAD

struct list_element {
    void *value;
};

struct array_list {
    int cap;
    int size;
    struct list_element **elements;
    void (*free_value_func) (void *value);
};

struct array_list *new_list(int init_cap);
void free_list(struct array_list *list, int deep);
void list_add(struct array_list *list, void *value);
void *list_remove(struct array_list *list, int index);

#endif
