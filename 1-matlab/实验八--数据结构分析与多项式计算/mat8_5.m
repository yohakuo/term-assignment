x=1:0.1:101;
y1=log10(x);
p=polyfit(x,y1,5)     %5次拟合多项式
y2=polyval(p,x);
plot(x,y1,':',x,y2,'-')
