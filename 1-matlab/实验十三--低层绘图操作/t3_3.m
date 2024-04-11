t=0:0.00001:0.001;
[t,x]=meshgrid(t);
v=10*exp(-0.01*x).*sin(2000*pi*t-0.2*x+pi);
axes('view',[-37.5,30]);
h=surface(t,x,v);
title('v=10*exp(-0.01*x).*sin(2000*pi*t-0.2*x+pi)');
xlabel('t'),ylabel('x'),zlabel('v')
