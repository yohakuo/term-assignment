temp=exp(2);z1=(2*sin(85/180*pi))/(1+temp);

x=12;y=1e-5;
z2=pi/(x+y);

x=[2 1+2*i;-0.45,5];
z3=0.5*log(x+sqrt(1+x^2));

a=[-3.0:0.1:3.0];
z4=(exp(0.3.*a)-exp(-0.3.*a))/2.*sin(a+0.3)+log((0.3+a)/2);
