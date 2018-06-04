clear all
close all
%1
nx1=-6:3;
nx2=4:10;
nx3=11:13;
nx=min((min(min(nx1),min(nx2))),min(nx3)):max((max(max(nx1),max(nx2))),max(nx3));
x=zeros(1,length(nx));
x1=10*cos(30*pi.*nx1);
x2=nx2+2;
x3=(nx3.^2);
x(find((nx>=min(nx1)) & (nx<=max(nx1))==1))=x1;
x(find((nx>=min(nx2)) & (nx<=max(nx2))==1))=x2;
x(find((nx>=min(nx3)) & (nx<=max(nx3))==1))=x3;
subplot(311)
stem(nx,x)%x(n)
%2
nh1=-5:3;
nh2=4:6;
nh=min(min(nh1),min(nh2)):max(max(nh1),max(nh2));
h1=ones(1,length(nh1));
h2=2*ones(1,length(nh2));
h(find((nh>=min(nh1)) & (nh<=max(nh1))==1))=h1;
h(find((nh>=min(nh2)) & (nh<=max(nh2))==1))=h2;
subplot(312)
stem(nh,h)%h(n)
%cross correlation
[hf,nhf]=sigfold(h,nh);
[r,l]=conv_m( x,nx,hf,nhf );
subplot(313)
stem(l,r)%r(l)