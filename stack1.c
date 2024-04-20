#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int stack[MAXSIZE], top=-1; 
void push();
void pop();
void display();
main(){ 
	int choice; 
	do{
	
	printf("\n------------Stack Menu----------");
	printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit");
	printf("\n---------------------------------");
	printf("\nEnter an Coice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: push(); break;
		case 2: pop(); break;
		case 3: display(); break;
	}}
	while(choice!=4);	
}
void push(){
	int n;
	if(top==MAXSIZE-1){
		printf("\n Stack is Overflow");
	}
	else{
		printf("\n Enter an Elemets");
		scanf("%d",&n);
		top++;
		stack[top]=n;
	}
}
void pop(){
	int j;
		if(top==-1){
		printf("Stack is Empty");
	}
	else{
		j=stack[top];
		top--;
		printf("Popped Elemets is %d", j);
		
	}
	
}

void display(){
	int i;
	if(top==-1){
		printf("Stack is Empty");
		
	}
	else{
		printf("Stack Elemets");
		for(i=top;i>=0;i--){
			printf("\t%d ",stack[i]);
		}
	}
}
