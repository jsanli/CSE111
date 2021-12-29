#
# Python3 Reverse Polish Notation (RPN) Calculator
#
# Accepts an single argument in RPN, evaluates it and prints the answer to stdout.
#

#www.geeksforgeeks.org/command-line-arguments-in-python
#https://www.w3schools.com/python/python_functions.asp
#https://www.simplilearn.com/tutorials/python-tutorial/global-variable-in-python:
#https://careerkarma.com/blog/python-isalpha-isnumeric-isalnum/#:~:text=The%20Python%20isnumeric()%20method,method%20returns%20the%20value%20False%20.

import sys

argument = str(sys.argv[1])
n = len(argument)
stack = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
nextt = 0

def pop():
	global nextt
	global stack
	nextt = nextt - 1
	return stack[nextt]


def push(operand):
	global nextt
	global stack
	stack[nextt] = operand;
	nextt = nextt + 1




for i in range(0, n):
	irrelevant = False
	if(argument[i] == "+"):
		push(pop() + pop());
	elif(argument[i] == "-"):
		op2 = pop()
		push(pop()-op2)
	elif(argument[i] == "*"):
		push(pop() * pop())
	elif(argument[i] == "/"):
		op2 = pop()
		push(pop()/op2) 
	elif(argument[i] == "^"):
		op2 = pop()
		push(pop()** op2)
	elif(argument[i] != " "):
		if(i != 0):
			if(argument[i-1].isnumeric()):
				irrelevant  = True
		if(irrelevant == False):
			if(i!= n - 1):
				if(argument[i+1].isnumeric()):
					if(argument[i+2].isnumeric()):
						push(int(argument[i] + argument[i+1] + argument[i+2]))
					else:	
						push(int(argument[i] + argument[i+1]))
				else:
					push(int(argument[i]))
			else:
				push(int(argument[i]))
print(stack[0])
		
		
 
