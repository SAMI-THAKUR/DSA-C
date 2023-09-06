#include <stdio.h>
#include <string.h>
#define max 20

// --- STACK --- //
char stack [max];
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
void push(char n){
  if(overflow()){
    return;
  }else{
    stack[++top]=n;
  }
}

// --- Pop Method --- //
char pop(){
 if(underflow()){
    printf("ERROR");
    return -1;
 }else{
   return stack[top--];
 }
}

char peek(){
    return stack[top];
}

// --- Precedence --- //
 int precedence(char c){
        if(c=='+' || c=='-'){
            return  1;
        }
        else if(c=='*' || c=='/' || c=='%' ){
            return 2;
        }
        else if(c=='^'){
            return 3;
        }
        else if(c=='(' || c==')'){
            return 0;
        }
        return -1;
}

char *postfix (char *s){
    int i;
    int p=0;
    char *re = malloc(sizeof(char)*strlen(s));
    push('(');
    strcat(s,")");
    for(i=0 ; i<strlen(s) ; i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            re[p++]=s[i];
        }
        else if(s[i]=='('){
            push(s[i]);
           }
        else if(s[i]==')'){
                char r = peek();
            while(r!='('){
                 char curr = pop();
                 re[p++]=curr;
                 r = peek();
            }
            pop();
        }
       else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '%'){
             if (precedence(s[i]) > precedence(peek())) {
                push(s[i]);
             }else{
                while ((precedence(s[i]) <= precedence(peek()))){
                char op = pop();
                re[p++] = op ;
             }
             push(s[i]);
        }
    }
 }
 re[p]='\0';
 return re ;
}

void main(){
    char eq [20];
    printf("YOUR INFIX EQUATION: ");
    scanf("%s",&eq);
    printf("%s\n",postfix(eq));
    printf("%s",prefix(eq));

}
