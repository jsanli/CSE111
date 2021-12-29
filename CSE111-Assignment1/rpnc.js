/*
 * Node.js / JavaScript Reverse Polish Notation (RPN) Calculator
 *
 * Accepts an single argument in RPN, evaluates it and prints the answer to stdout.
 * 
 */

//nodejs.org/en/knowledge/command-line/how-to-parse-command-line-arguments
//https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/function
//www.w3schools.com/jsref/jsref_length_string.asp
//https://www.w3schools.com/jsref/jsref_string.asp
//https://stackoverflow.com/questions/3586775/what-is-the-correct-way-to-check-for-string-equality-in-javascript
//stackoverflow.com/questions/8935632/check-if-character-is-number/
//https://www.w3schools.com/jsref/jsref_concat_string.asp



let argument = String(process.argv.slice(2));
let n = argument.length; 
let stack = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]; 
let next = 0;
let op2 = 0.0;

function pop(){
	return stack[--next];
}

function push(operand){
	stack[next++] = operand;
}

for(let i = 0; i < n; i++){
	let irrelevant = false;
	if(argument[i] === '+'){
		push(pop()+pop());
	}
	else if(argument[i] === '-'){
		op2 = pop();
		push(pop()-op2);
	} 
	else if(argument[i] === '*'){
		push(pop()*pop());
	} 
	else if(argument[i] === '/'){
		op2 = pop();
		push(pop()/op2);
	} 
	else if(argument[i] === '^'){
		op2 = pop();
		push(Math.pow(pop(), op2));
	}
	else if(!(argument[i] === ' ')){
		if(i != 0){
			if(argument[i-1] >= '0' && argument[i-1] <= '9'){
				irrelevant = true;
			}
		}
		if(irrelevant == false){
			if(i != n - 1){
				if(argument[i+1] >= '0' && argument[i+1] <= '9'){
					if(argument[i+2] >= '0' && argument[i+2] <= '9'){
						push(parseInt(argument[i].concat(argument[i+1]).concat([i+2])));
					}
					else{
						push(parseInt(argument[i].concat(argument[i+1])));
					}
				}
				else{
					push(parseInt(argument[i]));
				}
			}
			else{
				push(parseInt(argument[i]));
			}
		}
	} 
}

console.log(stack[0]);
	

	
