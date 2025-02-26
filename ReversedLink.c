#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to remove all nodes with the given value
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Remove leading nodes with value == val
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode* current = head;
    struct ListNode* prev = NULL;

    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;  // Skip the node
            free(current);  // Free memory
            current = prev->next;  // Move to the next node
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;  // Return new head
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    // Creating linked list: [1,2,6,3,4,5,6]
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    printf("Original List:\n");
    printList(head);

    int val = 6;
    head = removeElements(head, val);

    printf("List after removing %d:\n", val);
    printList(head);

    return 0;
}
