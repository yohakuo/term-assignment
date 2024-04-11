x=linspace(-2*pi,2*pi,100);
y1=x.^2;
y2=cos(2*x);
y3=y1.*y2;
plot(x,y1,'b-',x,y2,'r:',x,y3,'y--');
text(4,16,'\leftarrow y1=x^2');
text(6*pi/4,-1,'\downarrow y2=cos(2*x)');
text(-1.5*pi,-2.25*pi*pi,'\uparrow y3=y1*y2');
