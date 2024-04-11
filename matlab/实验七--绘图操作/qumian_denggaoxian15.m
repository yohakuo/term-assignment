x=linspace(-5,5,21);
y=linspace(0,10,31);
[x,y]=meshgrid(x,y);    %在[-5,5]*[0,10]的范围内生成网格坐标
z=cos(x).*cos(y).*exp(-sqrt(x.^2+y.^2)/4);
subplot(2,1,1);
surf(x,y,z);
subplot(2,1,2);
contour3(x,y,z,50);     %其中50为高度的等级数，越大越密
