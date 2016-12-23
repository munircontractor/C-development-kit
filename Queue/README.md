## Queue methods

#### Structs

    struct queue_element {
        void *value;
        struct queue_element *next;
    };

> Internal data structure for wrapping the `value` pointer type.  
> There is no reason to create this struct since the `enqueue`
method does that already. It is only required for iterating 
over the queue when used as a linked list.

    struct queue {
        int size;
        struct queue_element *head;
        struct queue_element *tail;
        void (*free_value_func) (void *value);
    };

> The `queue` struct:
> 
> * `size` is the number of elements currently in the queue
> * `head` is the head of the queue. Elements are removed from this end.
> * `tail` is the tail of the queue. Elements are added at this end.
> * `free_value_func` is a function that free the struct of which the
queue is made.

#### Methods

`struct queue *new_queue(void)`:

>  Creates a new, empty queue and returns a pointer to it

`void free_queue(struct queue *q, int deep)`:

> Free the memory allocated to the queue and all its elements  
> If `deep` is true, the pointers to `value` are also freed for each
element using the `free_value_func`. Otherwise, only the queue and
allocated `queue_element` structs are freed.

`void enqueue(struct queue *q, void *value)`:

> Add value to the end of the queue

`void *dequeue(struct queue *q)`:

> Remove and return the value at the head of the queue   
> Calling this method on an empty queue will return NULL

