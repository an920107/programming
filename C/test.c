#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STACKSIZE 30
#define TRUE 1
#define FALSE 0

struct stack {
	int top;
	char items[STACKSIZE];
};

int main()
{
	struct stack infix; infix.top = -1;
	scanf("%s", infix.items);
	printf("%s", infixToPrefix(infix.items));

}

char* infixToPrefix(char str[STACKSIZE]){
struct stack myStack; myStack.top = -1;
struct stack prefix; prefix.top = -1;
for(int i = 0; i < strlen(str); i++){
	switch(str[i]){
		case ‘+’: case ‘-’: case ‘*’: case ‘/’:
		while(priority(myStackTopPriority(myStack)) > priority(str[i])){
			push(prefix.items, pop(myStack));
}
push(myStack, str[i]);
break;
default:
push(prefix, str[i]);
}
}
while(!isEmpty(myStack))
push(prefix, pop(myStack));

return prefix.items;
}

int myStackTopPriority(struct stack *ps){
return (ps -> items == NULL)? -1 : ps -> items[ps -> top];
}

int priority(char x){
switch(x){
case ‘*’: case ‘/’: return 2;
case ‘+’: case ‘-’: return 1;
default: return 0;
}
}

bool isEmpty(struct stack *ps)
{
return (ps -> top == -1);
}

bool isFull(struct stack *ps)
{
return (ps -> top == STACKSIZE -1);
}

void push(struct stack *ps, char x)
{
if(isFull(ps)){
printf(“%s”, “stack overflow\n”);
}
else{
ps -> items[++(ps -> top)] = x;
printf(“%s”, “push finished\n”);
}
}

char pop(struct stack *ps)
{
if(isEmpty(ps)){
printf(“%s”, “stack underflow\n”);
}
else return(ps -> items[ps -> top–]);
}