#
# Perl Reverse Polish Notation (RPN) Calculator
#
# Accepts an single argument in RPN, evaluates it and prints the answer to stdout.
#

#https://stackoverflow.com/questions/41950624/how-to-get-input-from-the-terminal-in-perl
#https://gist.github.com/ishu3101/00c296fcb04bb10f4c2d5fbff894b06a
#https://stackoverflow.com/questions/19100106/local-and-global-variables-in-perl`
#https://www.tutorialspoint.com/perl/perl_subroutines.htm
#https://www.geeksforgeeks.org/perl-eq-operator/
#https://stackoverflow.com/questions/10019049/what-does-do-in-perl

$input = $ARGV[0];
$n = length($input);
@stack = (0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
$nextt = 0;
$op2 = 0;
$push_val = 0;  

sub popper {
	$nextt--;
	return(@stack[$nextt]);
}

sub pusher {
	@stack[$nextt] = $push_val;
	$nextt = $nextt + 1;
}
		

for $i(0..$n-1){
	$irrelevant = 0;
	$c =  substr($input, $i, 1);
	if($c eq "+"){
		$push_val = popper() + popper();
		pusher();
	}
	elsif($c eq "-"){
		$op2 = popper();
		$push_val = (popper() - $op2);
		pusher();
	}
	elsif($c eq "*"){
		$push_val = (popper() * popper());
		pusher();
	}
	elsif($c eq "/"){
		$op2 = popper();
		$push_val = (popper() / $op2);
		pusher();
	}
	elsif($c eq "^"){
		$op2 = popper();
		$push_val = (popper() ** $op2);
		pusher();
	}
	elsif(!($c eq " ")){
		if($i != 0){
			if(substr($input, $i - 1, 1) eq "0" || substr($input, $i - 1, 1) eq "1" || substr($input, $i - 1, 1) eq "2" || substr($input, $i - 1, 1) eq "3" || substr($input, $i - 1, 1) eq "4" || substr($input, $i - 1, 1) eq "5" || substr($input, $i - 1, 1) eq "6" || substr($input, $i - 1, 1) eq "7" || substr($input, $i - 1, 1) eq "8" || substr($input, $i - 1, 1) eq "9"){
				$irrelevant = 1;
			}
		}
		if($irrelevant == 0){
			if($i != n - 1){
				if(substr($input, $i + 1, 1) eq "0" || substr($input, $i + 1, 1) eq "1" || substr($input, $i + 1, 1) eq "2" || substr($input, $i + 1, 1) eq "3" || substr($input, $i + 1, 1) eq "4" || substr($input, $i + 1, 1) eq "5" || substr($input, $i + 1, 1) eq "6" || substr($input, $i + 1, 1) eq "7" || substr($input, $i + 1, 1) eq "8" || substr($input, $i + 1, 1) eq "9"){
					if(substr($input, $i + 2, 1) eq "0" || substr($input, $i + 2, 1) eq "1" || substr($input, $i + 2, 1) eq "2" || substr($input, $i + 2, 1) eq "3" || substr($input, $i + 2, 1) eq "4" || substr($input, $i + 2, 1) eq "5" || substr($input, $i + 2, 1) eq "6" || substr($input, $i + 2, 1) eq "7" || substr($input, $i + 2, 1) eq "8" || substr($input, $i + 2, 1) eq "9"){

						$push_val = (int(substr($input, $i, 3)));
						pusher();
					}
					else{
						$push_val = (int(substr($input, $i, 2)));
						pusher();
					}
				}
				else{
					$push_val = (int($c));
					pusher();
				}	
			}
			else{
				$push_val = (int($c));
				pusher();
			}
		}
	}
}
print @stack[0];
