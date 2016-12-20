#include <stdlib.h>

struct cyclic_int *new_cyclic_int(int cycle)
{
    struct cyclic_int *clock = malloc(sizeof *clock);
    clock->cycle = cycle;
    clock->hand = 0;
    return clock;
}

int update_hand(struct cyclic_int *clock)
{
    int current_hand = clock->hand;
    clock->hand = (clock->hand + 1) % clock->cycle;
    return current_hand;
}

