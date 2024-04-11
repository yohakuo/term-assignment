E=eye(3);       %求单位矩阵
R=rand(3,2);    %随机矩阵
O=zeros(2,3);   %零矩阵
S=diag([1,2]);  %对角阵
A=[E R;O S];    
Z1=A*A
Z2=[E R+R*S ; O S*S]