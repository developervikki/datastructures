#include<stdio.h> 
#define MAXSIZE 10      
    
int queue[MAXSIZE], rear=-1, front=0; 
void insert(); 
void delete1();   
void display();  
 
int main(){
    int choice; 
    do{
        printf("\n------------Queue Menu----------");
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit");
        printf("\n---------------------------------");
        printf("\nEnter a Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert(); break;
            case 2: delete1(); break; 
            case 3: display(); break;
        }
    }
    while(choice!=4);
    return 0;
}

void insert(){
    int n;
    if(rear==MAXSIZE-1){ 
        printf("\nQueue is Overflow");
    }
    else{
        printf("\nEnter an Element: ");
        scanf("%d",&n);
        rear++;
        queue[rear]=n;
    }
}

void display(){
    int i;
    if(front>rear){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nQueue Elements: ");
        for(i=front; i<=rear; i++){ 
            printf("%5d",queue[i]);
        }
    }
}

void delete1(){
    int n;
    if(front>rear){
        printf("\nQueue is Empty");
    }
    else{
        n=queue[front];
        front++;
        printf("\nDeleted Element is %d",n); // Added \n for readability
    }
}

