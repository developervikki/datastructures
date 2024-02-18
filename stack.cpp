#include<stdio.h>
#include<conio.h>

#define MAXSIZE 10
int stack[MAXSIZE],top=-1;

// Function prototypes
void push();
void pop();
void display();

int main() {
	
	
    int choice;
    do{
    printf("-----------Stack----------");
    printf("\n1.Push \n2.Pop \n3.Display \n4.Exit ");
    printf("\n------------------------");
    printf("\nEnter The Choice: ");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid Choice");
    }}
    while(choice!=4);
    
}

void push() {
    int n;
    if(top==MAXSIZE-1) {
        printf("Stack is Overflow");
    }
    else {
        printf("Enter the Element: ");
        scanf("%d",&n);
        top++;
        stack[top]=n;
    }
}

void display() {
    int i;
    if(top==-1) {
        printf("Stack is Empty");
    }
    else {
        printf("----------Elements-----------\n");
        for(i=top; i>=0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void pop() {
    int j;
    if(top==-1) {
        printf("Stack is Empty");
    }
    else {
        j=stack[top];
        top--;
        printf("Element Popped: %d", j);
    }
}

