x=-2:0.01:2;
y=1/2.*log(x+sqrt(1+x.^2));
h=line(x,y);
set(h,'color','r','linestyle',':','linewidth',2)
text(1,exp(2),'y=1/2*log(x+sqrt(1+x^2))')
