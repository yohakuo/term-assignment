x=-2:0.01:2;
y=x.^2.*exp(2*x);
h=line(x,y);
set(h,'color','r','linestyle',':','linewidth',2)
text(1,exp(2),'y=x^2*exp(2*x)')
