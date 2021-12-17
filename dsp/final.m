clc;
clear all;

%unit step sequence
N = 21;
x= ones(1,N);
n = 0:1:N-1;

hold on;
subplot(4,4,1);
stem(n,x);
title('unit step function');

%ramp sequence
 N=11;
 t=0:1:N-1;
 subplot(4,4,2);
 stem(t,t);
 title('remp sequence');
 
 %exponential sequence
 
 N=20;
 n=1:1:N-1;
 x=.8 .^ n;
 subplot(4,4,3);
 stem(n,x);
 title('exponential function');
 
 %sine wave
 %x=a*sin(2*pi*f*t)
 f=1;
 t=0:.01:pi;
 a=1;
 x=a*sin(2*pi*f*t+pi/4);
 subplot(4,4,4);
 plot(t,x);
 title('sine wave');
 
 %cosine wave
 t=0:.01:pi;
 x=cos(2*pi*t+pi/4);
 subplot(4,4,5);
 plot(t,x);
 title('cosine wave');
 
 %discrete signal
 %x(n)=a*sin(2*pi*(f/fs)*n) n pints;
 % x(t) = 10 sin (2pi 500t)
  
 a=10; N=500; 
 n=0:N-1;
 f=500; fs=50*f;
 y=a*sin(2*pi*(f/fs)*n);
 plot(n,y);
 subplot(4,4,6);
 title('discrete signal');
 




 
 
 
 
 
 