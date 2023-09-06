#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


struct Node *head=NULL;
struct Node *tail=NULL;


struct Node* getNode(){
  return (struct Node *)malloc(sizeof(struct Node));
}


int count(){
    struct Node *temp = head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void create(){
    int n ;
    struct Node *new = getNode();
    printf("ENTER VALUE TO ENTER: ");
    scanf("%d",&n);
    new->next=NULL;
    new->data=n;
    head = new;
    tail = new ;
}

void insert(){
    printf("\n1-Insert By Value \n2-Insert By Position \n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1: insertByValue();
                break;
        case 2: insertByPosition();
           break;
        default: printf("INVALID CHOICE");
    }
}

void insertByValue(){
    int n;
    printf("ENTER VALUE TO INSERT AFTER or BEFORE: ");
    scanf("%d",&n);
    struct Node *Atvalue = head;
    while (Atvalue->data!=n){
        Atvalue=Atvalue->next;
        if (Atvalue==NULL){
            printf("VALUE NOT FOUND");
            return;
        }
    }
    printf("\n1-Insert After Value \n2-Insert Before Value \n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1: insertAfterValue(Atvalue);
                break;
        case 2: insertBeforeValue(Atvalue);
                break;
        default: printf("INVALID CHOICE");
    }
}

void insertAfterValue(struct Node *Atvalue){
    int n;
    printf("ENTER VALUE TO ENTER: ");
    scanf("%d",&n);
    struct Node *new = getNode();
    new->data=n;
    new->next=Atvalue->next;
    Atvalue->next=new;
    if(Atvalue==tail){
        tail=new;
    }
}

void insertBeforeValue(struct Node *Atvalue){
    int n;
    printf("ENTER VALUE TO ENTER :");
    scanf("%d",&n);
    struct Node *new = getNode();
      if(Atvalue==head){
        new->next=head;
        head=new;
    }
    struct Node *Beforeval = head;
    while (Beforeval->next!=Atvalue){
        Beforeval=Beforeval->next;
    }
    Beforeval->next=new;
    new->next=Atvalue;
    new->data=n;
}

void insertByPosition(){
    int n;
    printf("ENTER POSITION TO INSERT [1-%d]: " , count()+1);
    scanf("%d",&n);
    if(n>count()+1){
        printf("INVALID POSITION");
        return;
    }
    if(n==count()+1){
        struct Node *new = getNode();
        printf("ENTER VALUE TO ENTER: ");
        scanf("%d",&n);
        new->next=NULL;
        new->data=n;
        tail->next=new;
        tail=new;
        return;
    }
    struct Node *Atvalue = head;
    int i=1;
    while (i!=n){
        Atvalue=Atvalue->next;
        i++;
        if (Atvalue==NULL){
            printf("VALUE NOT FOUND");
            return;
        }
    }
   printf("ENTER VALUE TO ENTER: ");
   scanf("%d",&n);
   struct Node *new = getNode();
   if(Atvalue==head){
        new->next=head;
        head=new;
    }
   struct Node *Beforevalue = head;
    while (Beforevalue->next!=Atvalue){
        Beforevalue=Beforevalue->next;
    }
    Beforevalue->next=new;
    new->next=Atvalue;
    new->data=n;

}

void Delete(){
    if (head==NULL) {
        printf("LIST IS EMPTY");
        return;
    }
    printf("\n1-Delete By Value \n2-Delete By Position \n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1: DeleteByValue();
                break;
        case 2: DeleteByPosition();
                break;
        default: printf("INVALID CHOICE");
    }
}

void DeleteByValue(){
    int n;
    printf("ENTER VALUE TO DELETE: ");
    scanf("%d",&n);
    struct Node *Atvalue = head;
    while (Atvalue->data!=n){
        Atvalue=Atvalue->next;
        if (Atvalue==NULL){
            printf("VALUE NOT FOUND");
            return;
        }
    }
   if(Atvalue==head){
        head=Atvalue->next;
        free(Atvalue);
        return;
    }
    struct Node *Beforeval = head;
    while (Beforeval->next!=Atvalue){
        Beforeval=Beforeval->next;
    }
    Beforeval->next=Atvalue->next;
     if (Atvalue==tail){
        tail=Beforeval;
    }
    free(Atvalue);
}

void DeleteByPosition(){
    int n;
    printf("ENTER POSITION TO DELETE (1-%d): " , count());
    scanf("%d",&n);
    struct Node *Atvalue = head;
    int i=1;
    while (i!=n){
        Atvalue=Atvalue->next;
        i++;
        if (Atvalue==NULL){
            printf("VALUE NOT FOUND");
            return;
        }
    }
   if(Atvalue==head){
        head=Atvalue->next;
        free(Atvalue);
        return;
    }
    struct Node *Beforeval = head;
    while (Beforeval->next!=Atvalue){
        Beforeval=Beforeval->next;
    }
    Beforeval->next=Atvalue->next;
    if (Atvalue==tail){
        tail=Beforeval;
    }
    free(Atvalue);
}


void Search(){
    if (head==NULL) {
        printf("LIST IS EMPTY");
        return;
    }
    
    int n ;
    int pos = 1;
    printf("ENTER VALUE TO SEARCH: ");
    scanf("%d",&n);
    struct Node *temp = head;
    while(temp->data!=n){
        temp=temp->next;
        pos++;
        if (temp==NULL){
            printf("VALUE NOT FOUND");
            return;
        }
    }
    printf("VALUE FOUND AT POSITION %d",pos);
}

void print(){
    struct Node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main(){
    int choice;
    printf("\n1-INSERT \n2-DELETE \n3-PRINT \n4-SEARCH \n");
    do{
        printf("\nENTER CHOICE: ");
        scanf("%d",&choice);
         switch(choice){
                case 1:
                if (head==NULL){
                    create();
                }
                else if (head!=NULL){
                   insert();
                }
                      break;
                case 2: Delete();
                      break;
                case 3: print();
                      break;
                case 4: Search();
                      break;
                case 5:
                    break;
                default: printf("INVALID CHOICE");
         }
    }while(choice!=5);
}
