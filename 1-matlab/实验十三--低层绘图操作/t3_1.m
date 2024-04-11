t=-20*pi:0.1*pi:20*pi;
[t,~]=meshgrid(t);
x=t;
y=2.*t.*cos(t);
z=5.*t.*sin(t);
axes('view',[-37.5,30]);
surface(x,y,z)
axis equal
