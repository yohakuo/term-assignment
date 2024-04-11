function f=mat10_3_2(u)
x1=u(1);x2=u(2);
f=2*x1.^3+4*x1*x2.^3-10*x1.*x2+x2.^2;

%两个未知数x1，x2,求f在[O, 0]附近的最小值点和最小值。


%[U,fmin]=fminsearch(@mat10_3_2,[0,0])