function F=mat10_2_2(X)
x=X(1);         %三个不同解
y=X(2);
z=X(3);
F(1)=sin(x)+y^2+log(z)-7;
F(2)=3*x+2^y-z^3+1;
F(3)=x+y+z-5;

%初值都为1
%X=fsolve(@mat10_2_2,[1,1,1],optimset('Display', 'off'))
