#include<stdio.h>
#include<stdlib.h> 
 
struct node {
    int data;
    struct node *ladd, *radd;
};  
 
struct node *start = NULL, *new1, *temp; 
 
void create();
void display(); 
void insert_first();
void insert_last();
void delete_first();
void delete_last();

int main() { 
    int choice;
    do {
        printf("\n------------------Linked list-------------");
        printf("\n1.Create \n2.Display \n3.Insert First \n4.Insert Last \n5.Delete first \n6.Delete last \n7.Exit");
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
                insert_last();
                break;
            case 5:
                delete_first();
                break;
            case 6:
                delete_last();
                break;
        }
    } while (choice != 7);
    return 0; 
}

void create(){
    char ch;
    int n;
    printf("Enter an Element: ");
    scanf("%d",&n);
    start=(struct node*)malloc(sizeof(struct node));
    start->ladd=start->radd=NULL;
    start->data=n;
    temp=start;
    temp->ladd=start;
    temp->radd=start;
    printf("Want to continue (Y/N): ");
    scanf(" %c", &ch); // Added space before %c to consume the newline character
    while(ch=='y' || ch=='Y'){
        new1=(struct node*)malloc(sizeof(struct node));
        new1->radd=new1->ladd=NULL;
        new1->data=n;
        temp->radd=new1;
        new1->ladd=temp;
        temp=temp->radd;
        start->ladd=new1;
        new1->radd=start;
        printf("Want to continue (Y/N): ");
        scanf(" %c", &ch); // Added space before %c to consume the newline character
    }
}

void display(){
    temp=start;
    do{
        printf("%5d", temp->data);
        temp=temp->radd;
    }while(temp!=start);
}

void insert_first(){
    int n;
    if(start==NULL){
        printf("List Not Found");
    }
    else{
        printf("Enter an Element:");
        scanf("%d",&n);
        new1=(struct node*)malloc(sizeof(struct node));
        new1->ladd=new1->radd=NULL;
        new1->data=n;
        temp=start;
        temp=temp->ladd;
        new1->ladd=start;
        start->ladd=new1;
        start=new1;
        start->ladd=temp;
        temp->radd=start;
    }
}

void insert_last(){
    int n;
    if(start==NULL){
        printf("List Not Found");
    }
    else{
        printf("Enter an Element:");
        scanf("%d",&n);
        new1=(struct node*)malloc(sizeof(struct node));
        new1->ladd=new1->radd=NULL;
        new1->data=n;
        temp=start;
        temp=temp->ladd;
        temp->radd=new1;
        new1->radd=temp;
        start->ladd=new1;
        new1->radd=start;
    }
}

void delete_first(){
    if(start==NULL){
        printf("List Not Found");
    }
    else{
        temp=start;
        struct node *next=start->radd;
        start=start->radd;
        start->ladd=next;
        next->radd=start;
        printf("Deleted node is %d",temp->data);
        free(temp);
    }
}

void delete_last(){
    if(start==NULL){
        printf("List Not Found");
    }
    else{
        temp=start->ladd;
        struct node *prev=temp->ladd;
        start->ladd=prev;
        prev->radd=start;
        printf("Deleted node is %d",temp->data);
        free(temp);
    }
}

