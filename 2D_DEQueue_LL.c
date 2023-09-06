#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
int size = 0;



void init(int n){
    struct Node *new;
    new = (struct node *)malloc(sizeof(struct Node));
    if(new==NULL){
        printf("No Memory");
        return;
    }
    new->next=head;
    new->data=n;
    head = new;
    tail = new ;
    size++;
}

void insert_last(int n){
    struct Node *new;
    new = (struct node *)malloc(sizeof(struct Node));
      if(new==NULL){
        printf("No Memory");
        return;
    }
    tail->next = new;
    new->next=NULL;
    tail = new ;
    new->data = n;
    size++;
}

void insertR(int n){
   if(head==NULL){
    init(n);
   }else{
    insert_last(n);
   }
}

void insertF(int n){
   if(head==NULL){
    init(n);
   }else{
    struct Node *new;
    new = (struct node *)malloc(sizeof(struct Node));
    new->next = head;
    head = new;
    new->data = n;
    size++;
   }
}

int deleteF(){
    int re;
    if(head==NULL){
    printf("Linked List is Empty");
 }else{
    re = head->data;
    head = head->next;
    size =size-1;
    if (size==0){
      tail=NULL;
      head = NULL;
    }
 }

 return re;
}

int deleteR(){
    int re;
    if(head==NULL){
    printf("Linked List is Empty");
 }else{
    struct Node *temp = head;
    while(temp->next==NULL){
        temp = temp->next;
    }
    re = tail->data;
    temp->next = NULL;
    tail=temp;
    size--;
 }
 return re;
}

void display(){
    struct Node *temp1 =head;
    if(head==NULL){
      printf("Linked List is Empty");
    }
    else{
        while(temp1!=NULL){
            printf("%d \t",temp1->data);
            temp1 = temp1->next;
        }
    }
}


void main(){
int point = 1 ;
int n,m;
printf("Options \n1-Insert Front \n2-Insert Rear \n3-Delete Front \n4-Delete Rear \n5-Print \n6-Exit \n");
while(point==1){
    int op ;
    printf("Your Option: ");
    scanf("%d",&op);
    switch (op){

 case 1:
    printf("Enter number to insert: ");
    scanf("%d",&n);
    insertF(n);
    break;

 case 2:
    printf("Enter number to insert: ");
    scanf("%d",&n);
    insertR(n);
    break;

 case 3:
    m = deleteF();
    if(m!=-1){
        printf("Deleted Element is %d \n",m);
    }
    break;

 case 4:
    m = deleteR();
    if(m!=-1){
        printf("Deleted Element is %d \n",m);
    }
    break;

 case 5:
    display();
    break;

 case 6:
    point=0;
    break;

 default:
    printf("Not a Valid choice \n");
    break;

    }
}
}


