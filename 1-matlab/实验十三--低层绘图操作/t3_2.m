theta=0:0.01*pi:2*pi;
t=0:0.01*pi:2*pi;
[theta,t]=meshgrid(theta,t);
x=2.*cos(theta);
y=2.*sin(theta);
z=t;
axes('view',[-37.5,30]);
surface(x,y,z)
