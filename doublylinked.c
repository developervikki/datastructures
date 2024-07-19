#include<stdio.h>
#include<stdlib.h> 
 
struct node {
    int data;
    struct node *ladd, *radd; 
}; 
 
struct node *start = NULL, *new1, *temp; 

void create();
void display();
void display_reverse(); 
void insert_first();
void insert_middle();
void insert_last();
void delete_first();
void delete_middle();
void delete_last();

int main() { 
    int choice;
    do {
        printf("\n------------------Linked list-------------");
        printf("\n1.Create \n2.Display \n3.Insert First \n4.Insert Middle \n5.Insert Last \n6.Delete first \n7.Delete middle \n8.Delete last \n9.Exit");
        printf("\n------------------------------------------");
        printf("\nEnter The choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_first();
                break;
            case 4:
                insert_middle();
                break;
            case 5:
                insert_last();
                break;
            case 6:
                delete_first();
                break;
            case 7:
                delete_middle();
                break;
            case 8:
                delete_last();
                break;
        }
    } while (choice != 9);
    return 0; 
}

void create() { 
    char ch;
    int n;
    printf("Enter an Element: ");
    scanf("%d", &n);
    start = (struct node*)malloc(sizeof(struct node));
    start->ladd = start->radd = NULL;
    start->data = n;
    printf("Want to continue");
    ch = getchar(); 
    while (ch == 'y' || ch == 'Y') { 
        printf("Enter the next elements: ");
        scanf("%d", &n);
        new1 = (struct node*)malloc(sizeof(struct node)); 
        new1->ladd = new1->radd = NULL;
        new1->data = n;
        printf("Want to continue");
        ch = getchar(); 
    }
}

void display() { 
    if (start == NULL) {
        printf("List Not Found");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->radd;
        }
    }
}

void display_reverse() { 
    if (start == NULL) {
        printf("List Not found");
    } else {
        temp = start;
        while (temp->radd != NULL) { 
            temp = temp->radd;
        }
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->ladd; 
        }
    }
}

void delete_first() { 
    if (start == NULL) {
        printf("List Not Found");
    }
    temp = start;
    start = start->radd;
    start->ladd = NULL;
    printf("Deleted Node is %d", temp->data);
    free(temp);
}

void delete_last() { 
    struct node *prev; 
    if (start == NULL) {
        printf("List Not Found"); 
    } else {
        temp = start;
        while (temp->radd != NULL) {
            temp = temp->radd;
        }
        prev = temp->ladd;
        printf("Deleted node is %d", temp->data);
        free(temp);
        prev->radd = NULL;
    }
}

void delete_middle() { 
    int pos, i = 1; 
    struct node *prev, *next;
    if (start == NULL) {
        printf("List Not Found");
    } else {
        printf("Enter the position:");
        scanf("%d", &pos);
        temp = start;
        while (i < pos) {
            temp = temp->radd;
            i++;
        }
        prev = temp->ladd;
        next = temp->radd;
        prev->radd = next;
        next->ladd = prev;
        free(temp);
    }
}

