#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;

void Insert(int n){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->next=NULL;
    new->data = n;
    if(head==NULL){
        head = new;
    }else{
        tail->next = new;
    }
    tail = new ;
}

int Delete(){
 if(head==NULL){
    printf("Underflow \n");
    return -1;
 }
 else{
    int re = head->data;
    head = head->next;
    return re;
   }

}

void display(){
    struct Node *temp1 =head;
    if(head==NULL){
      printf("Stack is Empty");
    }
    else{
        while(temp1!=NULL){
            printf("%d \t",temp1->data);
            temp1 = temp1->next;
        }
        printf("\n");
    }
}

void main(){
int n;
int m;
int point = 1;
printf("Options \n1-Push \n2-Pop \n3-Print \n4-Exit \n");
while(point){
     int op ;
     printf("Your Option: ");
     scanf("%d",&op);
     switch (op){
         case 1 :
    printf("Enter number to Push : ");
    scanf("%d",&n);
    Insert(n);
    break;

   case 2 :
    m = Delete();
    if(m!=-1){
        printf("Deleted element is %d \n",m);
    }
    break;

   case 3 :
    display();
    break;

   case 4 :
    point=0;
    break;

   default:
    printf("Not a Valid choice \n");
    break;
     }
}

}



