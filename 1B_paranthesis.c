#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

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
    return;
    return -1;
 }else{
   return stack[top--];
 }
}

int paran(char f []){
  int i=0;
  for(i=0 ; i<strlen(f) ; i++){
    char curr = f[i];
    if(curr=='('){
        push(')');
       }
    else if(curr=='{'){
        push('}');
       }
    else if(curr=='['){
        push(']');
    }
  else if(underflow() || f[i]!=pop()){
    return 0;
  }
}
 return underflow();
}

int main()
{
  char f [1000] ;
  gets(f);
  printf("%s",f);
  if(paran(f)){
    printf("\ncorrect paranthesis");
  }
  else{
    printf("\nERROR");
  }
  return 0;
}

// Reads and stores the whole contents of the file with filename into a
// dynamically allocated char array on the heap, returns a pointer to this char
// array (or NULL if there was an error reading the file contents)/
char *read_file(char *filename)
{
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL) return NULL;
  fseek(file, 0, SEEK_END);


  int length = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *string = malloc(sizeof(char) * (length+1));
  char c;
  int i = 0;
  while ( (c = fgetc(file)) != EOF)
  {
    if(c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']'){
    string[i] = c;
    i++;
    }

  }
  string[i] = '\0';
  fclose(file);
  return string;
}
