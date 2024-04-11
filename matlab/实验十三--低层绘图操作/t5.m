t=linspace(0,2*pi,6);
k=t(1:length(t)-1);
patch(sin(k),cos(k),1:length(k),'facecolor','interp');
colormap summer;
axis equal;
