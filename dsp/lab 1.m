clear all;
close all;
fs=100;
bit=[0,1,0,1,0,1,1,0,0,0,1];
bit_duration=2;
volt=5;
T=size(bit,2)*bit_duration;
t=0:1/fs:T-1/fs;
ds=zeros(1,size(t,2));
for i=1:size(bit,2)
    for ii=1:bit_duration*fs
        if(bit(i)>0)
            ds(bit_duration*fs*(i-1)+ii)=volt;
        end
    end
end
%plot(t,ds);
frq_carrier=4;
a=5;
as1=a*sin(2*pi*frq_carrier*t);
as0=2*sin(2*pi*frq_carrier*t);
%ask=as1;
for i=1:1:size(ds,2)
    if ds(1,i)==5
        ask(1,i)=as1(1,i);
    else
       ask(1,i)=as0(1,i); 
    end

end

subplot(4,1,1);
plot(t,ds);
subplot(4,1,2);
plot(t,as1);
subplot(4,1,3);
plot(t,as0);
subplot(4,1,4);
plot(t,ask);

