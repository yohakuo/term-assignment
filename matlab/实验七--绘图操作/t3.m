t=0:pi/100:2*pi;
x=(2+cos(t/2)).*cos(t);
y=(2+cos(t/2)).*sin(t);
z=sin(t/2);
plot3(x,y,z)
