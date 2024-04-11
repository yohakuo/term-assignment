x=-5:0.01:5;
y=[];   %起始设y为空向量
for x0=x
if x0<=0  %不能写成x0=<0
y=[y,(x0+sqrt(pi))/exp(2)];    %将x对应的函数值放到y中
else
y=[y,0.5*log(x0+sqrt(1+x0^2))];
end
end
plot(x,y)
