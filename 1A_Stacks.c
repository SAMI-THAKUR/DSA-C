#include<stdio.h>
#define max 5

int stack [max];
int top = -1 ;

int underflow(){
 if(top==-1){
    return 1;
 }
 return 0;
}

int overflow(){
 if(top==max-1){
    return 1;
 }
 return 0;
}

// --- Push Method --- //
void push(int n){
  if(overflow()){
    printf("Stack Overflow");
  }else{
    stack[++top]=n;
    printf("%d was Pushed \n" , n);
  }
}

// --- Pop Method --- //
int pop(){
 if(underflow()){
    printf("Stack underflowed \n");
    return -1;
 }else{
   return stack[top--];
 }
}

// -- Peek Method --- //
int peek(){
 if(underflow()){
    printf("Stack underflowed \n");
    return -1;
 }else{
  return stack[top];
 }
}

// --- Print Method --- //
void print_stack(){
    int i;
 for(i=top;i>=0;i--){
    printf("%d \t",stack[i]);
 }
 printf("\n");
}


void main(){
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
    push(n);
    break;

   case 2 :
    m = pop();
    if(m!=-1){
        printf("Poped element is %d \n",m);
    }
    break;

   case 3 :
     m = peek();
    if(m!=-1){
        printf("Top element is %d \n",m);
    }
    break;

   case 4 :
    print_stack();
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
