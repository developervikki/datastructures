#include<stdio.h>
#include <stdlib.h>


struct Node { 
    int data;
    struct Node* next;
};

struct Node* new_Node(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* sorted_Merge(struct Node* x, struct Node* y) {
    struct Node* result = NULL;

    if (!x)
        return y;
    if (!y)
        return x;

    if (x->data <= y->data) {
        result = x;
        result->next = sorted_Merge(x->next, y);
    } else {
        result = y;
        result->next = sorted_Merge(x, y->next);
    }
    return result;
}

struct Node* getMiddle(struct Node* head) {
    if (!head)
        return head;

    struct Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node* mergeSort(struct Node* head) {
    if (!head || !head->next)
        return head;

    struct Node *middle = getMiddle(head);
    struct Node *nextOfMiddle = middle->next;
    middle->next = NULL;

    struct Node *left = mergeSort(head);
    struct Node *right = mergeSort(nextOfMiddle);

    struct Node *sortedList = sorted_Merge(left, right);
    return sortedList;
}

void displayList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list = new_Node(2);
    list->next = new_Node(3);
    list->next->next = new_Node(1);
    list->next->next->next = new_Node(7);
    list->next->next->next->next = new_Node(5);

    printf("Sort the said singly linked list using merge sort:\n");
    displayList(list); 

    struct Node* result = mergeSort(list);
    printf("\nAfter sorting the said list:\n");
    displayList(result); 

    return 0; 
}

