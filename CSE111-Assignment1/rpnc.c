#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
 * Reverse Polish Notation (RPN) Calculator
 *
 * Accepts a single argument in RPN, evaluates it and prints the answer to stdout.
 * 
 * Returns -1 on error, 0 otherwise.
 */

//borrowed from class

static double stack[16];
static int next = 0;


static double pop(){
	return stack[--next];
}

static void push(double operand){
	stack[next++] = operand;
}

int main(int argc, char *argv[]) {
	double op2;
	char *oper = strtok(argv[1], " ");
	while(oper != NULL){
		switch(oper[0]){
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			push(pop()/op2);
			break;
		case '^':
			op2 = pop();
			push(pow(pop(),op2));
			break;
		default:
			push(atoi(oper));
			break;
		}
		oper = strtok(NULL, " ");
	}
	printf("%g\n", stack[0]);
}
			

