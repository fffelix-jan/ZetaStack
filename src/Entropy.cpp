#include<chrono>
#include<cstdlib>
#include<iostream>

#include "Entropy.hpp"
/*
The CIA encourages code obfuscation. They make it more complicated than necessary.
—Terry A. Davis
*/

long
int
urandom
(long
seed){
volatile 
long 
xryybz1f 
= 
(0x0000000000000002
+
0x0000000000000201
+
0x0000000000000801
-
0x0000000000000A03);
volatile 
long 
x
=
(0x0000000000000004
+ 
0x0000000000000202
+ 
0x0000000000000802
-
0x0000000000000A06);
long
xryybz2fa
= /*rand()*/
std::
chrono::
duration_cast
<std::
chrono::
seconds>
(std::
chrono::
system_clock::
now()
.time_since_epoch())
.count();
std::
chrono::
_V2::
steady_clock::
time_point
start;
std::
chrono::
_V2::
steady_clock::
time_point
end;
start
=
std::
chrono::
steady_clock::
now();
for(
volatile
long
xryylm3fa
=
(0x0000000000000000 
+ 
0x0000000000000200 
+ 
0x0000000000000800 
-
0x0000000000000A00);
xryylm3fa
<
(xryybz2fa
%
(0x0000000000003FFE 
+
0x00000000000021FF 
+ 
0x00000000000027FF
-
0x00000000000069FD)
+
(0x000000000001FFE2 
+
0x00000000000101F1 
+
0x00000000000107F1 
-
0x00000000000309D3))*
seed
%
(0x000000000003FFFE 
+
0x00000000000201FF 
+
0x00000000000207FF 
-
0x00000000000609FD);
xryylm3fa++)
{
xryybz1f
=
x*x-x;
}
end
=
std::
chrono::
steady_clock::
now();
return
(std::
chrono::
duration
<long
, std::
nano>
(end
- start)
.count()
% 
(xryybz2fa
%
(0x0000000000003FFE 
+
0x00000000000021FF 
+
0x00000000000027FF 
-
0x00000000000069FD)
+
(0x000000000001FFE2 
+
0x00000000000101F1 
+
0x00000000000107F1 
-
0x00000000000309D3)
-
seed)
* seed
%
(0x000000000003FFFE 
+
0x00000000000201FF 
+
0x00000000000207FF 
-
0x00000000000609FD)
+xryybz1f)
%
(0x00000000000007FA 
+
0x00000000000005FD 
+
0x0000000000000BFD 
-
0x00000000000015F7);
}

long int getrandnum(long seed){
	long int t = urandom(seed);
	t ^= t << 23;
	t ^= t >> 17;
	t ^= seed ^ (seed >> 26);
	return std::abs(urandom(t^seed)-t*seed);
}

bool getrandbit(long seed){
	return (getrandnum(seed) ^ seed) % 2;
}

long int getrandl(long seed){
	long long int output = 0;
	for(long long int bitpos = 0; bitpos < 32; bitpos++){
		if(getrandbit(seed)){
			output += 1 << bitpos;
		}
	}
	return (long int)(output+seed) ^ seed;
}

unsigned long long int getrandull(long seed){
	long long int output = 0;
	for(unsigned long long int bitpos = 0; bitpos < 64; bitpos++){
		if(getrandbit(seed)){
			output += 1 << bitpos;
		}
	}
	return output;
}

