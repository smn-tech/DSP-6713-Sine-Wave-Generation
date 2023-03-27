#include "DSK6713_AIC23.h" 
Uint32 fs=DSK6713_AIC23_FREQ_8KHZ; 
#define LOOPLENGTH 8 
short sine_table[LOOPLENGTH]={0,7071,10000,7071,0,
                                  -7071,-10000,-7071};
short loopindex = 0; 
interrupt void c_int11(){
output_left_sample(sine_table[loopindex]); 
if (++loopindex >= LOOPLENGTH)
    loopindex = 0;
return; 
}

void main(){
comm_intr(); 
while(1); 
}
