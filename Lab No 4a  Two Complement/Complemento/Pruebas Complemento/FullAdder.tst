load FullAdder.hdl,
output-file FullAdder.out,
output-list Cin%B3.1.3
	    a%B3.1.3
	    b%B3.1.3
	    Cout%B3.1.3
	    sum%B3.1.3;

set Cin 0,
set a 0,
set b 0,
eval,
output;

set Cin 0,
set a 0,
set b 1,
eval,
output;

set Cin 0,
set a 1,
set b 0,
eval,
output;

set Cin 0,
set a 1,
set b 1,
eval,
output;

set Cin 1,
set a 0,
set b 0,
eval,
output;

set Cin 1,
set a 0,
set b 1,
eval,
output;

set Cin 1,
set a 1,
set b 0,
eval,
output;

set Cin 1,
set a 1,
set b 1,
eval,
output;