
%mock taste:
 clc;
 clear all;
 a=10; N=500; 
 n=0:N-1;
 f=500; fs=20*f;
 y= a * sin( 2 * pi * (f/fs) *n );
 subplot(3,2,1);
 plot(n,y);
 title('discrete signal');
 
 % hamming window
 %make hamming window of n pints;
 N_temp=100;
 n_temp=0:N_temp-1;
 hw=.54 - .46* cos((2* pi * n_temp)/(N_temp-1));
 %hw_temp=[hw zeros(1,400)]
 hw_temp=[hw hw hw hw hw]
 subplot(3,2,2);
 plot(n,hw_temp)
 title('hamming window for 100 points');
 
 hwy= y .* hw_temp;
 subplot(3,2,3);
 plot(hwy);
 title('multiply with hamming window in 100 points sep');
 
 %rectangular window
 N_temp=100;
 rw=[zeros(1,200) ones(1,100) zeros(1,200)]
 %subplot(3,2,4);
 %plot(rw);
 %title('rectangular window n points');
 
 rwy= y .* rw;
 subplot(3,2,4);
 plot(rwy);
 title('multiply with rectangular window in 100 points sep');
 
 %triangular window
 N_temp=100;
 n_temp=0:N_temp-1;
 tw=1 - (abs(2*n_temp-N_temp+1)/(N_temp-1))
 tw_temp=[tw tw tw tw tw]
 subplot(3,2,5);
 plot(tw_temp);
 
 twy=y .* tw_temp;
 subplot(3,2,6);
 plot(twy);
 title('multiply with triangularangular window in 100 points sep')
 

 