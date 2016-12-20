#ifndef CYCLIC_INT_HEAD
#define CYCLIC_INT_HEAD

// Cyclic integer
struct cyclic_int {
    int cycle;
    int hand;
};

struct *cyclic_int new_cyclic_int(int cycle);
int update_hand(struct cyclic_int *clock);

#endif

