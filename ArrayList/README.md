## ArrayList methods

#### Structs

    struct list_element {
        void *value;
    };

> Internal data structure for wrapping the `value` pointer type.  
> There is no reason to create this struct since the `list_add`
method does that already. It is only required for iterating 
over the list.

    struct array_list {
        int cap;
        int size;
        struct list_element **elements;
        void (*free_value_func) (void *value);
    };

> The `array_list` struct:
> 
> * `cap` is the capacity of the list
> * `size` is the number of elements currently in the list
> * `elements` is the array of the elements
> * `free_value_func` is a function that can free the struct of which 
the list is made

#### Methods

`struct array_list *new_list(int init_cap)`:

> Create a new, empty list with capacity init_cap.  
> The default for free_value_func is free(), but can be reassigned
if some other function is required to free memory used by the
value pointer.  
> Returns a pointer to the new list.

`void free_list(struct array_list *list, int deep)`:

> Free the memory allocated to the list and all its elements.  
> If `deep` is true, the pointers to `value` are also freed for each
element using the `free_value_func`. Otherwise, only the list and
allocated `list_element` structs are freed.

`void list_add(struct array_list *list, void *value)`:

> Add value to the end of the list. The `value` is wrapped by the
`list_element` struct as part of this method, so no need to wrap
externally.  
> If list is full, the capacity of the list is doubled.

`void *list_remove(struct array_list *list, int index)`:

> Remove and return the `value` at the index of the list.  
> If index is not valid, the method returns NULL, otherwise
returns a void pointer to `value`.

