%利用ezsurf隐函数
ezsurf('cos(s)*cos(t)','cos(s)*sin(t)','sin(s)',[0,0.5*pi,0,1.5*pi]);
%进行插值着色处理
shading interp  
