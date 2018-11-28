// Given a singly linked list and an integer k, remove the kth last element
// from the list. k is guaranteed to be smaller than the length of the list.
// The list is very long, so making more than one pass is prohibitively expensive.
// Do this in constant space and in one pass.
#include <vector>
#include <iostream>

typedef struct _sll {
    int         value;
    struct _sll *next;
}sll_t;

int remove_r (sll_t *head, int pos)  {
    int itr_count = 0;
    sll_t   *c_itr, *k_itr, *p_itr;
    c_itr = k_itr = p_itr = head;

    while (itr_count < pos) {
        c_itr = c_itr->next;
        if (nullptr == c_itr) {
            throw std::invalid_argument("Position greater than length of list");
        }
        itr_count++;
    }

    while (c_itr != nullptr) {
        c_itr = c_itr->next;
        p_itr = k_itr;
        k_itr = k_itr->next;
    }

    p_itr->next = k_itr->next;
    delete(k_itr);
    return 1;
}

