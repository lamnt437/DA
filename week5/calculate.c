/*Exercise 2 - calculate.c*/

#include <stdio.h>
#include <stdlib.h>

typedef struct number{
	char digit;
	struct number *next;
}NumberStack;

void printStack(NumberStack *top);
int isEmpty(NumberStack *top);
void push(NumberStack **top, char temp);
char pop(NumberStack **top);



int main()
{
	char c, aChar[2], bChar[2], dChar[2];
	int a, b, d, curTemp = 0, prevTemp = 0, choice;
	NumberStack *A = NULL;
	NumberStack *B = NULL;
	NumberStack *C = NULL;

	printf("Enter number A: ");
	while((c = getchar()) != '\n'){
		push(&A, c);
	}

	printf("Enter number B: ");
	while((c = getchar()) != '\n'){
		push(&B, c);
	}

	printf("CALCULATOR\n\n1 - add\n2 - subtract\n3 - exit\n?");
	scanf("%d", &choice);


	switch(choice){
		case 1://ADD
			aChar[0] = pop(&A);
			bChar[0] = pop(&B);
			while(aChar[0] != 'e' || aChar[0] != 'e'){
				//CONVERT TO INTEGER
				if(aChar[0] == 'e')
					a = 0;
				else
					a = atoi(aChar);

				if(bChar[0] == 'e')
					b = 0;
				else
					b = atoi(bChar);

				//ADD DIGIT
				d = a + b + prevTemp;
				if(d >= 10){
					curTemp = 1;
					d = d - 10;
				}
				else
					curTemp = 0;
				//PUSH TO STACK
				itoa(d, dChar, 10);
				push(&C, dChar[0]);
				prevTemp = curTemp;

				aChar[0] = pop(&A);
				bChar[0] = pop(&B);
			}
			if(prevTemp == 1)
				push(&C, '1');

			break;

		case 2://SUBTRACT
			aChar[0] = pop(&A);
			bChar[0] = pop(&B);
			curTemp = 0; prevTemp = 0;
			while(aChar[0] != 'e'){
                //CONVERT TO INTEGER
				a = atoi(aChar);
				if(bChar[0] == 'e')
					b = 0;
				else
					b = atoi(bChar);
                //SUBTRACT DIGIT
				d = a - b - prevTemp;
				if(d < 0){
					curTemp = 1;
					d = d + 10;
				}
                else
                    curTemp = 0;
                //PUSH TO STACK
				itoa(d, dChar, 10);
				prevTemp = curTemp;
				push(&C, dChar[0]);

				aChar[0] = pop(&A);
				bChar[0] = pop(&B);
			}

			break;

		default:
			puts("Error!");
			break;
	}

	printf("Result: ");
	printStack(C);

	return 0;
}

void printStack(NumberStack *top)
{
	NumberStack *cur = top;
	while(cur != NULL){
		printf("%c", cur->digit);
		cur = cur->next;
	}
	printf("\n");
}

int isEmpty(NumberStack *top)
{
	return top == NULL;
}

void push(NumberStack **top, char temp)
{
	NumberStack *buff = (NumberStack *)malloc(sizeof(NumberStack));
	buff->digit = temp;
	buff->next = *top;
	*top = buff;
}

char pop(NumberStack **top)
{
	if(isEmpty(*top))
		return 'e';
	NumberStack *ptr = *top;
	char temp = ptr->digit;
	*top = (*top)->next;
	free(ptr);

	return temp;
}

