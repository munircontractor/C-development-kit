## Cyclic Integer methods

#### Structs

    struct cyclic_int {
        int cycle;
        int hand;
    };

> This data structure creates a bounded integer, like the numbers on a clock.
> 
> * `cycle` is the period of repitition
> * `hand` is the current state of the cyclic integer. `0 <= hand < cycle` is
always true, unless the hand or cycle is set manually to some other value.
> 
> To free the struct, simply call free() on the pointer.

#### Methods

`struct cyclic_int *new_cyclic_int(int cycle)`:

> Creates a new `cyclic_int` struct and returns a pointer to it.
> 
> The `cycle` is the cycle of the new struct.

`int update_hand(struct cyclic_int *clock)`:

> Updates the value of the hand to the next value and returns the previous
value. Updated value of hand will always be `0 <= hand < cycle`, but the
returned value is whatever was the previous value.


