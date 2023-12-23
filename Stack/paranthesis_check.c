/* Program to check nesting of paranthesis using stack */

#include <stdio.h>
#include <string.h>
#define MAX 10

int top=-1;
int stack[MAX];
void push(char elem);
char pop();
int check(char exp[]);
int match(char a, char b);

void push(char item)
{
	if(top == MAX-1)
	{
		printf("Stack overflowed\n");
		return;
	}
	stack[++top] = item; 	
}

char pop()
{
	char item;
	if(top == -1)
	{
		printf("Stack is empty\n");
	}
	
	item = stack[top--];
	return item;
}

int main()
{
	int valid;
	char exp[MAX];
	
	printf("Enter the expression to be validated\n");
	gets(exp);
	valid = check(exp);
	if(valid == 1)
		printf("Valid expression\n");
	else
		printf("Invliad expression\n");
}

int check(char exp[])
{
	char temp;
	for(int i=0; i<strlen(exp); i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[' )
		{
			push(exp[i]);
		}
		if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']' )
		{
			if(top == -1)
			{
				printf("Right paranthesis are more than left\n");
			}	
			else
			{
				temp = pop();
				if(!match(temp,exp[i]))
				{
					printf("Mismatched paranthesis are: ");
					printf("%c ans %c \n", temp, exp[i]);
					return 0;
				}
			}
			
		}
	}
		if(top == -1)
		{
			printf("Balanced paranthesis\n");
			return 1;
		}
		else
		{
			printf("Left paranthesis more than right paranthesis\n");
			return 0;
		}
				
}




int match(char a, char b)
{
	if(a=='[' && b == ']')
		return 1;
	if(a=='{' && b == '}')
		return 1;
	if(a == '(' && b==')')
		return 1;
	return 0;
}




