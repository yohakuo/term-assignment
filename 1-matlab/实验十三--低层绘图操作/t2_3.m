x=-2:0.01:2;
y=(1+x.^2)./(1+x.^4);
h=line(x,y);
set(h,'color','r','linestyle',':','linewidth',2)
text(1,1,'y=(1+x.^2)./(1+x.^4)')
