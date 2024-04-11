a=fix(10+(99-10)*rand(1,2))                    %产生两个随机整数
x=a(1);
y=a(2);
t=input('请输入运算符号：','s');
if t=='+'
    z=x+y;
elseif t=='-'
    z=x-y;
elseif t=='*'
    z=x*y;
elseif t=='/'
    z=x/y;
end
disp([num2str(x),t,num2str(y),'=',num2str(z)])   %输出运算结果
