r=150;
a=150;
b=150;
para1=[a-r,b-r,2*r,2*r];
para2=[a-r+300,b-r,2*r,2*r]
rectangle('Position',para1,'Curvature',[1 1],'EdgeColor','r')
hold on 
rectangle('Position',para2,'Curvature',[1 1],'EdgeColor','r')
axis equal
