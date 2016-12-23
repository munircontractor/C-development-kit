#ifndef QUEUE_HEAD
#define QUEUE_HEAD

struct queue_element {
    void *value;
    struct queue_element *next;
};

struct queue {
    int size;
    struct queue_element *head;
    struct queue_element *tail;
    void (*free_value_func) (void *value);
};

struct queue *new_queue(void);
void free_queue(struct queue *q, int deep);
void enqueue(struct queue *q, void *value);
void *dequeue(struct queue *q);

#endif

