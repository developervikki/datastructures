#include<stdio.h>
#include<stdlib.h>

struct node { 
    int data; 
    struct node *add;
};
 
struct node *start = NULL, *new1, *temp;

void create(); 
void display();
void insert_first();
void insert_middle();
void insert_last();
void delete_first();
void delete_middle();
void delete_last();
void searching();

void main() {
    int choice;
    do {
        printf("\n------------------Linked list-------------");
        printf("\n1.Create \n2.Display \n3.Insert First \n4.Insert Middle \n5.Insert Last \n6.Delete first \n7.Delete middle \n8.Delete last \n9. Search \10.Exit");
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
            case 9:
            	searching();
        }
    } while (choice != 10);
}

void create() {
    char ch;
    int n;
    printf("\nEnter an Element");
    scanf("%d", &n);
    start = (struct node*)malloc(sizeof(struct node));
    start->data = n;
    start->add = NULL;
    temp = start;
    printf("\nWant to continue:");
    ch = getchar();
    while (ch == 'Y' || ch == 'y') {
        printf("\nEnter the next Elements");
        scanf("%d", &n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;
        temp->add = new1;
        temp = temp->add;
        printf("\nWant to continue:");
        ch = getchar();
    }
}

void display() {
    if (start == NULL) {
        printf("\nList Not Found");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("\t%d", temp->data);
            temp = temp->add;
        }
    }
}

void insert_first() {
    int n;
    if (start == NULL) {
        printf("List not Found");
    } else {
        printf("\nEnter the Element:");
        scanf("%d", &n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;
        new1->add = start;
        start = new1;
    }
}

void insert_middle() {
    int n, pos, i = 1;
    struct node *next, *prev;
    if (start == NULL) {
        printf("List not Found");
    } else {
        printf("\nEnter the Element");
        scanf("%d", &n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;
        printf("\nEnter The Position:");
        scanf("%d", &pos);
        next = start;
        while (i < pos) {
            prev = next;
            next = next->add;
            i++;
        }
        prev->add = new1;
        new1->add = next;
    }
}

void insert_last() {
    int n;
    if (start == NULL) {
        printf("list Not Found");
    } else {
        printf("\nEnter the Element:");
        scanf("%d", &n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;
        temp = start;
        while (temp->add != NULL) {
            temp = temp->add;
        }
        temp->add = new1;
    }
}

void delete_first() {
    if (start == NULL) {
        printf("List not found");
    } else {
        temp = start;
        start = start->add;
        printf("\nDeleted Node is %d", temp->data);
        free(temp);
    }
}

void delete_middle() {
    int pos, i = 1;
    struct node *next, *prev;
    if (start == NULL) {
        printf("List Not found");
    } else {
        printf("Enter the position:");
        scanf("%d", &pos);
        temp = start;
        while (i < pos) {
            prev = temp;
            temp = temp->add;
            i++;
        }
        next = temp->add;
        prev->add = next;
        printf("Deleted node is %d", temp->data);
        free(temp);
    }
}

void delete_last() {
    struct node *prev;
    if (start == NULL) {
        printf("List not Found");
    } else {
        temp = start;
        while (temp->add != NULL) {
            prev = temp;
            temp = temp->add;
        }
        prev->add = NULL;
        printf("Deleted Node is %d", temp->data);
        free(temp);
    }
}

void searching() {
    int s, f = 0;
    if (start == NULL) {
        printf("List Not Found");
    } else {
        printf("Enter an Element for search: ");
        scanf("%d", &s);
        temp = start;
        while (temp != NULL) {
            if (s == temp->data) {
                f = 1;
                break;
            }
            temp = temp->add; 
        }
        if (f == 1) {
            printf("Searching Success\n");
        } else {
            printf("Searching Not Success\n");
        }
    }
}

