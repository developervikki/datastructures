#include<stdio.h>
#include<stdlib.h>
#include<conio.h>  
  
struct node {
    int data;  
    struct node* next;
};
 
struct node *start=NULL,*temp;

void create() { 
    char ch;
    int n;
    struct node *new1;

    printf("Enter an Element: ");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->next = NULL;
    temp = start; 
    printf("Want to continue? (y/n): ");
    ch = getch();
    while(ch == 'y' || ch == 'Y') {
        printf("\nEnter Next Element: ");
        scanf("%d", &n);
        new1 = (struct node *)(malloc(sizeof(struct node)));
        new1->data = n;
        new1->next = NULL;
        temp->next = new1;
        temp = temp->next;
        printf("Want to continue? (y/n): ");
        ch = getch();
    }
}

int main() {
    int ch;
    do {
        printf("-------------Linked List-----------\n");
        printf("1. create \n 2. Insert First \n 3. insert on last \n 4. insert on Middle \n 5. Delete from first \n 6. Delete from Last \n 7. Delete from Middle \n 8. Display \n 9. Exit\n ");
        printf("-----------------------------------\n");
        printf("Enter the choice :");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2: 
				insertF();
				break;
			case 3: 
				insertL();
				break;
			case 4: 
				insertm();
				break;
			case 5:
				deletef();
				break;
			case 6:
				deletel();
				break;
			case 7:
				deletem();
				break;
			case 8:
				display();
				break;
            default:
                printf("Invalid Choice\n");
        }
    } while(ch != 9);

    return 0;
}
void insertF() {
    int data;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = start;
    start = newNode;
    printf("Node inserted at the beginning successfully.\n");
}

void insertL() {
    int data;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if (start == NULL) {
        start = newNode;
        return;
    }
    struct node *temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node inserted at the end successfully.\n");
}

void insertm() {
    int data, position, i;
    printf("Enter position (1-indexed) to insert the node: ");
    scanf("%d", &position);
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter data to insert at position %d: ", position);
    scanf("%d", &data);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    if (position == 1) {
        newNode->next = start;
        start = newNode;
        printf("Node inserted at position %d successfully.\n", position);
        return;
    }
    struct node *temp = start;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d successfully.\n", position);
}

// Function to delete the first node from the linked list
void deletef() {
    if (start == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
    printf("First node deleted successfully.\n");
}

// Function to delete the last node from the linked list
void deletel() {
    if (start == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("Last node deleted successfully.\n");
        return;
    }
    struct node *temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted successfully.\n");
}

// Function to delete a node from the middle of the linked list
void deletem() {
    int position, i;
    printf("Enter position (1-indexed) to delete the node: ");
    scanf("%d", &position);
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deletef();
        return;
    }
    struct node *temp = start;
    struct node *prev = NULL;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node at position %d deleted successfully.\n", position);
}

// Function to display the linked list
void display() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


