#include<stdio.h>

#include"cycle.h"



int main() {
    // Create a sample linked list with a cycle
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = head; // Create a cycle

    int result = hasCycle(head);

    if (result == 1) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }

    return 0;
}
