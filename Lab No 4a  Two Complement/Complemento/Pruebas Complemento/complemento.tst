load complemento.hdl,
output-file complemento.out,
output-list ah%B1.15.1 al%B1.15.1 sh%B1.15.1 sl%B1.15.1;

set ah %B000000000000000,
set al %B000000000000000,
eval,
output;

set ah %B000000000000000,
set al %B111111111111111,
eval,
output;

set ah %B111111111111111,
set al %B000000000000000,
eval,
output;

set ah %B000000000000001,
set al %B111111111111111,
eval,
output;

set ah %B111111111111110,
set al %B000000000000000,
eval,
output;

set ah %B111111111111111,
set al %B111111111111111,
eval,
output;

set ah %B010101010101010,
set al %B101010101010101,
eval,
output;

set ah %B101010101010101,
set al %B010101010101010,
eval,
output;

set ah %B110111011101110,
set al %B101011011011010,
eval,
output;

set ah %B101011011011010,
set al %B110111011101110,
eval,
output;