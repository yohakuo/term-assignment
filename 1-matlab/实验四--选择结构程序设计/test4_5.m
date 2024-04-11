a=rand(5,6)              %产生5x6的随机矩阵
n=input('请输入您要输出矩阵的第几行：');
if n>5
    disp('超出了矩阵的行数，矩阵的最后一行为：')
    a(5,:)
else
    disp(['矩阵的第',num2str(n),'行为：'])
    a(n,:)
end
