a=input('请输入正数a：');
b=input('请输入正数b：');
Xn=1;
Xn1=a/(b+Xn);
n=0;
while abs(Xn1-Xn)>1e-5      %|Xn1-Xn|>1e-5 
    Xn=Xn1;
    Xn1=a/(b+Xn);
    n=n+1;
    if n==500
        break;
    end
end
n
Xn1
r1=(-b+sqrt(b*b+4*a))/2
r2=(-b-sqrt(b*b+4*a))/2
