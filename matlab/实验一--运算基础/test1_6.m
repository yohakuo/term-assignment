a=[100:999];
num=a(rem(a,21)==0);
temp=find(num);
n=length(temp);

str = 'StrinG';
upperCaseIdx = find(isstrprop(str,'upper'));
str(upperCaseIdx) = [];