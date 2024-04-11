id=input('请输入员工工号：');
h=input('该员工工作时数是：');
if h>120
x=(h-120)*84*(1+0.15)+120*84;
elseif h<60
x=h*84-700;
else
x=h*84;
end
disp([num2str(id),'号员工','的应发工资为',num2str(x)]);
