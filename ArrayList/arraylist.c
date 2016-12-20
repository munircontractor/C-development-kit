#include <stdlib.h>

/*************************
**** ArrayList methods ***
**************************/

/**
 * Create a new, empty list with capacity init_cap
 * The default for free_value_func is free(), but can be reassigned
 * if some other function is required to free all memeory used by the
 * *value pointer.
 *
 * Returns a pointer to the new queue
 */
struct array_list *new_list(int init_cap)
{
    struct array_list *list = malloc(sizeof *list);
    list->size = 0;
    list->elements = malloc(init_cap * sizeof *list->elements);
    list->cap = init_cap;
    list->free_value_func = free;
    return list;
}

/**
 * Free the memory allocated to the list and all its elements
 */
void free_list(struct array_list *list, int deep)
{
    int i;
    for (i = 0; i < list->size; i++) {
        if (deep) {
            list->free_value_func(list->elements[i]->value);
        }
        free(list->elements[i]);
    }
    free(list->elements);
    free(list);
}

/**
 * Add value to the end of the list.
 *
 * If list is full, the capacity of the list is doubled.
 */
void list_add(struct array_list *list, void *value)
{
    if (list->size == list->cap) {
        struct list_element **tmp = realloc(list->elements, 2 * list->cap * sizeof *list->elements);
        list->cap *= 2;
        list->elements = tmp;
    }
    
    struct list_element *element = malloc(sizeof *element);
    element->value = value;
    list->elements[list->size] = element;
    list->size++;
}

/**
 * Remove and return the value at the index of the list
 *
 * If index is not valid, the method returns NULL
 */
void *list_remove(struct array_list *list, int index)
{
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    
    struct list_element *element = list->elements[index];
    int i;
    for (i = index + 1; i < list->size; i++) {
        list->elements[i - 1] = list->elements[i];
    }
    list->size--;
    
    void *value = element->value;
    free(element);
    return value;
}

