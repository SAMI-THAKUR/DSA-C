#include <stdio.h>
#include <math.h>
#define max 5

// --- STACK --- //
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
    return;
  }else{
    stack[++top]=n;
  }
}

// --- Pop Method --- //
int pop(){
 if(underflow()){
    return;
    return -1;
 }else{
   return stack[top--];
 }
}


int eval(char eq []){
    int i;
    for(i=0 ; i<strlen(eq) ; i++){
            char curr = eq[i];
        if( curr>=48 && curr<=57){
            push(curr -'0');
        }else{
            int p1 = pop();
            int p2 = pop();
            switch (curr) {
                case '+':
                    push(p2+p1);
                    break;
                case '-':
                    push(p2-p1);
                    break;
                case '*':
                    push(p2*p1);
                    break;
                case '/':
                    push(p2/p1);
                    break;
                case '^':
                    push((int)pow(p2,p1));
                    break;
            }

        }
    }
    return pop();
}

void main(){
    char c [10];
    printf("POSTFIX EQUATION: ");
    gets(c);
    printf("%d",eval(c));
}
