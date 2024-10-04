#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node with the given data
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a cycle in a linked list
int hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return 0; // No cycle if the list is empty or has only one node
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move one step
        fast = fast->next->next;    // Move two steps

        if (slow == fast) {
            return 1; // Cycle detected
        }
    }

    return 0; // No cycle detected
}

