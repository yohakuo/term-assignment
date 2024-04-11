H=hilb(5);      %建立一个5*5希尔伯特矩阵
P=pascal(5);    %建立一个5*5帕斯卡矩阵
Hh=det(H);      %求行列式的值
Hp=det(P);
Th=cond(H);     %求条件数
Tp=cond(P);

%P的性能更好，条件数更接近1