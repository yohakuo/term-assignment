s=input('请输入一个成绩（0分到100分之间）：');  %s用于存放成绩
while 1                                         %判断输入成绩的合理性
    if s<0||s>100                               %去除无效值
        disp('输入的成绩需在0到100之间，请重新输入：')
        s=input('请输入一个成绩（0分到100分之间）：');
    else
        break;
    end
end
switch fix(s/10)                              %对成绩做出等级判断
    case {9,10}
        disp('A')
    case 8
        disp('B')
    case 7
        disp('C')
    case 6
        disp('D')
    otherwise
        disp('E')
end

