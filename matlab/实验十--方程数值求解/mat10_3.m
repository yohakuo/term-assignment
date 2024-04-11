%f(x)=(x^3+cos(x)+x*log(x))/e^x在(0, 1) 内的最小值。


f=@(x) (x^3+cos(x)+x*log(x))/exp(x);
fminbnd(f,0,1)


