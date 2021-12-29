#
# Bash Reverse Polish Notation (RPN) Calculator
#
# Accepts an single argument a RPN, evaluates it and prints the answer to stdout.
# 


#://devqa.io/create-call-bash-functions/
#://stackoverflow.com/questions/10551981/how-to-perform-a-for-loop-on-each-character-in-a-string-in-bash
variable=$1;
stack=(0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0);
next=0;
op=0.0;
n=0;
push_val=0.0;
ret_val=0.0;
iprev="";

pop(){
	next=$((next - 1));
	ret_val=stack[$next];
}

push(){
	stack[$next]=$push_val;
	next=$((next + 1));
}

for(( i=0; i<${#variable}; i++ )); do
#	echo "${variable:$i:1}"
	n=n+0;
done

while IFC='' read -r -d '' -n 1 i; do
	n=n+1;
#	printf "${variable}"
done < <(printf %s "$variable")

while read -n1 i; do
	irrelevant=0;
	if [[ "$i" == "+" ]]
	then
		pop;
		op=$ret_val;
		pop;
		push_val=($(($op + $ret_val)));
		push;
	elif [[ "$i" == "-" ]]
	then
		pop;
		op=$ret_val;
		pop;
		push_val=($(($ret_val - $op)));
		push;
	elif [[ "$i" == "*" ]]
	then
		pop;
		op=$ret_val;
		pop;
		push_val=($(($op * $ret_val)));
		push;
	elif [[ "$i" == "/" ]]
	then	
		pop;
		op_val=$ret_val;
		pop;
		push_val=($(($ret_val / $op_val)));
		push;
	elif [[ "$i" == "^" ]]
	then
		pop;
		op=$ret_val; 
		pop;
		push_val=($(($ret_val ** $op)));
		push;
	elif [[ "$i" == "0" ||  "$i" == "1" ||  "$i" == "2" ||  "$i" == "3" ||  "$i" == "4"  ||  "$i" == "5"  ||  "$i" == "6"  ||  "$i" == "7"  ||  "$i" == "8"  ||  "$i" == "9" ]]
	then
		iprev+="$i";
	else
		if [[ "$iprev" != "" ]]
		then
			push_val=$iprev;
			push;
		fi
		iprev="";  
	fi

		
		
	
done < <(echo -n "$variable")

printf "%s\n" "${stack[0]}"
 
