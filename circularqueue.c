#include<stdio.h>
#define MAXSIZE 10
int cq(MAXSIZE), rear=-1, front=-1;  
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
	if((rear+1)%MAXSIZE==front)
	{
		printf("\nQueue is Overflow");
	}
	else{
		int n;
		printf("\nEnter an Elemet");
		scanf("%d",&n);
		if(front==-1 && rear==-1){
			front=0;
			rear=0;
		}
		else{
			rear=(rear+1)%MAXSIZE;
			cq[rear]=n;
		}
		
	}
	
}

void delete1(){
	if(rear==-1 && front==-1){
		printf("queue Is Empty");
	}
	else{
		n=cq[front];
		printf("Delted Elemet is %d", n);
		if(front==rear){
			front=-1;
			rear=-1;
		}
		front=(front+1)%MAXSIZE;
	}
	
}

void display(){
	if(rear==-1 && front==-1){
		printf("queue Is Empty");
	}
	else{
		printf("Elements of Queue ");
		for(i=front;i!=rear; (i=(i+1)%MAXSIZE))
		{
			printf("%5d", cq[i]);
		}
		printf("%5d", cq[i]);

	}
	
}
