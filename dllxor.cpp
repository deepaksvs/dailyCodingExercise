// XORed Doubly Linked List

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include "commons.h"


dll_node_t* left_right_of(dll_node_t *node, dll_node_t *other)
{
    return (dll_node_t *)(node->ptrs ^ (uint64_t)other);
}

uint64_t make_ptrs(dll_node_t *prev, dll_node_t *nxt)
{
    return (uint64_t) prev ^ (uint64_t) nxt;
}

dll_node_t* dll_add_node(dll_node_t *head, int val)
{
    dll_node_t *prev= NULL;
    dll_node_t *nxt = head;
    dll_node_t *itr = head;

    if (head == NULL) {
        dll_node_t *temp = new dll_node_t;
        if (temp) {
            temp->value = val;
            temp->ptrs = 0x0 ^ 0x0;
            return temp;
        }
        else {
            printf("Falied to allocate memory\n");
            return NULL;
        }
    }
    else {
        while (nxt != NULL) {
            nxt = left_right_of(itr, prev);
            prev = itr;
            itr = nxt;
        }
        dll_node_t *temp = new dll_node_t;
        if (temp) {
            temp->value = val;
            temp->ptrs = make_ptrs(prev, 0x0);
            dll_node_t *prev_prev = left_right_of(prev, 0x0);
            prev->ptrs = make_ptrs(prev_prev, temp);
        }
    }

    return head;
}

int dll_print(dll_node_t *head)
{
    dll_node_t *prev= NULL, *t;
    dll_node_t *itr = head;
    
    while (itr != NULL) {
        printf("%d ", itr->value);
        t = prev;
        prev = itr;
        itr = left_right_of(itr, t);
    }
    return 0;
}
