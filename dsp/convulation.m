clear all;
close all;
clc;

x= input("enter fist sequence :")
h= input("enter second sequence")

n1=length(x);
n2=length(h);

X=[x,zeros(1,n2)];
Y=[h,zeros(1,n1)];

for i=1 : n1+n2-1
  y(i)=0;
  for j =1:n1
    if(i-j+1>0)
      y(i)=y(i)+X(j) * Y(i-j+1)
     else
     end
  endfor
end
stem(y);
ylabel('y[n]');
xlabel('n');
tittle('convulation of two signal');
