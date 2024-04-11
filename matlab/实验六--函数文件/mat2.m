function [a,b,N,M]=mat2(m,n,t)
A=[m*cos(t*pi/180),-m,-sin(t*pi/180),0;m*sin(t*pi/180),0,cos(t*pi/180),0;
    0,n,-sin(t*pi/180),0;0,0,-cos(t*pi/180),1];
B=[0,9.8*m,0,9.8*n];
C=inv(A)*B';
a=C(1);
b=C(2);
N=C(3);
M=C(4);



%在命令窗口调用该函数文件:
%m1=input('m1=');
%m2=input('m2=');
%theta=input('theta=');
%[a1,a2,N1,N2]=mat2(m1,m2,theta)
