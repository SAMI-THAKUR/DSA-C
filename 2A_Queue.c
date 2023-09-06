#include <stdio.h>
#define max 10
int queue [max];
int rear=-1;
int front=-1;

int underflow(){
 if(rear==-1){
    return 1;
 }
 return 0;
}

int overflow(){
 if(rear==max-1){
    return 1;
 }
 return 0;
}

void insert(int n){
 if(overflow()){
    printf("Queue is Full \n");
 }
 else if(front==-1){
    front = 0;
    rear = 0;
    queue[rear]=n;
    printf("%d was Inserted \n" , n);
 }
 else{
    rear++;
    queue[rear]=n;
    printf("%d was Inserted \n" , n);
 }
}

int delete(){
 if(underflow()){
    printf("Queue is empty \n");
    return -1;
 }
 int a = queue[front];
 if(front==rear){
    front = rear = -1;
 }else{
   front ++;
 }
 return a;
}

void print_queue(){
    int i;
 for(i=front;i<=rear;i++){
    printf("%d \t",queue[i]);
 }
 printf("\n");
}

void main(){
int point = 1 ;

int n,m;
printf("Options \n1-Insert \n2-Delete \n3-Print \n4-Exit \n");
while(point==1){
    int op ;
    printf("Your Option: ");
    scanf("%d",&op);
    switch (op){

 case 1:
    printf("Enter number to insert: ");
    scanf("%d",&n);
    insert(n);
    break;

 case 2:
    m = delete();
    if(m!=-1){
        printf("Deleted Element is %d \n",m);
    }
    break;

 case 3:
    print_queue();
    break;

 case 4:
    point=0;
    break;

 default:
    printf("Not a Valid choice \n");
    break;

    }
}
}
