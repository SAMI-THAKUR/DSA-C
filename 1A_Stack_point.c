#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Structure to represent the stack
struct Stack {
    int arr[MAX_STACK_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

// Function to push a value onto the stack
void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = data;
}

// Function to pop a value from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to peek at the top value of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

// Function to print the elements of the stack
void printStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}


int main() {
    struct Stack stack;
    initializeStack(&stack);
    int point = 1 ;

   int n,m;
   printf("Options \n1-Push \n2-Pop \n3-Peek \n4-Print \n5-Exit \n");
   while(point==1){
     int op ;
     printf("Your Option: ");
     scanf("%d",&op);
     switch (op){
   case 1 :
    printf("Enter number to Push : ");
    scanf("%d",&n);
    push(&stack,n);
    break;

   case 2 :
    m = pop(&stack);
    if(m!=-1){
        printf("Poped element is %d \n",m);
    }
    break;

   case 3 :
     m = peek(&stack);
    if(m!=-1){
        printf("Top element is %d \n",m);
    }
    break;

   case 4 :
    printStack(&stack);
    break;

   case 5:
    point=0;
    break;

   default:
    printf("Not a Valid choice \n");
    break;
     }
   }
}
