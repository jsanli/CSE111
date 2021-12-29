#
# Awk Reverse Polish Notation (RPN) Calculator
#
# Accepts an single argument in RPN, evaluates it and prints the answer to stdout.
#

#://unix.stackexchange.com/questions/475008/command-line-argument-in-awk
#://unix.stackexchange.com/questions/475008/command-line-argument-in-awk
#http://star-www.rl.ac.uk/docs/sc4.htx/sc4se11.html
#https://stackoverflow.com/questions/5808971/casting-to-int-in-awk

function pop(){
	nextt = nextt - 1
	return stack[nextt]
}

function push(operand){
	stack[nextt] = operand
	nextt = nextt + 1
}


BEGIN {
	argument = ARGV[1]
	n = length(argument)
	for (i = 0; i < 16; i++){
		stack[i] = 0.0
	}
	nextt = 0
	op2 = 0

	split(argument, a, sep)
	for (i = 1; i<n; i++){
		irrelevant = 0
		if(a[i] == "+"){
			push(pop() + pop());
		}
		else if(a[i] == "-"){
			op2 = pop()
			push(pop() - op2)
		}
		else if(a[i] == "*"){
			push(pop() * pop())
		}
		else if(a[i] == "/"){
			op2 = pop()
			push(pop() / op2)
		}
		else if(a[i] == "^"){
			op2 = pop()
			push(pop() ** op2)
		}
		else if(a[i] != " "){
			if(i != 0){
				if(a[i-1] == "0" || a[i-1] == "1" || a[i-1] == "2" || a[i-1] == "3" || a[i-1] == "4" || a[i-1] == "5" || a[i-1] == "6" || a[i-1] == "7" || a[i-1] == "8" || a[i-1] == "9"){
					irrelevant = 1
				}
			}
			if(irrelevant == 0){
				if(i != n-1){
					if(a[i+1] == "0" || a[i+1] == "1" || a[i+1] == "2" || a[i+1] == "3" || a[i+1] == "4" || a[i+1] == "5" || a[i+1] == "6" || a[i+1] == "7" || a[i+1] == "8" || a[i+1] == "9"){
						if(a[i+2] == "0" || a[i+2] == "1" || a[i+2] == "2" || a[i+2] == "3" || a[i+2] == "4" || a[i+2] == "5" || a[i+2] == "6" || a[i+2] == "7" || a[i+2] == "8" || a[i+2] == "9"){	
							push(a[i]a[i+1]a[i+2] + 0)
						}
						else{
							push(a[i]a[i+1] + 0)
						}
					}
					else{
						push(a[i] +0)
					}
				}
				else{
					push(a[i] + 0)
				}
			}

		}
	}
	print stack[0]
}
