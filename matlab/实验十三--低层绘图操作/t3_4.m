y=0:0.01:20;
x=0:0.01:20;
[x,y]=meshgrid(x,y);
z=y.^3;
axes('view',[-37.5,30]);
h=surface(x,y,z);
