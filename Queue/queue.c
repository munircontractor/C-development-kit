#include <stdlib.h>

/*********************
**** Queue methods ***
**********************/

/**
 * Create a new, empty queue
 *
 * Returns a pointer to the new queue
 */
struct queue *new_queue(void)
{
    struct queue *q = malloc(sizeof *q);
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
    q->free_value_func = free;
    return q;
}

/**
 * Free the memory allocated to the queue and all its elements
 */
void free_queue(struct queue *q, int deep)
{
    int i;
    for (i = 0; i < q->size; i++) {
        if (deep) {
            q->free_func(dequeue(q));
        } else {
            dequeue(q);
        }
    }
    free(q);
}

/**
 * Add value to the end of the queue
 */
void enqueue(struct queue *q, void *value)
{
    struct queue_element *element = malloc(sizeof *element);
    element->value = value;
    
    if (q->size > 0) {
        q->tail->next = element;
    } else {
        q->head = element;
    }
    q->tail = element;
    q->size++;
}

/**
 * Remove and return the value at the head of the queue
 * Calling this method on an empty queue will return NULL
 */
void *dequeue(struct queue *q)
{
    if (q->head == NULL) {
        return NULL;
    }

    struct queue_element *old_head = q->head;
    void *value = old_head->value;
    
    q->head = old_head->next;
    q->size--;
    
    free(old_head);
    return value;
}

