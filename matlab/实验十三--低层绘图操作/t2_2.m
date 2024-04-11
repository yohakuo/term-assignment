t=-2:0.01:2;
x=t.^2;
y=5.*t.^3;
h1=line(t,x);
set(h1,'color','r','linestyle',':','linewidth',2)
text(-1.5,0,'x=t.^2')
hold on
h2=line(t,y);
set(h2,'color','b','linestyle',':','linewidth',3)
text(1.5,20,'y=5.*t.^3')
